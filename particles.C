void particles() {
  // Open the first file and its tree.
  auto myFile = TFile::Open("gramsdetsimpl.root");
  auto tree = myFile->Get<TTree>("DetSim");

  // Declare that the gramsg4 tree is a friend to the DetSim tree.
  tree->AddFriend("gramsg4","gramsg4pl.root");
  tree->AddFriend("gramsg4elec","gramsg4elec.root");
  tree->AddFriend("gramsg4pos","gramsg4pos.root");
  tree->AddFriend("gramsg4proton","gramsg4proton.root");
  tree->AddFriend("gramsg4alpha","gramsg4alpha.root");
  tree->AddFriend("ReadoutSim", "gramsreadoutsimpl.root");
  tree->AddFriend("ReadoutSimelec", "gramsreadoutsimelec.root");
  tree->AddFriend("ReadoutSimpos", "gramsreadoutsimpos.root");
  tree->AddFriend("ReadoutSimproton", "gramsreadoutsimproton.root");
  tree->AddFriend("ReadoutSimalpha", "gramsreadoutsimalpha.root");
  tree->AddFriend("DetSimelec", "gramsdetsimelec.root");
  tree->AddFriend("DetSimpos", "gramsdetsimpos.root");
  tree->AddFriend("DetSimproton", "gramsdetsimproton.root");
  tree->AddFriend("DetSimalpha", "gramsdetsimalpha.root");

  // Define the TTreeReader for this combined tree.
  auto reader = new TTreeReader(tree);
  //bin size should be the same as the amount of wire strips for the readout  
  TH1D* hist = new TH1D("hist", "Averaged Hits",250,0,125000/1000);
  TH1D* hist2 = new TH1D("hist2", "G4 energy/readout Energy",50,0,25);
  //TH1D* hist3 = new TH1D("hist3", "Normalized Time Counts",250,0,125000/1000);
  //TH1D* hist4 = new TH1D("hist4", "Normalized Time Counts",250,0,125000/1000);
  //TH1D* hist5 = new TH1D("hist5", "Normalized Time Counts",250,0,125000/1000);
  TCanvas* canvas = new TCanvas("canvas","hist",800,800);

  //read in the different classes that you need information from
  TTreeReaderValue<grams::EventID>   EventID  (*reader, "DetSim.EventID");
  TTreeReaderValue<grams::EventID>   EventID_g4  (*reader, "gramsg4.EventID");
  TTreeReaderValue<grams::EventID>   EventID_pos  (*reader, "DetSimpos.EventID");
  TTreeReaderValue<grams::EventID>   EventID_e  (*reader, "DetSimelec.EventID");
  TTreeReaderValue<grams::EventID>   EventID_proton  (*reader, "DetSimproton.EventID");
  TTreeReaderValue<grams::EventID>   EventID_alpha  (*reader, "DetSimalpha.EventID");
  TTreeReaderValue<grams::ElectronClusters> clusters(*reader, "ElectronClusters");
  TTreeReaderValue<grams::ElectronClusters> clusters_e(*reader, "DetSimelec.ElectronClusters");
  TTreeReaderValue<grams::ElectronClusters> clusters_pos(*reader, "DetSimpos.ElectronClusters");
  TTreeReaderValue<grams::ElectronClusters> clusters_proton(*reader, "DetSimproton.ElectronClusters");
  TTreeReaderValue<grams::ElectronClusters> clusters_alpha(*reader, "DetSimalpha.ElectronClusters");
  TTreeReaderValue<grams::ReadoutMap> readout(*reader, "ReadoutMap");
  TTreeReaderValue<grams::ReadoutMap> readout_e(*reader, "ReadoutSimelec.ReadoutMap");
  TTreeReaderValue<grams::ReadoutMap> readout_pos(*reader, "ReadoutSimpos.ReadoutMap");
  TTreeReaderValue<grams::ReadoutMap> readout_proton(*reader, "ReadoutSimproton.ReadoutMap");
  TTreeReaderValue<grams::ReadoutMap> readout_alpha(*reader, "ReadoutSimalpha.ReadoutMap");

  TTreeReaderValue<grams::MCTrackList> track(*reader, "gramsg4.TrackList");
  TTreeReaderValue<grams::MCTrackList> track_e(*reader, "gramsg4elec.TrackList");
  TTreeReaderValue<grams::MCTrackList> track_pos(*reader, "gramsg4pos.TrackList");
  TTreeReaderValue<grams::MCTrackList> track_proton(*reader, "gramsg4proton.TrackList");
  TTreeReaderValue<grams::MCTrackList> track_alpha(*reader, "gramsg4alpha.TrackList");
  TTreeReaderValue<grams::MCLArHits> track_lar(*reader, "LArHits");

  std::vector<double> time;
  std::vector<double> energy;
  std::vector<double> e_val;
  std::vector<int> evt;
  std::vector<int> evt_clus;
  Int_t num_evt = 0;
  std::vector<double> evt1;
  std::vector<double> evt2;
  std::vector<double> evt3;
  std::vector<double> evt4;
  Int_t num_evt1 = 0;
  Int_t num_evt2 = 0;
  Int_t num_evt3 = 0;
  Int_t num_evt4 = 0;
  std::vector<double> time1;
  std::vector<double> time2;
  std::vector<double> time3;
  std::vector<double> time4;
  std::vector<double> energy1;
  std::vector<double> energy2;
  std::vector<double> energy3;
  std::vector<double> energy4;
  std::vector<double> num_clus1;
  std::vector<double> num_clus2;
  std::vector<double> num_clus3;
  std::vector<double> num_clus4;
  std::vector<double> num_clus5;
  static const auto event = grams::EventID(0, 9);
  std::vector<double> e_g4;
  std::vector<double> elec;
  std::vector<int> g4_hit;
  std::vector<int> read_hit;

    while (reader->Next()) {
	  //if(*EventID == event) {

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
			//time.push_back(trajectory[0].T());
			evt.push_back(EventID->Index());
			num_evt++;
			//std::cout << EventID->Index()  << std::endl;

                    }
                }
            }

	    for (const auto& [TrackID, t] : *track) {
                auto traj = t.Trajectory();
                for (const auto& point : traj) {
                    auto e = point.E();
                    //e_g4.push_back(e);
                }
            }

            for(const auto& [TrackID, t]: *track_lar) {
	       //auto e = t.E();
	       auto hit = t.HitID();
	       //e_g4.push_back(e);
	       g4_hit.push_back(hit);

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
		e_val.push_back(cluster.EnergyAtAnode());
            }
	}

        for (const auto& [ClusterKeys, clusterKeys] : *readout) {
            for (const auto& clusterKey : clusterKeys) {
                auto result = clusters->find(clusterKey);
                if (result == clusters->end()) {
                    std::cerr << "Inconsist readout->electron cluster map" << std::endl;
                    exit(EXIT_FAILURE);
                }
                auto& readoutCluster = result->second;

                // Assuming readoutCluster provides EnergyAtAnode method
                double energy_at_anode = readoutCluster.EnergyAtAnode();
		auto time_A = readoutCluster.PositionAtAnode4D();
		auto electrons = readoutCluster.NumElectrons();
		auto hit = readoutCluster.HitID();
                //e_val.push_back(energy_at_anode);
		time.push_back(time_A.T());
		num_clus1.push_back(electrons);
		read_hit.push_back(hit);
            }
        }

        for (const auto& [TrackID, track] : *track_lar) {
            // Check if any element in read_hit is in g4_hit
            bool found_in_g4 = std::any_of(read_hit.begin(), read_hit.end(),
                                           [&g4_hit](int hit) {
                                               return std::find(g4_hit.begin(), g4_hit.end(), hit) != g4_hit.end();
                                           });

            if (found_in_g4) {
               auto e = track.E();
               e_g4.push_back(e);
                }
            }
	//}

    }

  double e_tot = 0;
  double num_elec = 0;
  double e_r = 0;
  std::vector<double> div;
  std::vector<double> evnt;  

  for(size_t i =0; i <e_g4.size(); i++){
      e_tot += e_g4.at(i);
      //std::cout <<  i  << " Event: " << evt.at(i) <<  std::endl;
  }

  for(size_t i =0; i <num_clus1.size(); i++){
      num_elec += num_clus1[i];
      //std::cout <<  i  << " num electrons: " << num_elec <<  std::endl;
  }

  //for(size_t i=0; i<e_g4.size(); i++) {
  //   e_r = e_g4.at(i)/e_val.at(i);
  //   if(e_r < 1){
  //          auto event = evt[i]; 
  //          // Check if the EventID is already in the evnt vector
  //          if (std::find(evt.begin(), evt.end(), event) == evt.end()) {
  //              // If not found, add the EventID to evnt
  //              evnt.push_back(event);
  //          }	     
  //   }
  //}

    // Loop through each pair of energies and EventIDs
    for (size_t i = 0; i < e_g4.size(); ++i) {
        double ratio = e_g4[i] / e_val[i];
        if (ratio < 1) {
            // Get the EventID corresponding to this energy ratio condition
            auto event = evt[i];

            // Check if the EventID is already in the evnt vector
            if (std::find(evnt.begin(), evnt.end(), event) == evnt.end()) {
                // If not found, add the EventID to evnt
                evnt.push_back(event);
            }
        }
    }  
  for(size_t i=0; i < evnt.size(); i++) {
     std::cout << evnt.at(i) << ", ";
  }

  auto tot_e1 = num_evt * num_elec * 23.6/1000000;
  std::cout << "Total E photon: " << tot_e1 << " G4 Tot E: " << e_tot << " energy at anode: " << e_r << std::endl;  

         
  // Optionally set labels and titles
  hist2->GetXaxis()->SetTitle("Ratio of Energy");
  hist->GetYaxis()->SetTitle("Hits");

  // Fill histogram with your actual time data
  //for (size_t i = 0; i < time.size(); ++i) {
      //hist->Fill(time[i]/1000., 1.0/num_evt);
      //std::cout << time.at(i) << std::endl;
  //}
  for( size_t i =0; i< e_g4.size(); i++) {
     hist2->Fill(e_g4[i]/e_val[i]);
  }
  // Fill histogram with your actual time data
  //for (size_t i = 0; i < time1.size(); ++i) {
  //    hist2->Fill(time1[i]/1000., 1.0/num_evt1);
  //}
////  // Fill histogram with your actual time data
  //for (size_t i = 0; i < time2.size(); ++i) {
  //    hist3->Fill(time2[i]/1000., 1.0/num_evt2);
  //    //std::cout << time.at(i) << std::endl;
  //}
  //// Fill histogram with your actual time data
  //for (size_t i = 0; i < time3.size(); ++i) {
  //    hist4->Fill(time3[i]/1000., 1.0/num_evt3);
  //    //std::cout << time.at(i) << std::endl;
  //}
  //// Fill histogram with your actual time data
  //for (size_t i = 0; i < time4.size(); ++i) {
  //    hist5->Fill(time4[i]/1000., 1.0/num_evt4);
  //    //std::cout << time.at(i) << std::endl;
  //}
//
  //hist->SetMaximum(20);
  hist2->SetStats(kFALSE);  
  
  //hist2->SetLineColor(kRed);
  //hist3->SetLineColor(kGreen);
  //hist4->SetLineColor(kViolet);
  //hist5->SetLineColor(kCyan);
  // Draw histograms on the same canvas
  //canvas->cd();
  //hist->Draw();                // Draw the first histogram
  hist2->Draw();         // Draw the second histogram on the same canvas
  //hist3->Draw("SAME");         // Draw the third histogram on the same canvas
  //hist4->Draw("SAME");         // Draw the fourth histogram on the same canvas
  //hist5->Draw("SAME");         // Draw the fifth histogram on the same canvas

  // Add a legend
  TLegend *legend = new TLegend(0.1, 0.7, 0.3, 0.9);
  //legend->AddEntry(hist, "Photon", "l");
  //legend->AddEntry(hist2, "Electron", "l");
  //legend->AddEntry(hist3, "Positron", "l");
  //legend->AddEntry(hist4, "Proton", "l");
  //legend->AddEntry(hist5, "alpha", "l");
  //legend->Draw();
}
