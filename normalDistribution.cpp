#include <iostream>
#include <random>
#include <fstream>
# include <vector>

double gaussianDistribution(double mean, double stdev) {
    static std::random_device rd; // Obtain a random number from hardware
    static std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    static std::normal_distribution<double> d(mean, stdev); // mean = 0.0, stddev = 0.1

    double number = d(gen);
    return number;
}

std::vector<double> readFile() {
    double x;
    std::vector<double> results;
    std::ifstream inFile;
    inFile.open("input.in");
    while (inFile >> x) {
        results.push_back(x);
    }
    inFile.close();
    return results;
}

void applyNoise(std::vector<double>& data) {
    for (double& value : data) {
        value += gaussianDistribution(0.0, 0.1);
    }
}
void writeFile(const std::vector<double>& data) {
    std::ofstream outFile("output.out");
    for (const double& value : data) {
        outFile << value << std::endl;
    }
    outFile.close();
}

int main() {
    std::vector<double> data = readFile();
    applyNoise(data);
    writeFile(data);
    return 0;
}