# include <iostream>
# include <random>
# include <fstream>
# include <vector>
# include <cmath>

double gaussianDistribution(double mean, double stdev) {
    static std::random_device rd; // Obtain a random number from hardware
    static std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    static std::normal_distribution<double> d(mean, stdev); // mean = 0.0, stddev = 0.1

    double number = d(gen);
    int finalNumber = static_cast<int>(std::round(number));
    return finalNumber;
}
int listLength() {
    int length;
    std::cout << "Enter the number of values to generate: ";
    std::cin >> length;
    return length;
}
int main() {
    int mode;
    std::ofstream outFile("input.in");
    outFile.clear();
    std::cout << "Input mode:" << std::endl;
    std::cout << "1. Generate random numbers" << std::endl;
    std::cout << "2. Constant numbers" << std::endl;
    std::cin >> mode;
    if (mode == 1) {
        int length = listLength();
        for (int i = 0; i < length; ++i) {
            outFile << gaussianDistribution(0.0, 10.0) << std::endl;
        }
    }
    else if (mode == 2) {
       int length = listLength();
       std::cout << "Enter the constant value: ";
       int constant;
       std::cin >> constant;
       for (int i = 0; i < length; ++i) {
           outFile << constant << std::endl;
       }
    }
    else {
        std::cout << "Invalid mode selected. Please choose 1 or 2." << std::endl;
        return 1;
    }
    outFile.close();
}