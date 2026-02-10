#include "smear.h"
#include <iostream>
#include <random>
#include <fstream>

double gaussianDistribution(double mean, double stdev) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::normal_distribution<double> d(mean, stdev);
    return d(gen);
}

std::vector<double> readFile() {
    double x;
    std::vector<double> results;
    std::ifstream inFile("input.in");
    while (inFile >> x) {
        results.push_back(x);
    }
    inFile.close();
    return results;
}

void applyNoise(std::vector<double>& data) {
    for (double& value : data) {
        if (value == 0.0) value += gaussianDistribution(0.0, 0.1);
        else value *= (1.0 + gaussianDistribution(0.0, 0.1));
    }
}

void writeFile(const std::vector<double>& data) {
    std::ofstream outFile("output.out");
    for (const double& value : data) {
        outFile << value << std::endl;
    }
    outFile.close();
}