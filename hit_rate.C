// Define a struct to hold event data
struct EventData {
    int totalHits;
    int uniqueHits;
    double ratio;
};

void hit_rate() {  
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
    std::map<int, std::map<int, std::vector<int>>> nonzero_counts_by_energy_range;
    std::map<std::pair<double, double>, std::map<int, std::vector<int>>> nonzero_counts;    
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
					    //std::cout << "Total ADC: " << value << std::endl;
					}

                                        if (std::find(cluster_hit.begin(), cluster_hit.end(), hitID) != cluster_hit.end()) {
                                            if (!positiveDigital.empty()) {
                                                adc_counts_by_energy_range[EventID->Index()][hitID] = positiveDigital;
						adc_counts[{low, high}][hitID] = positiveDigital; 
                                            }
                                        }

                                        if (std::find(cluster_hit.begin(), cluster_hit.end(), hitID) != cluster_hit.end()) {
                                            if (!all_val.empty()) {
                                                nonzero_counts_by_energy_range[EventID->Index()][hitID] = all_val;
                                                nonzero_counts[{low, high}][hitID] = all_val;
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
    //int colorIndex=0;
    int total=0;

//    std::map<std::pair<double, double>, TH1D*> histograms;
//    std::vector<int> colors = {kRed+3, kGreen, kBlue,kMagenta};
//    for (const auto& range : energyRanges) {
//        std::string histName = "hist_" + std::to_string(range.first) + "_" + std::to_string(range.second);
//        histograms[range] = new TH1D(histName.c_str(), "Occupancy for specified energies of the incoming photons", 20, 0.01, 22);
//        histograms[range]->SetLineColor(colors[colorIndex % colors.size()]); // Assign color
//        ++colorIndex;
//    }
//
//    std::set<int> uniqueHitIDs;
//
//    for (const auto& [energyRange, hit_map] : adc_counts) {
//        auto hist = histograms[energyRange];
//        for (const auto& [hitID, digital_values] : hit_map) {
//            hist->Fill(digital_values.size()); // Fill with count of values
//            uniqueHitIDs.insert(hitID); // Store unique hitID
//        }
//    }    
//
//    // Collect unique hit IDs
//    for (const auto& [eventID, hit_map] : adc_counts_by_energy_range) {
//        for (const auto& [hitID, digital_values] : hit_map) {
//            uniqueHitIDs.insert(hitID);
//        }
//    }
//
//    // Create and configure canvas
//    TCanvas* canvas = new TCanvas("canvas", "Histograms", 800, 600);
//    canvas->SetLogy(); // Set y-axis to logarithmic scale
//    canvas->cd(); // Ensure you are on the main pad
//
//    // Draw histograms on the same pad
//    bool firstHist = true;
//    for (const auto& [range, hist] : histograms) {
//        if (firstHist) {
//	    hist->SetMaximum(10000);
//	    hist->SetStats(kFALSE);
//	    hist->SetXTitle("Number of Non Zero ADC Values");
//            hist->Draw("same");
//            firstHist = false;
//        } else {
//            hist->Draw("same");
//        }
//    }
//
//    // Create legend and add entries
//    TLegend* legend = new TLegend(0.6, 0.7, 0.9, 0.9); // Position of the legend
//    for (const auto& [range, hist] : histograms) {
//        legend->AddEntry(hist, (std::to_string(range.first) + "-" + std::to_string(range.second) + " MeV").c_str(), "l");
//    }
//
//    // Draw the legend
//    legend->Draw();    
//
//}

    // Create histograms
    std::map<std::pair<double, double>, TH1D*> histograms;
    std::vector<int> colors = {kRed+3, kGreen, kBlue, kMagenta};
    int colorIndex = 0;

    for (const auto& range : energyRanges) {
        std::string histName = "hist_" + std::to_string(range.first) + "_" + std::to_string(range.second);
        histograms[range] = new TH1D(histName.c_str(), "Non-Zero ADC / Total ADC", 20, 0, 1);
        histograms[range]->SetLineColor(colors[colorIndex % colors.size()]);
        ++colorIndex;
    }

    // Fill histograms with the ratio of non-zero ADC counts to total ADC counts
    for (const auto& range : energyRanges) {
        double non_zero_count = adc_counts[range];
        double total_count = nonzero_counts[range];
	std::cout<<"Total ADC Size: "<< total_adc_counts[range]<<std::endl;

        if (total_count > 0) {
            double ratio = non_zero_count / total_count;
            histograms[range]->Fill(ratio);
        } else {
            std::cerr << "Warning: Total count is zero for range " << range.first << " - " << range.second << " MeV." << std::endl;
        }
    }

    // Plotting and Legend (As in your existing code)
    TCanvas* canvas = new TCanvas("canvas", "Histograms", 800, 600);
    canvas->SetLogy();
    canvas->cd();

    bool firstHist = true;
    for (const auto& [range, hist] : histograms) {
        if (firstHist) {
            hist->SetMaximum(1);
            hist->SetStats(kFALSE);
            hist->SetXTitle("Non-Zero ADC / Total ADC");
            hist->Draw();
            firstHist = false;
        } else {
            hist->Draw("same");
        }
    }

    TLegend* legend = new TLegend(0.6, 0.7, 0.9, 0.9);
    for (const auto& [range, hist] : histograms) {
        legend->AddEntry(hist, (std::to_string(range.first) + "-" + std::to_string(range.second) + " MeV").c_str(), "l");
    }

    legend->Draw();
}
