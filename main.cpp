#include "smear.h"

int main() {
    std::vector<double> data = readFile();
    applyNoise(data);
    writeFile(data);
    return 0;
}