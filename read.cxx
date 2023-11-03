#include "TFile.h"
#include "TTree.h"
#include "your_class.h" 

void read() {
    // Initialize your object
    your_class obj;

    // Open your file 
    TFile *file = new TFile("tree_file.root", "READ");

    // Get you tree
    TTree *tree = dynamic_cast<TTree*>(file->Get("tree"));  // Assuming the tree is named "tree"

    if (!tree) {
        std::cerr << "Error: Tree not found in the file." << std::endl;
        return;
    }

    // Remember to set the branch address
    tree->SetBranchAddress("px", &obj.px);
    tree->SetBranchAddress("py", &obj.py);
    tree->SetBranchAddress("pz", &obj.pz);

    // Define the number of events (N)
    Long64_t N = tree->GetEntries();

    // Loop over the entire tree
    for (Long64_t i = 0; i < N; i++) {
        // Get the entry for the current event
        tree->GetEntry(i);

        // Now you can access the data in the 'obj' instance
        // For example, you can calculate the magnitude of the momentum
        Double_t magnitude = obj.Magnitude();

        // Do something with the data, e.g., print it
        std::cout << "Event " << i << ": Magnitude = " << magnitude << std::endl;
    }

    // Close the file
    file->Close();
    delete file;  
}
