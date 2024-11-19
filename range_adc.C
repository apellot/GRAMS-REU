// Define a struct to hold event data
struct EventData {
    int totalHits;
    int uniqueHits;
    double ratio;
};

void range_adc() {  
     auto myFile = TFile::Open("gramsdetsimpl.root");
     auto tree = myFile->Get<TTree>("DetSim");

     // Declare that the gramsg4 tree is a friend to the DetSim tree.
     tree->AddFriend("gramsg4","gramsg4pl.root");
     tree->AddFriend("ReadoutSim", "gramsreadoutsimpl.root");
     tree->AddFriend("ElecSim", "gramselecsimpl.root");

     // Define the TTreeReader for this combined tree.
     auto reader = new TTreeReader(tree);
     //bin size should be the same as the amount of wire strips for the readout  
     //TH1D* hist = new TH1D("hist", "ADC Counts",50,0,4050);
     //TH1D* hist2 = new TH1D("hist2", "G4 energy/readout Energy",50,0.05,200);
     //TCanvas* c1 = new TCanvas("c1","hist",800,800);
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
     std::vector<int>all_val;

    // Define energy ranges
    std::vector<std::pair<double, double>> energyRanges = {{0, 10}, {10, 50}, {50, 100},{100,200}};
    
    // Maps to store ADC counts by hitID and energy range
    std::map<int, std::map<int, std::vector<int>>> adc_counts_by_energy_range;
    std::map<std::pair<double, double>, std::map<int, std::vector<int>>> adc_counts;
     while(reader->Next()) {
            // Vector to save track IDs of primary particles
            std::vector<int> primaries;

            // Example energy retrieval
            for (const auto& [trackID, t] : *track) {
                if (t.Process() == "Primary") {
                    primaries.push_back(trackID);

                    auto trajectory = t.Trajectory();
                    if (!trajectory.empty()) {
                        auto e = trajectory[0].E();
                        e_g4[EventID_g4->Index()] = e;

                        int current_event = EventID_g4->Index();
                        if (e >= 0 && e < 10) {
                            event_energy[current_event] = e;
                        }
                    }
                }
            }

            // Iterate over readout and clusterKeys
            for (const auto& [readoutID, clusterKeys] : *readout) {
                for (const auto& clusterKey : clusterKeys) {
                    auto result = clusters->find(clusterKey);
                    if (result == clusters->end()) {
                        std::cerr << "Inconsist readout->electron cluster map" << std::endl;
                        exit(EXIT_FAILURE);
                    }
                    auto& readoutCluster = result->second;
                    const auto [trackID, hitID, clusterID] = clusterKey;

                    if (hitID != -1) {
                        events.push_back(EventID->Index());
                        cluster_hit.push_back(hitID);
                        break;
                    }
                }
            }

            if (std::find(events.begin(), events.end(), EventID_g4->Index()) != events.end()) {
                int current_event = EventID_g4->Index();
                if (e_g4.find(current_event) != e_g4.end()) {
                    double energy = e_g4[current_event];
                    for (const auto& [low, high] : energyRanges) {
                        if (energy >= low && energy < high) {
                            for (const auto& [readoutID, wave] : *waves) {
                                auto digital = wave.Digital();
                                const auto& readoutMap = *readout;

                                auto search = readoutMap.find(readoutID);
                                if (search != readoutMap.end()) {
                                    auto& clusterKeys = search->second;

                                    for (const auto& clusterKey : clusterKeys) {
                                        const auto [trackID, hitID, clusterID] = clusterKey;

                                        std::vector<int> positiveDigital;
                                        for (int value : digital) {
                                            if (value > 0) {
                                                positiveDigital.push_back(value);
                                            }
                                        }

					for(int value : digital) {
					    all_val.push_back(value);
					}

                                        if (std::find(cluster_hit.begin(), cluster_hit.end(), hitID) != cluster_hit.end()) {
                                            if (!positiveDigital.empty()) {
                                                adc_counts_by_energy_range[EventID->Index()][hitID] = positiveDigital;
						adc_counts[{low, high}][hitID] = positiveDigital; 
                                            }
                                        }
                                    }
                                } else {
                                    std::cout << "readoutID " << readoutID << " not found in readout map." << std::endl;
                                }
                            }
                            break;
                        }
                    }
                }
            }
	    

     }
    int count =0;
    int colorIndex=0;
    int total=0;

    std::map<std::pair<double, double>, TH1D*> histograms;
    std::vector<int> colors = {kRed+3, kGreen, kBlue,kMagenta};
    for (const auto& range : energyRanges) {
        std::string histName = "hist_" + std::to_string(range.first) + "_" + std::to_string(range.second);
        histograms[range] = new TH1D(histName.c_str(), "Occupancy for specified energies of the incoming photons", 20, 0.01, 22);
        histograms[range]->SetLineColor(colors[colorIndex % colors.size()]); // Assign color
        ++colorIndex;
    }

    std::set<int> uniqueHitIDs;

    //for (const auto& [energyRange, event_map] : adc_counts_by_energy_range) {
    //    auto hist = histograms[energyRange];
    //    for (const auto& [eventID, hit_map] : event_map) {
    //        for (const auto& [hitID, digital_values] : hit_map) {
    //            for (int value : digital_values) {
    //                hist->Fill(value);
    //                total++;
    //            }
    //        }
    //    }
    //}

    // Replace this with actual filling code
    //for (const auto& [energyRange, hit_map] : adc_counts) {
    //    auto hist = histograms[energyRange];
    //    for (const auto& [hitID, digital_values] : hit_map) {
    //        for (int value : digital_values) {
    //            hist->Fill(value);
    //        }
    //        uniqueHitIDs.insert(hitID); // Store unique hitID
    //    }
    //}

    for (const auto& [energyRange, hit_map] : adc_counts) {
        auto hist = histograms[energyRange];
        for (const auto& [hitID, digital_values] : hit_map) {
            hist->Fill(digital_values.size()); // Fill with count of values
            uniqueHitIDs.insert(hitID); // Store unique hitID
        }
    }    

    // Collect unique hit IDs
    for (const auto& [eventID, hit_map] : adc_counts_by_energy_range) {
        for (const auto& [hitID, digital_values] : hit_map) {
            uniqueHitIDs.insert(hitID);
        }
    }

    // Create and configure canvas
    TCanvas* canvas = new TCanvas("canvas", "Histograms", 800, 600);
    canvas->SetLogy(); // Set y-axis to logarithmic scale
    canvas->cd(); // Ensure you are on the main pad

    // Draw histograms on the same pad
    bool firstHist = true;
    for (const auto& [range, hist] : histograms) {
        if (firstHist) {
	    hist->SetMaximum(10000);
	    hist->SetStats(kFALSE);
	    hist->SetXTitle("Number of Non Zero ADC Values");
            hist->Draw("same");
            firstHist = false;
        } else {
            hist->Draw("same");
        }
    }

    // Create legend and add entries
    TLegend* legend = new TLegend(0.6, 0.7, 0.9, 0.9); // Position of the legend
    for (const auto& [range, hist] : histograms) {
        legend->AddEntry(hist, (std::to_string(range.first) + "-" + std::to_string(range.second) + " MeV").c_str(), "l");
    }

    // Draw the legend
    legend->Draw();    

    // Print hit counts
    for (const int& hitID : uniqueHitIDs) {
        count++;
    }

    std::cout << "Total # of channels: " << total << " channels hit: " << count << std::endl;
    std::map<int, EventData> eventDataMap;

    // Output unique and total hits for each event
    for (const auto& [eventID, hit_map] : adc_counts_by_energy_range) {
        std::set<int> uniqueHits;
        int totalHits = 0;
	int totalDigitalValues =0;
        for (const auto& [hitID, digital_values] : hit_map) {
            uniqueHits.insert(hitID);
            totalHits += digital_values.size();
	    totalDigitalValues += digital_values.size();
	    //std::cout << " EventID: " << eventID << " HitID: " << hitID << " ADC Value: ";
            for (int value : digital_values) {
                //std::cout << value << " ";
            }
            //std::cout << std::endl;	    
        }
	double ratio = static_cast<double>(uniqueHits.size()) / totalDigitalValues;
        std::cout << "  Event ID: " << eventID << std::endl;
        std::cout << "    Total hits: " << totalHits << std::endl;
        std::cout << "    Unique hits: " << uniqueHits.size() << std::endl;
	std::cout << "    Ratio of total hits to total digital values: " << ratio << std::endl;
	eventDataMap[eventID] = {totalHits, static_cast<int>(uniqueHits.size()), ratio};
    }

    // Define the number of bins and the energy range
    //int nBins = 200;  // Adjust the number of bins based on your data
    double energyMin = 100.0;
    double energyMax = 200.0;  // Adjust the maximum energy based on your data
     Double_t tmin = 100.0;
     Double_t tmax = 200;

     // Define the number of bins and calculate the bin edges based on the time range
     Int_t nbins = 30; // Adjust as needed
     Double_t *ebins = new Double_t[nbins + 1];
     for (Int_t i = 0; i <= nbins; ++i) {
         ebins[i] = TMath::Power(10, TMath::Log10(tmin) + (TMath::Log10(tmax) - TMath::Log10(tmin)) / nbins * i);
     }

     // Create the histograms with time on the x-axis and logarithmically spaced bins
     TH1D *hist2 = new TH1D("hist2", "dN/dE vs. E", nbins, ebins);    
    
    // Assuming adc_counts_by_energy_range and e_g4 are already filled
    for (const auto& [eventID, hit_map] : adc_counts_by_energy_range) {
        if (e_g4.find(eventID) != e_g4.end()) {
            double energy = e_g4[eventID];
            for (const auto& [hitID, digital_values] : hit_map) {
                hist2->Fill(energy, digital_values.size());
            }
        }
    }

    // Normalize the histogram to get dN/dE
    hist2->Scale(1.0 / hist2->GetBinWidth(1));    
    // Create and configure the canvas
    TCanvas* c1 = new TCanvas("c1", "dN/dE vs. E", 800, 600);
    c1->SetLogy();  // Optional: Set y-axis to logarithmic scale if desired
    c1->SetLogx();
    c1->cd();
    
    // Draw the graph
    hist2->Draw("hist");
    
    // Save the canvas to a file if needed
    c1->SaveAs("dN_dE_vs_E.png");
    
    // Save or display the canvas
    canvas->Update(); // Go back to the main pad
    canvas->SaveAs("histograms.png");

}
