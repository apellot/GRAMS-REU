void adc_counts() {  
     auto myFile = TFile::Open("gramsdetsimpl.root");
     auto tree = myFile->Get<TTree>("DetSim");

     // Declare that the gramsg4 tree is a friend to the DetSim tree.
     tree->AddFriend("gramsg4","gramsg4pl.root");
     tree->AddFriend("ReadoutSim", "gramsreadoutsimpl.root");
     tree->AddFriend("ElecSim", "gramselecsimpl.root");

     // Define the TTreeReader for this combined tree.
     auto reader = new TTreeReader(tree);
     //bin size should be the same as the amount of wire strips for the readout  
     TH1D* hist = new TH1D("hist", "ADC Counts",1050,0,1050);
     TH1D* hist2 = new TH1D("hist2", "G4 energy/readout Energy",50,0,25);
     TCanvas* canvas = new TCanvas("canvas","hist",800,800);

     //read in the different classes that you need information from
     TTreeReaderValue<grams::EventID>   EventID  (*reader, "DetSim.EventID");
     TTreeReaderValue<grams::EventID>   EventID_g4  (*reader, "gramsg4.EventID");
     TTreeReaderValue<grams::ElectronClusters> clusters(*reader, "ElectronClusters");
     TTreeReaderValue<grams::ReadoutMap> readout(*reader, "ReadoutMap");

     TTreeReaderValue<grams::MCTrackList> track(*reader, "gramsg4.TrackList");
     TTreeReaderValue<grams::MCLArHits> track_lar(*reader, "gramsg4.LArHits");
     TTreeReaderValue<grams::ReadoutWaveforms> waves(*reader, "ReadoutWaveforms");

     std::vector<int> adc;
     std::vector<int> indices;

     while(reader->Next()) {
	  if(*EventID == grams::EventID(0,5000)) {

             for(const auto& [readoutID, wave]: *waves) {
                auto digital = wave.Digital();
	        //std::cout << "ADC counts: " << digital << std::endl;
                //auto sumADC = std::accumulate( digital.cbegin(), digital.cend(), 0 );
		//if(sumADC > 0) {
                //  adc.push_back(sumADC);
		//  indices.push_back(adc.size() - 1);
		//  std::cout << "adc counts: " << adc << std::endl;
		//}
                for (const auto& num : digital) {
                    //if (num != 0.0) { // Optionally filter out zero values
                       adc.push_back(num);
                       indices.push_back(adc.size() - 1);
                    //}
                }		
             }
	  }
     }
     for(size_t i =0; i < adc.size(); i++) {
        hist->Fill(adc[i]);
     }

    // Create a scatter plot using TGraph
    TGraph* scatterPlot = new TGraph(adc.size(), indices.data(), adc.data());
    scatterPlot->SetTitle("ADC Scatter Plot;Index;ADC Sum");
    scatterPlot->SetMarkerStyle(20); // Set marker style
    scatterPlot->SetMarkerColor(kBlue); // Set marker color

    //canvas->Divide(1, 2); // Divide the canvas into 1x2 sections
    canvas->cd(); // Go to the first section
    //hist->SetStats(kFALSE);
    gPad->SetLogy();
    hist->Draw();
    //canvas->cd(2); // Go to the second section
    //scatterPlot->Draw("AP");	
}
