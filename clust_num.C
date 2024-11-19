void clust_num(){
  // Open the first file and its tree.
  auto myFile = TFile::Open("gramsdetsimpl.root");
  auto tree = myFile->Get<TTree>("DetSim");

  // Declare that the gramsg4 tree is a friend to the DetSim tree.
  tree->AddFriend("gramsg4","gramsg4pl.root");
  tree->AddFriend("ReadoutSim", "gramsreadoutsimpl.root");

  // Define the TTreeReader for this combined tree.
  auto reader = new TTreeReader(tree);

  //read in the different classes that you need information from
  TTreeReaderValue<grams::EventID>   EventID  (*reader, "DetSim.EventID");
  TTreeReaderValue<grams::ElectronClusters> clusters(*reader, "ElectronClusters");
  TTreeReaderValue<grams::ReadoutMap> readout(*reader, "ReadoutMap");

  TTreeReaderValue<grams::MCTrackList> track(*reader, "TrackList");

  std::vector<double> time;
  std::vector<double> energy;
  std::vector<double> e_val;
  std::vector<double> evt;
  std::vector<double> cluster_num;

  // Define the specific event we're interested in
  static const auto event = grams::EventID(0, 9);

    while (reader->Next()) {
        // Check if the current event matches the specified event
        if (*EventID == event) {
            // Get the number of clusters in the current event
            auto numClusters = clusters->size();

            // Iterate over all clusters and get the start position
            for (const auto& [key, cluster] : *clusters) {
                auto start = cluster.PositionAtAnode4D();
                //std::cout << "Event " << EventID->Index()
                          //<< " has " << numClusters << " clusters, "
                          //<< "start pos: (" << start.X() << ", " << start.Y() << ", " << start.Z() << ", " << start.T() << ")" << std::endl;

                time.push_back(start.T());
                //e_val.push_back(cluster.EnergyAtAnode());
                evt.push_back(EventID->Index());
		cluster_num.push_back(cluster.HitID());
		std::cout << cluster.HitID() << std::endl;
            }

                    // Access ReadoutMap to get cluster keys to get the energy values
        for (const auto& [readoutID, clusterKeys] : *readout) {
            for (const auto& clusterKey : clusterKeys) {
                auto result = clusters->find(clusterKey);
                if (result == clusters->end()) {
                    std::cerr << "Inconsist readout->electron cluster map" << std::endl;
                    exit(EXIT_FAILURE);
                }
                auto& readoutCluster = result->second;

                // Assuming readoutCluster provides EnergyAtAnode method
                double energy_at_anode = readoutCluster.EnergyAtAnode();
                e_val.push_back(energy_at_anode);
            }
        }

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

                    }
                }
            }
        }
    }
    auto graph = new TGraph(time.size(), time.data(), cluster_num.data());
    graph->SetTitle("Number of Clusters vs Time;Time (ns);Number of Clusters");

    // Draw the TGraph
    TCanvas* canvas = new TCanvas("canvas", "Clusters vs Time", 800, 600);
    graph->Draw("ap");
    canvas->cd();
}
