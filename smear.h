#ifndef SMEAR_H
#define SMEAR_H

#include <vector>

double gaussianDistribution(double mean, double stdev);
void applyNoise(std::vector<double>& data);
std::vector<double> readFile();
void writeFile(const std::vector<double>& data);

#endif