#include "TFile.h"
#include "TTree.h"
#include "TH2D.h"
#include "TCanvas.h"

void drawHistogram() {
    // Open the ROOT file for reading
    TFile *file = new TFile("tree_file.root", "READ");

    // Get the TTree from the file
    TTree *tree = dynamic_cast<TTree*>(file->Get("tree"));

    if (!tree) {
        std::cerr << "Error: Tree not found in the file." << std::endl;
        return;
    }

    // Create a 2D histogram (TH2D) to fill with px and py data
    TH2D *histogram = new TH2D("px_py_histogram", "Momentum Distribution;px;py", 100, -0.1, 0.1, 100, -0.1, 0.1);

    // Define the number of events (N)
    Long64_t N = tree->GetEntries();

    // Fill the histogram with data from the TTree
    for (Long64_t i = 0; i < N; i++) {
        tree->GetEntry(i);

        // Fill the histogram with px and py values
        histogram->Fill(obj.px, obj.py);
    }

    // Create a canvas to draw the histogram
    TCanvas *canvas = new TCanvas("canvas", "Canvas", 800, 600);

    // Draw the 2D histogram
    histogram->Draw("COLZ");

    // Show the canvas
    canvas->Update();
    canvas->Modified();
    canvas->Draw();

    // Close the file
    file->Close();
    delete file;
}
