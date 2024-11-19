void g_e() {
  // Open the first file and its tree.
  auto myFile = TFile::Open("gramsdetsimpl.root");
  auto tree = myFile->Get<TTree>("DetSim");

  // Declare that the gramsg4 tree is a friend to the DetSim tree.
  tree->AddFriend("gramsg4","gramsg4pl.root");
  tree->AddFriend("ReadoutSim", "gramsreadoutsimpl.root");

  // Define the TTreeReader for this combined tree.
  auto reader = new TTreeReader(tree);
  //bin size should be the same as the amount of wire strips for the readout  
  //TH1D* hist = new TH1D("hist", "hist",143,0,50);
  TCanvas* canvas = new TCanvas("canvas", "hist", 800, 800);

  //read in the different classes that you need information from
  TTreeReaderValue<grams::EventID>   EventID  (*reader, "DetSim.EventID");
  TTreeReaderValue<grams::ElectronClusters> clusters(*reader, "ElectronClusters");
  TTreeReaderValue<grams::ReadoutMap> readout(*reader, "ReadoutMap");

  TTreeReaderValue<grams::MCTrackList> track(*reader, "TrackList");

  std::vector<double> time;
  std::vector<double> energy;
  std::vector<double> e_val;
  std::vector<double> evt;
  std::vector<int> evt_clus;

    while (reader->Next()) {
        // Check if the current event matches the specified event
            // Get the number of clusters in the current event
            auto numClusters = clusters->size();

            // Vector to save track IDs of primary particles
            std::vector<int> primaries;

            // Iterate over tracks and filter primary particles
            for (const auto& [trackID, t] : *track) {
                if (t.Process() == "Primary") {
                    // Save the ID of this track
                    primaries.push_back(trackID);

                    auto trajectory = t.Trajectory();
                    if (!trajectory.empty() && trajectory[0].E() < 50 && trajectory[0].E() >10) {
                        auto e = trajectory[0].E();
                        energy.push_back(e);
			//time.push_back(trajectory[0].T());
			evt.push_back(EventID->Index());

                    }
                }
            }

        // Check if the current event is in the evt_clus vector
        if (std::find(evt.begin(), evt.end(), EventID->Index()) != evt.end()) {
            // Iterate over all clusters and get the start position
            for (const auto& [key, cluster] : *clusters) {
                auto start = cluster.PositionAtAnode4D();
                //std::cout << "Event " << EventID->Index() << std::endl;

                // Extract the four elements
                time.push_back(start.T());
                evt_clus.push_back(EventID->Index());
            }

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
        }
    }	    

         
  for(size_t i =0; i < energy.size(); i++) {
     std::cout << "entry: " << i << " " << energy.at(i) << " Event: " << evt.at(i) << std::endl;
  }

  std::vector<int> event;
  // Print the events with energy less than the threshold
  for (size_t i = 0; i < energy.size(); i++) {
      if (energy.at(i) < 10) {
          std::cout << "Event: " << evt.at(i)
                    << " energy: " << energy.at(i) << std::endl;
	  event.push_back(evt.at(i));
      }
  }

  // Print the events vector
  //std::cout << "Events with energy less than 10:" << std::endl;
  for (const auto& e : event) {
      //std::cout << e << std::endl;
  }

  for(size_t i =0; i < event.size(); i++) {
    if(event == evt_clus) {
      //std::cout << "Event: " << event.at(i) << std::endl;
  }
  }

  // Determine the minimum and maximum time values from your data
  Double_t tmin = 10;
  Double_t tmax = 50;

  // Define the number of bins and calculate the bin edges based on time range
  Int_t nbins = 10; // Adjust as needed
      // Calculate number of bins
  Double_t *ebins = new Double_t[nbins + 1];
  for (Int_t i = 0; i <= nbins; ++i) {
      ebins[i] = TMath::Power(10, TMath::Log10(tmin) + (TMath::Log10(tmax) - TMath::Log10(tmin)) / nbins * i);
  }


  // Create the histogram with time on the x-axis and logarithmically spaced bins
  TH1D *hist = new TH1D("hist", "Initial Energy", nbins, ebins);

  // Optionally set labels and titles
  hist->GetXaxis()->SetTitle("Initial Gamma-ray energy (MeV)");
  hist->GetYaxis()->SetTitle("Counts");

  // Fill histogram with your actual time data
  for (size_t i = 0; i < energy.size(); ++i) {
      hist->Fill(energy[i]);
  }

  canvas->cd();
  hist->Draw();

}
