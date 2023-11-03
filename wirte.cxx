#include "TFile.h"
#include "TTree.h"
#include "TMath.h"  

void write() {
    // Initialize your object (assuming your_class is the class you want to store in the TTree)
    your_class obj;

    // Create a ROOT file for writing the TTree
    TFile *file = new TFile("output.root", "RECREATE");

    // Create a TTree
    TTree *tree = new TTree("myTree", "My Tree");

    // Create branches for your TTree with meaningful names and descriptions
    // Assuming you have members in your_class like px, py, and pz
    tree->Branch("px", &obj.px, "px/F");
    tree->Branch("py", &obj.py, "py/F");
    tree->Branch("pz", &obj.pz, "pz/F");

    // Define the number of events (nEvents)
    Int_t nEvents = 100;  // You can change this to your desired number of events

    // Create a loop to fill the tree with random data
    for (Int_t i = 0; i < nEvents; i++) {
        // Initialize your new object (your_class) for each event
        obj.px = gRandom->Gaus(0, 0.02);
        obj.py = gRandom->Gaus(0, 0.02);
        obj.pz = gRandom->Gaus(0, 0.02);

        // Fill the tree with the data for the current event
        tree->Fill();
    }

    // Write the tree to the file
    tree->Write();

    // Close the file
    file->Close();
    delete file;  // Don't forget to delete the file to avoid memory leaks
}
