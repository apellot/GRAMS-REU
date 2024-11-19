void file(const char* fileName) {
    auto file = TFile::Open(fileName);
    if (!file || file->IsZombie()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }
    file->Print();
    file->Close();
}
int main() {
    // Print the structure of each ROOT file
    //printFileStructure("gramsdetsimpl.root");
    file("gramsg4elec.root");
    //printFileStructure("gramsreadoutsimpl.root");
    //printFileStructure("gramsreadoutsimpos.root");
    //printFileStructure("gramsreadoutsimelec.root");

    return 0;
}
