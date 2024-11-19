void e_initial() {  
     auto myFile = TFile::Open("gramsdetsimpl.root");
     auto tree = myFile->Get<TTree>("DetSim");

     // Declare that the gramsg4 tree is a friend to the DetSim tree.
     tree->AddFriend("gramsg4","gramsg4pl.root");
     tree->AddFriend("ReadoutSim", "gramsreadoutsimpl.root");
     tree->AddFriend("ElecSim", "gramselecsimpl.root");

     // Define the TTreeReader for this combined tree.
     auto reader = new TTreeReader(tree);
     //bin size should be the same as the amount of wire strips for the readout  
     //TH1D* hist = new TH1D("hist", "ADC Counts",50,0.05,200);
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

     while(reader->Next()) {
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
			e_g4[EventID_g4->Index()] = e;

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
     }
     Double_t tmin = 0.05;
     Double_t tmax = 200;
     
     // Define the number of bins and calculate the bin edges based on the time range
     Int_t nbins = 50; // Adjust as needed
     Double_t *ebins = new Double_t[nbins + 1];
     for (Int_t i = 0; i <= nbins; ++i) {
         ebins[i] = TMath::Power(10, TMath::Log10(tmin) + (TMath::Log10(tmax) - TMath::Log10(tmin)) / nbins * i);
     }
     
     // Create the histograms with time on the x-axis and logarithmically spaced bins
     TH1D *hist = new TH1D("hist", "Initial Energies", nbins, ebins);
     TH1D *hist2 = new TH1D("hist2", "Initial Energy from ReadoutSim", nbins, ebins);
     
     // Optionally set labels and titles
     hist->GetXaxis()->SetTitle("Initial Gamma-ray energy (MeV)");
     hist->GetYaxis()->SetTitle("Events");
     hist2->GetXaxis()->SetTitle("Initial Gamma-ray energy (MeV)");
     hist2->GetYaxis()->SetTitle("Counts");     
     
     // Ensure e_g4 and event_energy maps are populated correctly
     if (e_g4.empty()) {
         std::cerr << "Warning: e_g4 map is empty!" << std::endl;
     }
     if (event_energy.empty()) {
         std::cerr << "Warning: event_energy map is empty!" << std::endl;
     }

    // Open a file to save energy values
    std::ofstream outFile("energy_values_readout.txt");
    if (!outFile) {
        std::cerr << "Error opening file for writing!" << std::endl;
    }     
     
     // Fill histograms with your actual time data
     for (const auto& [event, energy] : event_energy) {
         std::cout << energy << std::endl;
         hist2->Fill(energy);
	 outFile << energy << std::endl;
     }
     for (const auto& [EventID, energy] : e_g4) {
         hist->Fill(energy);
	 //outFile << energy << std::endl;
     }

     outFile.close();
     
     // Set line color for the second histogram
     hist2->SetLineColor(kRed);
     hist->SetStats(kFALSE);
     hist2->SetStats(kFALSE);
     
     // Draw the histograms
     c1->SetLogx();
     c1->SetLogy();
     c1->cd();
     hist->SetMaximum(1000);
     hist->Draw();

    TLegend* legend1 = new TLegend(0.6, 0.7, 0.9, 0.9);
    legend1->AddEntry(hist, "G4 Energy", "l");
    legend1->AddEntry(hist2, "Readout Energy", "l");
    legend1->Draw();     
     //c2->SetLogx();
     //c2->cd();
     hist2->Draw("same");
     
     // Clean up
     delete[] ebins;
}
