void gramsHist() {
  // Open the first file and its tree.
  auto myFile = TFile::Open("gramsdetsimpl.root");
  auto tree = myFile->Get<TTree>("DetSim");

  // Declare that the gramsg4 tree is a friend to the DetSim tree.
  tree->AddFriend("gramsg4","gramsg4pl.root");
  tree->AddFriend("ReadoutSim", "gramsreadoutsimpl.root");

  // Define the TTreeReader for this combined tree.
  auto reader = new TTreeReader(tree);
  //bin size should be the same as the amount of wire strips for the readout  
  TH3D* hist = new TH3D("hist", "", 150, -15,15,150,-15,15,250,0,125000);
  TCanvas* canvas = new TCanvas("canvas", "Histograms", 800, 800);

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
    for (size_t i = 0; i < x.size(); i++) {
        std::cout << x.at(i) << " " << y.at(i) << " " << z.at(i) << " " << time.at(i) << " entry: " << i << std::endl;
    }

    //sanity check to make sure everything is the same size before plotting
    std::cout << x.size() << time.size() << y.size() << z.size() << e_val.size() <<  std::endl;

    // Ensure all vectors have the same size
    if (x.size() != y.size() || y.size() != z.size() || z.size() != time.size() || time.size() != e_val.size()) {
        std::cerr << "Vector sizes are not consistent!" << std::endl;
        return;  // Exit the function
    }

    for (size_t i = 0; i < x.size(); i++) {
        hist->Fill(x.at(i), y.at(i), time.at(i), e_val.at(i));
        std::cout << x.at(i) << " " << y.at(i) << " " << z.at(i) << " " << time.at(i) << " energy: " << e_val.at(i) << " entry: " << i << std::endl;
    }

    //convert the energy of the gamma ray and event number to a string so it can be labelled 
    double e_prim = energy[0];
    double evt_str = evt[0];
    std::stringstream ss;
    ss << e_prim;
    std::stringstream sx;
    sx << evt_str;
    std :: string event_string = sx.str(); 
    std::string energy_str = ss.str();;

    // Create the label text
    std::string label ="Event: "+ event_string +  " energy of incoming gamma ray " + energy_str + " MeV";

    canvas->cd();
    hist->SetStats(kFALSE);
    hist->SetLineColor(kGray);  // Set the color of the box edges
    hist->SetFillColor(kGray);    
    hist->GetXaxis()->SetTitle("x position (cm)");
    hist->GetYaxis()->SetTitle("y position (cm)");
    hist->GetZaxis()->SetTitle("time at anode (ns)");
    hist->Draw("lego2z");
    TText *t = new TText(.15,.95,label.c_str());
    t->SetTextAlign(22);
    t->SetTextColor(kPink-5);
    t->SetTextFont(43);
    t->SetTextSize(20);
    t->Draw();
    canvas->Update();
  

}
