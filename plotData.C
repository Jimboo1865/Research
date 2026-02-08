# include <iostream>
# include <fstream>
# include <vector>
# include <algorithm>

std::vector<double> readFile() {
    double x;
    std::vector<double> result;
    std::ifstream inFile;
    inFile.open("output.out");
    while (inFile >> x) {
        result.push_back(x);
    }
    inFile.close();
    return result;
}
void plotData() {
    int bins = 500;
    std::vector<double> data = readFile();
    double max = *std::max_element(data.begin(), data.end()) - 1;
    double min = *std::min_element(data.begin(), data.end()) + 1;
    TH1D *hist = new TH1D("hist", "Title;X-Axis;Counts", bins, min, max);
    for (const auto& val : data) {
        hist->Fill(val);
    }
    hist->SetFillColor(kBlue-7);
    TCanvas *c1 = new TCanvas();
    hist->Draw();
    c1->SaveAs("histogram.png");
}