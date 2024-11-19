void hits() {
    auto myFile = TFile::Open("gramsdetsimpl.root");
    auto tree = myFile->Get<TTree>("DetSim");

    // Declare that the gramsg4 tree is a friend to the DetSim tree.
    tree->AddFriend("gramsg4","gramsg4pl.root");
    tree->AddFriend("ReadoutSim", "gramsreadoutsimpl.root");
    tree->AddFriend("ElecSim", "gramselecsimpl.root");

    // Define the TTreeReader for this combined tree.
    auto reader = new TTreeReader(tree);

    // Read in the different classes that you need information from
    TTreeReaderValue<grams::EventID>   EventID(*reader, "ReadoutSim.EventID");
    TTreeReaderValue<grams::EventID>   EventID_g4(*reader, "gramsg4.EventID");
    TTreeReaderValue<grams::ElectronClusters> clusters(*reader, "ElectronClusters");
    TTreeReaderValue<grams::ReadoutMap> readout(*reader, "ReadoutMap");
    TTreeReaderValue<grams::MCTrackList> track(*reader, "gramsg4.TrackList");
    TTreeReaderValue<grams::ReadoutWaveforms> waves(*reader, "ReadoutWaveforms");

    // Define energy ranges
    std::vector<std::pair<double, double>> energyRanges = {{0, 10}, {10, 50}, {50, 100}, {100, 200}};

    // Maps to store ADC counts by energy range
    std::map<std::pair<double, double>, int> total_adc_counts;
    std::map<std::pair<double, double>, int> non_zero_adc_counts;

    while (reader->Next()) {
        std::vector<int> primaries;

        // Example energy retrieval
        for (const auto& [trackID, t] : *track) {
            if (t.Process() == "Primary") {
                primaries.push_back(trackID);
                auto trajectory = t.Trajectory();
                if (!trajectory.empty()) {
                    auto e = trajectory[0].E();

                    int current_event = EventID_g4->Index();
                    for (const auto& [low, high] : energyRanges) {
                        if (e >= low && e < high) {
                            for (const auto& [readoutID, wave] : *waves) {
                                auto digital = wave.Digital();

                                total_adc_counts[{low, high}] += digital.size();

                                for (int value : digital) {
                                    if (value > 0) {
                                        non_zero_adc_counts[{low, high}]++;
                                    }
                                }
                            }
                            break;
                        }
                    }
                }
            }
        }
    }

    // Create histograms
    std::map<std::pair<double, double>, TH1D*> histograms;
    std::vector<int> colors = {kRed+3, kGreen, kBlue, kMagenta};
    int colorIndex = 0;

    for (const auto& range : energyRanges) {
        std::string histName = "hist_" + std::to_string(range.first) + "_" + std::to_string(range.second);
        histograms[range] = new TH1D(histName.c_str(), "Non-Zero ADC / Total ADC", 20, 0, 1000);
        histograms[range]->SetLineColor(colors[colorIndex % colors.size()]);
        ++colorIndex;
    }

    // Fill histograms with the ratio of non-zero ADC counts to total ADC counts
    for (const auto& range : energyRanges) {
        double non_zero_count = non_zero_adc_counts[range];
        double total_count = total_adc_counts[range];
        std::cout << "Total ADC Count for range " << range.first << "-" << range.second << " MeV: " << total_count << std::endl;

        //if (total_count > 0) {
        double ratio = non_zero_count / total_count;
        histograms[range]->Fill(ratio);
        //} else {
            //std::cerr << "Warning: Total count is zero for range " << range.first << " - " << range.second << " MeV." << std::endl;
        //}
    }

    // Plotting and Legend
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

