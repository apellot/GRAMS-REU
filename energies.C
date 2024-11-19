void energies() {
  // Open the first file and its tree.
  auto myFile = TFile::Open("gramsdetsim.root");
  auto tree = myFile->Get<TTree>("DetSim");

  // Declare that the gramsg4 tree is a friend to the DetSim tree.
  tree->AddFriend("gramsg4","gramsg4.root");
  tree->AddFriend("ReadoutSim", "gramsreadoutsim.root");

  // Define the TTreeReader for this combined tree.
  auto reader = new TTreeReader(tree);
  //bin size should be the same as the amount of wire strips for the readout  
  TH1D* hist = new TH1D("hist", "G4 energy/readout Energy",50,0,25);
  TH1D* hist2 = new TH1D("hist2", "G4 energy/readout Energy",50,0,25);
  //TH1D* hist3 = new TH1D("hist3", "Normalized Time Counts",250,0,125000/1000);
  //TH1D* hist4 = new TH1D("hist4", "Normalized Time Counts",250,0,125000/1000);
  //TH1D* hist5 = new TH1D("hist5", "Normalized Time Counts",250,0,125000/1000);
  TCanvas* canvas = new TCanvas("canvas","hist",800,800);

  //read in the different classes that you need information from
  TTreeReaderValue<grams::EventID>   EventID  (*reader, "DetSim.EventID");
  TTreeReaderValue<grams::EventID>   EventID_g4  (*reader, "gramsg4.EventID");
  TTreeReaderValue<grams::ElectronClusters> clusters(*reader, "ElectronClusters");
  TTreeReaderValue<grams::ReadoutMap> readout(*reader, "ReadoutMap");

  TTreeReaderValue<grams::MCTrackList> track(*reader, "gramsg4.TrackList");
  TTreeReaderValue<grams::MCLArHits> track_lar(*reader, "gramsg4.LArHits");

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
  static const auto event = grams::EventID(0, 1000);
  std::vector<double> e_g4;
  std::vector<double> elec;
  std::vector<double> g4_hit;
  std::vector<double> read_hit;
  std::vector<double> z_s;
  std::vector<double> z_f;
  double z_mean =0;
  //double diff =0;
  double dx =0;
  double dEdx = 0;
  std::set<int> primary_track_ids;
  std::set<int> secondary_track_ids;

  std::map<int, double> e_g4_map;
  std::map<int, double> e_val_map;
  std::map<int, double> elec_map;
  std::map<int, double> rec_energy;
  std::map<int, double> dedx_map;
  std::map<int, double> pos_map;
    while (reader->Next()) {
          //if(*EventID == event) {
          evt.push_back(EventID_g4->Index());
          evt1.push_back(EventID->Index());

        // Iterate over tracks and filter primary particles with energy < 1
          // Iterate over tracks and filter primary particles with energy > 10
          for (const auto& [trackID, tracks] : *track) {
              if (tracks.Process() == "Primary") {
                  auto trajectory = tracks.Trajectory();
                  if (!trajectory.empty()) {
                      double energy = trajectory.front().E();
                      std::cout << "Primary TrackID: " << trackID << " Energy: " << energy << std::endl;
                      if (energy < 10) {
                          // Loop through all the daughters of this primary particle
                          for (auto daughterID : tracks.Daughters()) {
                              // Use find to safely access daughter track
                              const auto search = track->find(daughterID);
                              if (search == track->cend()) {
                                  std::cerr << "Error: Daughter TrackID " << daughterID << " not found in tracks." << std::endl;
                                  continue; // Skip to the next daughterID
                              }
                              
                              const auto& daughter = search->second;
                              if (daughter.Process() == "compt") {
                                  // Save the track ID of the secondary Compton scatter
                                  secondary_track_ids.insert(daughterID);
                                  std::cout << "Secondary TrackID (Compton): " << daughterID << std::endl;
                              }
                          }
                      }
                  }
              }
          }
          // Collect LAr hits and store in the map
          for (const auto& [hitKey, track] : *track_lar) {
	    auto tracks = track.TrackID();
	    if (secondary_track_ids.find(tracks) != secondary_track_ids.end()) {
	       auto hits = track.HitID();    
               auto energy = track.E();
               e_g4_map[hits] = energy;
               auto start = track.Start4D();
               auto end = track.End4D();
               auto mean = 0.5 * (start.Z() + end.Z());
               //std::cout << "initial energy: " << energy << " HitID: " << hits << "energy after recombination:" << energy * effect1  << "energy after absorption:" << energy * effect * effect2 << std::endl;

               auto diff = start - end;
               auto dx = diff.R();
               //double dx = std::sqrt( std::pow(track.StartX() - track.EndX(), 2) +
                                    //std::pow(track.StartY() - track.EndY(), 2) +
                                    //std::pow(track.StartZ() - track.EndZ(), 2) );

               if ( dx > 0. ) {
                 dEdx = (energy / dx);
               }
               double zeta = 0.212/(1.3973*0.5) * (dEdx);
               double effect2 = std::max(
                                   std::log10(0.93 + zeta) / zeta, 1.0e-6);
               //std::cout << "recombination: " << 1/effect2 << std::endl;
               //std::cout << "initial energy: " << energy << "energy after recombination:" << energy * effect  << "energy after absorption:" << energy * effect * effect2 << std::endl;
               dedx_map[hits] += dEdx;

               double DriftDistance = 0  - mean;
               double TDrift = std::abs(DriftDistance * (1/0.00016));

               pos_map[hits]+=TDrift;

               double effect = std::exp( -1.0 * TDrift / 50000);

               z_s.push_back(1/effect);
               rec_energy[hits] = energy*effect*effect2;
               //std::cout << "HitID: " << hits << " trackid: " << track.TrackID() <<  " initial energy: " << energy << "energy after recombination:" << energy * effect2 << " effect: " << effect2 << " dedx: " << dEdx << " dx: " << dx << "energy after absorption:" << energy * effect * effect2 << std::endl;
	    }

          }


          // Match hits_det with hits and calculate energy
          for (const auto& [key, cluster] : *clusters) {
              auto tracks = cluster.TrackID();
              if (secondary_track_ids.find(tracks) != secondary_track_ids.end()) {		  
                 auto hits_det = cluster.HitID();
                 auto it = e_g4_map.find(hits_det);
                 if (it != e_g4_map.end()) {
                     auto num_electrons = cluster.NumElectrons();
                     auto cluster_energy = cluster.EAtAnode();
                     e_val_map[hits_det] += cluster_energy;
	         }
                 }
          }

            //}
          double total_cluster_energy = 0;
          for (const auto& [HitID, energy] : e_val_map) {
              //total_cluster_energy += energy;
              std::cout << "HitID: " << HitID << " energy: " << energy << std::endl;
          }
   }

    double e_read =0;
    double e_truth = 0;
    double ele_num=0;
    double evnt =0;
    std::vector<double>truth_e;
    std::vector<int> hit_det;
    //double energy_read = 0;

    for (const auto& val : e_g4) {
        e_truth += val;
    }

  // Calculate and compare total energies
  double total_g4_energy = 0;
  for (const auto& [HitID, energy] : e_g4_map) {
    total_g4_energy += energy;
    truth_e.push_back(energy);
    //std::cout << HitID << std::endl;
  }

  double total_cluster_energy = 0;
  for (const auto& [HitID, energy] : e_val_map) {
    total_cluster_energy += energy;
    //std::cout << HitID << std::endl;
  }


  std::cout << "Total G4 Energy: " << total_g4_energy*2.36e-5 << " Total Cluster Energy: " << total_cluster_energy*2.36e-5 << std::endl;
    //auto energy_read = total_elec * 2.36e-5;
    for(size_t i=0; i < evt.size(); i++) {
       //std::cout << "G4 evt id: " << evt[i] << " readout id: " << evt1[i] << std::endl;
    }

  //for (size_t i =0; i< elec.size(); i++) {
    //energy_read += elec[i] * 23.6/1000000 * num_clus1[i];
  //}
  int count = 0;
  for (size_t i =0; i< z_s.size(); i++) {
    z_mean+= z_s[i];
    count++;
  }

  int count1 = 0;
  for (size_t i =0; i< z_f.size(); i++) {
    dEdx+= z_f[i];
    count1++;
  }  

	
    //std::cout<<"e_g4 :"<<e_g4.size()<<"\te_val :"<<e_val.size()<<"\telec :"<<elec.size()<<"\tevt: "<<evt.size()<< " evt size: " << evt.size() << " evt1 size: " << evt1.size() << "Cluster HitID Count: " << num_clus1.size() << std::endl;
    //std::cout <<"Energy from det sim: " << e_read << " Energy from G4: " << e_truth << " calculated energy: " << energy_read <<  std::endl;


   // double DriftDistance = 0  - z_mean/count;
   // double TDrift = std::abs(DriftDistance * (1/0.00016));

   // double effect = std::exp( -1.0 * TDrift / 50000);

   // std::cout << "absorption: " << 1/effect << std::endl;

    //double zeta = 0.212/(1.3973*0.5) * (dEdx/count1);
    //double effect2 = std::max(
    //    		  std::log(0.93 + zeta) / zeta, 1.0e-6);
    //std::cout << "recombination: " << 1/effect2 << std::endl;
    //
    // Iterate through the map and print the contents
    std::vector<double> readout_e;
    std::vector<double> g4_energy;
    std::vector<double> dedx_val;
    std::vector<double> time_val;
    for (const auto& [HitID, energy] : e_val_map) {
        readout_e.push_back(energy);
        //std::cout << HitID << std::endl;
    }
    for (const auto& pair : rec_energy) {
	g4_energy.push_back(pair.second);
	//hit_det.push_back(pair.first);
        //std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    for (const auto& pair : pos_map) {
        time_val.push_back(pair.second);
        //std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
    for (const auto& pair : dedx_map) {
        dedx_val.push_back(pair.second);
        //std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    for(size_t i=0; i<g4_energy.size(); i++) {
       //std::cout << "g4 energy after absorption: " << g4_energy[i] << " readout energy: " << readout_e[i] << " HitID: " << i << " drift time: " << time_val[i] << " dEdx: " << dedx_val[i] << " truth energy: " << truth_e[i] << std::endl;
    }
   std::cout<<"e_g4 :"<<g4_energy.size()<<"\te_val :"<<readout_e.size()<< " primary size: " << primary_track_ids.size() << " secondary: " << secondary_track_ids.size() << std::endl;    
  // Fill the histogram with the ratio values
  for (const auto& [eventID, g4_energy] : e_g4_map) {
    if (e_val_map.find(eventID) != e_val_map.end()) {
      double val_energy = e_val_map[eventID];
      if (val_energy != 0) {
        double ratio = g4_energy / val_energy;
        hist->Fill(ratio);
      }
    }
  }

  //for(size_t i =0; i<readout_e.size(); i++) {
     //hist2->Fill(truth_e[i]/readout_e[i]);
  //}

  // Fill the histogram with the ratio values
  for (const auto& [eventID, g4_energy] : e_g4_map) {
    if (e_val_map.find(eventID) != e_val_map.end()) {
      double val_energy = rec_energy[eventID];
      if (val_energy != 0) {
        double ratio = g4_energy / val_energy;
        hist2->Fill(ratio);
      }
    }
  }  
  hist->SetMaximum(700);
  hist->SetStats(kFALSE);
  hist2->SetLineColor(kRed);
  hist->Draw();
  hist2->Draw("same"); 

  TLegend *legend = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend->AddEntry(hist, "energy from readout sim <1", "l");
  legend->AddEntry(hist2, "calculated energy < 1", "l");
  legend->Draw();

}



