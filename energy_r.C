void energy_r() {
  // Open the first file and its tree.
  auto myFile = TFile::Open("gramsdetsimpl.root");
  auto tree = myFile->Get<TTree>("DetSim");

  // Declare that the gramsg4 tree is a friend to the DetSim tree.
  tree->AddFriend("gramsg4","gramsg4pl.root");
  tree->AddFriend("ReadoutSim", "gramsreadoutsimpl.root");

  // Define the TTreeReader for this combined tree.
  auto reader = new TTreeReader(tree);
  //bin size should be the same as the amount of wire strips for the readout  
  TH1D* hist = new TH1D("hist", "Deposited Ionization Energy/Recorded Energy",75,0,25);
  TH1D* hist2 = new TH1D("hist2", "G4 energy/readout Energy",75,0,25);
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

  std::vector<double> e_val;
  std::vector<int> evt;
  std::vector<int> evt_clus;
  Int_t num_evt = 0;
  std::vector<double> evt1;
  static const auto event = grams::EventID(0, 9);
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
  std::vector<int> secondary_track_ids;

  std::map<int,std::map<int, double>> e_g4_map;
  std::map<int,std::map<int, double>> e_val_map;
  std::map<int,std::map<int, double>> elec_map;
  std::map<int,std::map<int, double>> rec_energy;
  std::map<int,std::map<int, double>> dedx_map;
  std::map<int,std::map<int, double>> pos_map;
  std::map<int,std::set<int>> track_map;
  while (reader->Next()) {
    // Push Event IDs to the vectors
    evt.push_back(EventID_g4->Index());
    evt1.push_back(EventID->Index());

    if(*EventID == event) {

      //// Iterate over tracks and filter primary particles with energy < 10
      for (const auto& [trackID, tracks] : *track) {
          if (tracks.Process() == "Primary") {
              auto trajectory = tracks.Trajectory();
              if (!trajectory.empty()) {
                  double energy = trajectory[0].E();
                  std::cout << "Primary TrackID: " << trackID << " Energy: " << energy << std::endl;

              }
          }
      }
      // Collect LAr hits and store in the map
      for (const auto& [hitKey, track] : *track_lar) {
          auto trackID = track.TrackID();  // Assume trackID is a single integer

          //// Check if the trackID is in track_map values
          //bool found = false;
          //for (const auto& [primaryID, daughterIDs] : track_map) {
          //    if (std::find(daughterIDs.begin(), daughterIDs.end(), trackID) != daughterIDs.end()) {
          //        found = true;
          //        break;
          //    }
          //}

          //if (found) {
          auto hits = track.HitID();
          auto energy = track.E();
          e_g4_map[trackID][hits] = energy;
          auto start = track.Start4D();
          auto end = track.End4D();
          auto mean = 0.5 * (start.Z() + end.Z());

          auto diff = start - end;
          auto dx = diff.R();

          double dEdx = 0.0;
          if (dx > 0.0) {
              dEdx = (energy / dx);
          }
          double zeta = ((0.212*dEdx) / (1.3973 * 0.5));
          double effect2 = std::max(std::log(0.93 + zeta) / zeta, 1.0e-6);

          dedx_map[trackID][hits] = dEdx;

          double DriftDistance = 0 - mean;
          double TDrift = std::abs(DriftDistance * (1 / 0.00016));

          pos_map[trackID][hits] = TDrift;

          double effect = std::exp(-1.0 * TDrift / 3000000);

          z_s.push_back(1 / effect);
          rec_energy[trackID][hits] = energy * effect * effect2;
          std::cout << "HitID: " << hits << " trackid: " << track.TrackID() << " initial energy: " << energy
                    << " energy after recombination: " << energy * effect2 << " effect: " << effect2 << " Drift Time: " << TDrift
                    << " dEdx: " << dEdx << " dx: " << dx << " energy after absorption: " << energy * effect * effect2
                    << std::endl;
          //}
	  //std::cout << "TrackID: " << trackID << " energy: " << energy << std::endl;
      }

      // Iterate over clusters and update energy values in the nested map
      for (const auto& [key, cluster] : *clusters) {
          auto tracks = cluster.TrackID();
          auto hits_det = cluster.HitID();
      
          // First, find the outer map (trackID)
          auto track_it = e_g4_map.find(tracks);
          if (track_it != e_g4_map.end()) {
              // Now, find the inner map (hitID)
              auto hit_it = track_it->second.find(hits_det);
              if (hit_it != track_it->second.end()) {
                  // Update the nested map with the new energy value
                  auto num_electrons = cluster.NumElectrons();
                  auto cluster_energy = cluster.EAtAnode();
                  e_val_map[tracks][hits_det] = cluster_energy;
                  //std::cout << "TrackID: " << tracks << " HitID: " << hits_det << " energy: " << cluster_energy << std::endl;
              }
          }
      }      
    }      
  }

    double e_read =0;
    double e_truth = 0;
    double ele_num=0;
    double evnt =0;
    std::vector<double>truth_e;
    std::vector<int> hit_det;
    std::vector<double>energy_readout;
    std::vector<double> calc_energy;
    double ratio_e =0;
    //double energy_read = 0;

    for (const auto& val : e_g4) {
        e_truth += val;
    }

    // Initialize variables to store total energies
    double total_g4_energy = 0;
    double total_cluster_energy = 0;
    
    // Loop over e_g4_map to calculate total_g4_energy and populate truth_e vector
    for (const auto& [trackID, hitMap] : e_g4_map) {
        for (const auto& [hitID, energy] : hitMap) {
            total_g4_energy += energy;
            truth_e.push_back(energy);
            //std::cout << "TrackID: " << trackID << " HitID: " << hitID << " Energy: " << energy << std::endl;
        }
    }
    
    // Loop over e_val_map to calculate total_cluster_energy and populate energy_readout vector
    for (const auto& [trackID, hitMap] : e_val_map) {
        for (const auto& [hitID, energy] : hitMap) {
            total_cluster_energy += energy;
            energy_readout.push_back(energy);
            //std::cout << "TrackID: " << trackID << " HitID: " << hitID << " Energy: " << energy << std::endl;
        }
    }

    // Loop over e_val_map to calculate total_cluster_energy and populate energy_readout vector
    for (const auto& [trackID, hitMap] : rec_energy) {
        for (const auto& [hitID, energy] : hitMap) {
            ratio_e += energy;
            calc_energy.push_back(energy);
            //std::cout << "TrackID: " << trackID << " HitID: " << hitID << " Energy: " << energy << std::endl;
        }
    }    

  std::cout << "Total G4 Energy: " << total_g4_energy << " Total Cluster Energy: " << total_cluster_energy << std::endl;

	
    //std::cout<<"e_g4 :"<<truth_e.size()<<"\te_val :"<<energy_readout.size()<<"\telec :"<<elec.size()<<"\tevt: "<<evt.size()<< " evt size: " << evt.size() << " evt1 size: " << evt1.size() << "Cluster HitID Count: " << num_clus1.size() << std::endl;
    //std::cout <<"Energy from det sim: " << e_read << " Energy from G4: " << e_truth << " calculated energy: " << energy_read <<  std::endl;


    // Iterate through the map and print the contents
    std::vector<double> readout_e;
    std::vector<double> g4_energy;
    std::vector<double> dedx_val;
    std::vector<double> time_val;
    //for (const auto& [TrackID, energy] : e_val_map) {
    //    readout_e.push_back(energy);
    //    //std::cout << TrackID <<" energy" << energy << std::endl;
    //}
    //for (const auto& pair : rec_energy) {
    //    g4_energy.push_back(pair.second);
    //    //hit_det.push_back(pair.first);
    //    //std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    //}

    //for (const auto& pair : pos_map) {
    //    time_val.push_back(pair.second);
    //    //std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    //}
    //for (const auto& pair : dedx_map) {
    //    dedx_val.push_back(pair.second);
    //    //std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    //}

    for(size_t i=0; i<g4_energy.size(); i++) {
       //std::cout << "g4 energy after absorption: " << g4_energy[i] << " readout energy: " << readout_e[i] << " HitID: " << i << " drift time: " << time_val[i] << " dEdx: " << dedx_val[i] << " truth energy: " << truth_e[i] << std::endl;
    }
   std::cout<<"e_g4 :"<<g4_energy.size()<<"\te_val :"<<readout_e.size()<< " primary size: " << primary_track_ids.size() << " secondary: " << secondary_track_ids.size() << std::endl;    
  double count=0;
   for(size_t i=0; i<truth_e.size(); i++) {
     hist->Fill(truth_e[i]/energy_readout[i]);
     count += energy_readout[i];
  }
  double count2 =0;
  double count3 =0;
  for(size_t i=0; i<truth_e.size(); i++) {
     hist2->Fill(truth_e[i]/calc_energy[i]);
     count2 += calc_energy[i];
     count3+= truth_e[i];
  }
  std::cout << " Sum of readout energy: " << count<< " Sum of calculated readout energy: " << count2<< " Sum of G4 energy: " << count3 << std::endl; 
  hist->SetMaximum(2700);
  hist->GetXaxis()->SetTitle("Energy Ratio");
  hist->SetStats(kFALSE);
  hist2->SetLineColor(kRed);
  hist->Draw();
  hist2->Draw("same");
  gPad->SetLogx(); 

  TLegend *legend = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend->AddEntry(hist, "energy from readout sim", "l");
  legend->AddEntry(hist2, "calculated energy", "l");
  legend->Draw();

}



