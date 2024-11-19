void channel_cts() {
     auto myFile = TFile::Open("gramsdetsimpl.root");
     auto tree = myFile->Get<TTree>("DetSim");

     // Declare that the gramsg4 tree is a friend to the DetSim tree.
     tree->AddFriend("gramsg4","gramsg4pl.root");
     tree->AddFriend("ReadoutSim", "gramsreadoutsimpl.root");
     tree->AddFriend("ElecSim", "gramselecsimpl.root");

     // Define the TTreeReader for this combined tree.
     auto reader = new TTreeReader(tree);
     //bin size should be the same as the amount of wire strips for the readout  
     TH2D* hist = new TH2D("hist", "Readout Reconstruction",150,-15,15, 150,-15,15);
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
     std::map<int, double> pos_x;
     std::map<int, double> pos_y;
     std::map<int, double> e_map;

     while(reader->Next()) {
          if(*EventID == grams::EventID(0,9)) {

             for(const auto& [hitkey, cluster]: *clusters) {
                auto pos = cluster.PositionAtAnode4D();
		auto hitID = cluster.HitID();
		pos_x[hitID]+=pos.X();
		pos_y[hitID]+=pos.y();
		e_map[hitID]+=cluster.EAtAnode();
                }
             }
          }

     std::vector<double> x;
     std::vector<double>y;
     std::vector<double>energy;

     for(const auto& [hitID, pos] : pos_x) {
	x.push_back(pos);
     }
     for(const auto& [hitID, pos] : pos_y) {
	 y.push_back(pos);
     }

     for(const auto& [hitID, e] : e_map) {
         energy.push_back(e);
     }

    std::vector<bool> rowHasContent(150, false);
    std::vector<bool> x_cont(150,false); 

    for (size_t i = 0; i < x.size(); i++) {
        int ind = hist->Fill(x.at(i), y.at(i));
        hist->SetBinContent(ind, energy.at(i));
        //hist->SetPoint(i, hist->GetX()[i], hist->GetY()[i], hist->GetZ()[i], e_val.at(i));
        int colorIndex = TColor::GetColorPalette((int)(energy.at(i) * 255));
        int binY = hist->GetYaxis()->FindBin(y.at(i));
	int binX = hist->GetXaxis()->FindBin(x.at(i));
        //rowHasContent[binY-1] = true; // Note: binY is 1-based, so subtract 1	
        hist->SetLineColor(colorIndex);
        hist->SetFillColor(colorIndex);
        if (binY > 0 && binY <= 150) {
            rowHasContent[binY-1] = true; // Note: binY is 1-based, so subtract 1
        }
        if (binX > 0 && binX <= 150) {
            x_cont[binX-1] = true; // Note: binY is 1-based, so subtract 1
        }
        //std::cout << x.at(i) << " " << y.at(i) << " " << z.at(i) << " " << time.at(i) << " energy: " << e_val.at(i) << " entry: " << i << std::endl;
        //std::cout << hist->GetBin(x.at(i), y.at(i), time.at(i)) << std::endl;
        //std::cout << "bin index: " << ind << std::endl;

    }

        // Draw the histogram with color map
    canvas->SetLeftMargin(0.15); // Adjust left margin
    canvas->SetRightMargin(0.15); // Adjust right margin
    canvas->SetBottomMargin(0.15); // Adjust bottom margin
    hist->GetXaxis()->SetTitle("x position (cm)");
    hist->GetYaxis()->SetTitle("y position (cm)");
    //hist->GetXaxis()->SetTitleOffset(1.4); // Adjust X-axis title offset
    //hist->GetYaxis()->SetTitleOffset(1.4); // Adjust Y-axis title offset

    //hist->GetXaxis()->SetTitleSize(0.05); // Adjust X-axis title size
    //hist->GetYaxis()->SetTitleSize(0.05); // Adjust Y-axis title size

    //hist->GetXaxis()->SetLabelSize(0.04); // Adjust X-axis label size
    //hist->GetYaxis()->SetLabelSize(0.04); // Adjust Y-axis label size
    
    hist->SetStats(kFALSE);
    hist->Draw("COLZ");

    // Determine the range of the histogram
    double xMin = hist->GetXaxis()->GetXmin();
    double xMax = hist->GetXaxis()->GetXmax();
    double yMin = hist->GetYaxis()->GetXmin();
    double yMax = hist->GetYaxis()->GetXmax();

    // Create a grid of 150x150 (22,500 boxes)
    int nX_fine = 150;
    int nY_fine = 150;

    // Calculate bin width
    double binWidthX = (xMax - xMin) / nX_fine;
    double binWidthY = (yMax - yMin) / nY_fine;

    // Draw boxes for rows with content
    //for (int j = 0; j < nY_fine; ++j) {
    //    if (rowHasContent[j]) { // If this row has content
    //        for (int i = 0; i < nX_fine; ++i) {
    //            double xCenter = xMin + (i + 0.5) * binWidthX;
    //            double yCenter = yMin + (j + 0.5) * binWidthY;

    //            // Draw the box for this row
    //            std::unique_ptr<TBox> box = std::make_unique<TBox>(xCenter - binWidthX / 2, yCenter - binWidthY / 2, xCenter + binWidthX / 2, yCenter + binWidthY / 2);
    //            box->SetLineColor(kGray);
    //            box->SetFillColor(kGray);
    //            box->Draw();
    //        }
    //    }
    //}
    int count1 = 0;
    int count2 =0;
    // Print rows with content
    for (int j = 0; j < 150; ++j) {
        if (rowHasContent[j]) { // If this row has content
            std::cout << "Column " << j + 1 << " has content." << std::endl;
	    count1++;
        }
    }  

    for (int j = 0; j < 150; ++j) {
        if (x_cont[j]) { // If this row has content
            std::cout << "Row " << j + 1 << " has content." << std::endl;
	    count2++;
        }
    }

    // Print bins with content
    for (int i = 1; i <= nX_fine; ++i) {
        for (int j = 1; j <= nY_fine; ++j) {
            int bin = hist->GetBin(i, j);
            double binContent = hist->GetBinContent(bin);
            if (binContent > 0) {
                std::cout << "Bin (" << i << ", " << j << ") has content. Bin number: " << bin << std::endl;
            }
        }
    }
    std::cout << "x channels: " << count2 << " y channels: " << count1 << std::endl;   


    // Draw vertical grid lines for 150x150 grid
    for (int i = 1; i <= nX_fine; ++i) {  // Start at 1 to avoid drawing the axis line again
        double xPos = xMin + i * (xMax - xMin) / nX_fine;
        TLine* line = new TLine(xPos, yMin, xPos, yMax);
        line->SetLineColor(kGray);
        line->SetLineStyle(1);
        line->Draw();

        // Draw label every two lines
        if (i % 2 == 0) {
            double yLabelPos = yMax + 0.5; // Offset position to the bottom side of the canvas
            TLatex* label = new TLatex(xPos, yLabelPos, Form("%d", i));
            label->SetTextSize(0.01);
            label->SetTextAlign(32);
            label->Draw();
        }
    }

    // Draw horizontal grid lines for 150x150 grid
    for (int j = 1; j <= nY_fine; ++j) {  // Start at 1 to avoid drawing the axis line again
        double yPos = yMin + j * (yMax - yMin) / nY_fine;
        TLine* line = new TLine(xMin, yPos, xMax, yPos);
        line->SetLineColor(kGray);
        line->SetLineStyle(1);
        line->Draw();

        // Draw label every two lines
        if (j % 2 == 0) {
            double xLabelPos = xMax + 0.5; // Offset position to the right side of the canvas
            TLatex* label = new TLatex(xLabelPos, yPos, Form("%d", j));
            label->SetTextSize(0.01);
            label->SetTextAlign(12);
            label->Draw();
          
        }
    }

}     
