void adc() {  
     auto myFile = TFile::Open("gramsdetsimpl.root");
     auto tree = myFile->Get<TTree>("DetSim");

     // Declare that the gramsg4 tree is a friend to the DetSim tree.
     tree->AddFriend("gramsg4","gramsg4pl.root");
     tree->AddFriend("ReadoutSim", "gramsreadoutsimpl.root");
     tree->AddFriend("ElecSim", "gramselecsimpl.root");

     // Define the TTreeReader for this combined tree.
     auto reader = new TTreeReader(tree);
     //bin size should be the same as the amount of wire strips for the readout  
     TH1D* hist = new TH1D("hist", "ADC Counts",50,0,4096);
     //TH1D* hist2 = new TH1D("hist2", "G4 energy/readout Energy",50,0.05,200);
     TCanvas* c1 = new TCanvas("c1","hist",800,800);
     //TCanvas* c2 = new TCanvas("c2","hist2",800,800);

     //read in the different classes that you need information from
     TTreeReaderValue<grams::EventID>   EventID  (*reader, "ReadoutSim.EventID");
     TTreeReaderValue<grams::EventID>   EventID_g4  (*reader, "gramsg4.EventID");
     TTreeReaderValue<grams::ElectronClusters> clusters(*reader, "ElectronClusters");
     TTreeReaderValue<grams::ReadoutMap> readout(*reader, "ReadoutMap");

     TTreeReaderValue<grams::MCTrackList> track(*reader, "gramsg4.TrackList");
     TTreeReaderValue<grams::MCLArHits> track_lar(*reader, "gramsg4.LArHits");
     TTreeReaderValue<grams::ReadoutWaveforms> waves(*reader, "ReadoutWaveforms");

     std::vector<int> adc;
     std::vector<int> events;
     std::map<int,double> e_g4;
     std::map<int, double> event_energy;
     std::map<int, std::vector<int>> adc_count;
     std::vector<int> cluster_hit;

     while(reader->Next()) {
            // Vector to save track IDs of primary particles
            std::vector<int> primaries;

            // Iterate over tracks and filter primary particles
            for (const auto& [trackID, t] : *track) {
                if (t.Process() == "Primary") {
                    // Save the ID of this track
                    primaries.push_back(trackID);

                    auto trajectory = t.Trajectory();
                    if (!trajectory.empty() && trajectory[0].E() <10) {
                        auto e = trajectory[0].E();
			e_g4[EventID_g4->Index()] = e;
			//e_g4_hit.push_back(t.HitID());

                    }
                }
            }


            for (const auto& [readoutID, clusterKeys] : *readout) {
                for (const auto& clusterKey : clusterKeys) {
                    auto result = clusters->find(clusterKey);
                    if (result == clusters->end()) {
                        std::cerr << "Inconsist readout->electron cluster map" << std::endl;
                        exit(EXIT_FAILURE);
                    }
		    auto& readoutCluster = result->second;
                    // Assuming clusterKey can be unpacked as [trackID, hitID, clusterID]
                    const auto [trackID, hitID, clusterID] = clusterKey;

                    // Check if there was a hit
                    if (hitID != -1) {  // Assuming -1 indicates no hit; replace with actual logic if different
                        events.push_back(EventID->Index());
			cluster_hit.push_back(hitID);
                        break; // Exit the loop if a hit is found
                    }		    
                }
            }

        // Check if the current event is in the events vector
        if (std::find(events.begin(), events.end(), EventID_g4->Index()) != events.end()) {
            // If the current event is found, store it along with its initial energy
            int current_event = EventID_g4->Index();
            if (e_g4.find(current_event) != e_g4.end()) {
                event_energy[current_event] = e_g4[current_event];
            }	
	}

             for(const auto& [readoutID, wave]: *waves) {
                auto digital = wave.Digital();
		//const auto search = readout.find( readoutID );
		//auto hit = (*search).first;
                const auto& readoutMap = *readout; // Dereference TTreeReaderValue to get the map
                
                // Find the corresponding entry in the readout map
                auto search = readout->find(readoutID);
		auto& clusterKeys = (*search).second;

                if (search != readoutMap.end()) {
                    //auto& clusterKeys = search->second;

                    for (const auto& clusterKey : clusterKeys) {
                        const auto [trackID, hitID, clusterID] = clusterKey;

                    // Filter out non-positive values and only assign if there are positive values
                    std::vector<int> positiveDigital;
                    for (int value : digital) {
                        if (value > 0) {
                            positiveDigital.push_back(value);
                        }
                    }

                    // Only store the hitID if there are positive digital values
		    if (std::find(cluster_hit.begin(), cluster_hit.end(), hitID) != cluster_hit.end()) {
                       if (!positiveDigital.empty()) {
                           adc_count[hitID] = positiveDigital;

                           // Print the waveform
                           //std::cout << "Waveform for hitID " << hitID << ": ";
                           for (int value : positiveDigital) {
                               //std::cout << value << " ";
                           }
                           //std::cout << std::endl;
                       }
                       } // for every cluster key
		    }
                } else {
                    std::cout << "readoutID " << readoutID << " not found in readout map." << std::endl;
                }
	     
	     }
     }
    int count =0;
    int total =0;
    std::set<int> uniqueHitIDs;
    // Loop through the map and process elements
    for (auto& pair : adc_count) {
        int key = pair.first;
        std::vector<int>& values = pair.second;
	uniqueHitIDs.insert(key);

        // Example processing: print the key and values
        //std::cout << "Key: " << key << " Values: ";
        for (int value : values) {
	    if(value > 0) {
              //std::cout << value << " ";
	      hist->Fill(value);
	      total++;
	    }
        }
        //std::cout << std::endl;
    }

    for (const int& hitID : uniqueHitIDs) {
        //std::cout << hitID << std::endl;
	count++;
    }    
    std::cout << "hit channels: " << count << " total channels: " << total << std::endl;


     
     // Optionally set labels and titles
     //hist->GetXaxis()->SetTitle("Initial Gamma-ray energy (MeV)");
     //hist->GetYaxis()->SetTitle("Counts");
     //hist->SetStats(kFALSE);
     c1->SetLogy();
     c1->cd();
     hist->Draw();
}
