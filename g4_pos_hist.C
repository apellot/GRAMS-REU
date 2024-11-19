void g4_pos_hist() {
  // Open the first file and its tree.
  auto myFile = TFile::Open("gramsdetsimpl.root");
  auto tree = myFile->Get<TTree>("DetSim");

  // Declare that the gramsg4 tree is a friend to the DetSim tree.
  tree->AddFriend("gramsg4","gramsg4pl.root");
  tree->AddFriend("ReadoutSim", "gramsreadoutsimpl.root");

  // Define the TTreeReader for this combined tree.
  auto reader = new TTreeReader(tree);
  //bin size should be the same as the amount of wire strips for the readout  
  TH3D* hist = new TH3D("hist", "", 150, -15,15,150,-15,15,250,0,125);
  //TCanvas* canvas = new TCanvas("canvas", "Histograms", 800, 800);

  //read in the different classes that you need information from
  TTreeReaderValue<grams::EventID>   EventID  (*reader, "DetSim.EventID");
  TTreeReaderValue<grams::ElectronClusters> clusters(*reader, "ElectronClusters");
  TTreeReaderValue<grams::ReadoutMap> readout(*reader, "ReadoutMap");

  TTreeReaderValue<grams::MCTrackList> track(*reader, "TrackList");
  TTreeReaderValue<grams::MCLArHits> track_lar(*reader, "LArHits");
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
  std::vector<double> xStart, yStart, zStart, xEnd, yEnd, zEnd, tStart, tEnd;

    while (reader->Next()) {
        // Check if the current event matches the specified event
        if (*EventID == event) {
            // Get the number of clusters in the current event
            auto numClusters = clusters->size();

            // Iterate over all clusters and get the start position
            for (const auto& [key, lar] : *track_lar) {
            auto start = lar.Start4D();
            auto end = lar.End4D(); // Assuming you have an end position method

            xStart.push_back(start.X());
            yStart.push_back(start.Y());
            zStart.push_back(start.Z());
	    tStart.push_back(start.T());

            xEnd.push_back(end.X());
            yEnd.push_back(end.Y());
            zEnd.push_back(end.Z());
            tEnd.push_back(end.T());	    
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
		auto pos = readoutCluster.PositionAtAnode4D();
                e_val.push_back(energy_at_anode);
		time.push_back(pos.T());
		x.push_back(pos.X());
                y.push_back(pos.Y());
                z.push_back(pos.Z());
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
     // Create a TGraph2D to plot the 3D lines
    TGraph2D *graph = new TGraph2D();

    TCanvas *c1 = new TCanvas("c1", "3D Line Plot", 800, 600);
    c1->SetGrid();    

    // Add lines to the TGraph2D
    int nPoints = xStart.size();
    for (int i = 0; i < nPoints; ++i) {
        graph->SetPoint(i,xStart[i], yStart[i], zStart[i]);
        graph->SetPoint(i,xEnd[i], yEnd[i], zEnd[i]);
    }

    // Draw the graph
    c1->cd();
    graph->SetTitle("G4 Event Visualization for Event 9;X Pos (cm);Y Pos (cm);Z Pos (cm)");
    // Customize the line style
    // Customize marker style
    graph->SetMarkerStyle(20); // Filled circle
    graph->SetMarkerColor(kRed); // Red color
    graph->SetMarkerSize(0.5); // Marker size 
    graph->Draw("p");

    // Save the canvas as an image
    c1->SaveAs("3DLinePlot.png");

    // Clean up
    //delete c1;
    //delete graph; 

}
