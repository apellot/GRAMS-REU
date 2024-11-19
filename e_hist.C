void e_hist() {
  // Open the first file and its tree.
  auto myFile = TFile::Open("gramsdetsimpl.root");
  auto tree = myFile->Get<TTree>("DetSim");

  // Declare that the gramsg4 tree is a friend to the DetSim tree.
  tree->AddFriend("gramsg4","gramsg4pl.root");
  tree->AddFriend("ReadoutSim", "gramsreadoutsimpl.root");

  // Define the TTreeReader for this combined tree.
  auto reader = new TTreeReader(tree);
  //bin size should be the same as the amount of wire strips for the readout  
  TH3D* h3 = new TH3D("hist", "", 150, -15,15,150,-15,15,250,0,125000);
  //TCanvas* canvas = new TCanvas("canvas", "Histograms", 800, 800);

  //read in the different classes that you need information from
  TTreeReaderValue<grams::EventID>   EventID  (*reader, "DetSim.EventID");
  TTreeReaderValue<grams::ElectronClusters> clusters(*reader, "ElectronClusters");
  TTreeReaderValue<grams::ReadoutMap> readout(*reader, "ReadoutMap");

  TTreeReaderValue<grams::MCTrackList> track(*reader, "TrackList");


  std::vector<double> x;
  std::vector<double> y;
  std::vector<double> z;
  std::vector<double> time;
  std::vector<double> energy;
  std::vector<double> e_val;
  std::vector<double> evt;
  gStyle->SetPalette(kCandy);

  // Define the specific event we're interested in
  static const auto event = grams::EventID(0, 9);

    while (reader->Next()) {
        // Check if the current event matches the specified event
        if (*EventID == event) {
            // Get the number of clusters in the current event
            auto numClusters = clusters->size();

            // Iterate over all clusters and get the start position
            for (const auto& [key, cluster] : *clusters) {
                auto start = cluster.PositionAtAnode4D();
                //std::cout << "Event " << EventID->Index()
                          //<< " has " << numClusters << " clusters, "
                          //<< "start pos: (" << start.X() << ", " << start.Y() << ", " << start.Z() << ", " << start.T() << ")" << std::endl;

                // Extract the four elements
                x.push_back(start.X());
                y.push_back(start.Y());
                z.push_back(start.Z());
                time.push_back(start.T());
                //e_val.push_back(cluster.EnergyAtAnode());
                evt.push_back(EventID->Index());
            }

                    // Access ReadoutMap to get cluster keys to get the energy values
        for (const auto& [readoutID, clusterKeys] : *readout) {
            for (const auto& clusterKey : clusterKeys) {
                auto result = clusters->find(clusterKey);
                if (result == clusters->end()) {
                    std::cerr << "Inconsist readout->electron cluster map" << std::endl;
                    exit(EXIT_FAILURE);
                }
                auto& readoutCluster = result->second;

                // Assuming readoutCluster provides EnergyAtAnode method
                double energy_at_anode = readoutCluster.EnergyAtAnode();
                e_val.push_back(energy_at_anode);
            }
        }

            // Vector to save track IDs of primary particles
            std::vector<int> primaries;

            // Iterate over tracks and filter primary particles
            for (const auto& [trackID, t] : *track) {
                if (t.Process() == "Primary") {
                    // Save the ID of this track
                    primaries.push_back(trackID);

                    auto trajectory = t.Trajectory();
                    if (!trajectory.empty()) {
                        auto e = trajectory[0].E();
                        energy.push_back(e);

                    }
                }
            }
        }
    }
    int nPoints = x.size();
    // Create a canvas
    TCanvas *c1 = new TCanvas("c1", "3D Scatter Plot with Energy Scale", 800, 600);

    // Create a 3D scatter plot (TPolyMarker3D)
    TPolyMarker3D *marker = new TPolyMarker3D(nPoints);
    
    // Set the marker size and color based on energy values
    for (int i = 0; i < nPoints; ++i) {
        int colorIndex = (energy[i] / *std::max_element(energy.begin(), energy.end())) * 255;  // Scale energy to 0-255 range
        marker->SetPoint(i, x[i], y[i], z[i]);
        marker->SetMarkerColor(gROOT->GetColor(255 - colorIndex, colorIndex, 0));  // Green to red gradient
        marker->SetMarkerStyle(20);  // Set marker style (adjust as needed)
        marker->SetMarkerSize(1.5);   //	    
    }

    // Set marker attributes
    marker->SetMarkerColor(kBlue);  // Default marker color
    marker->SetMarkerSize(1.5);     // Default marker size

    // Draw the 3D scatter plot
    marker->Draw();

    // Update the canvas to display the scatter plot
    c1->Update();

}
