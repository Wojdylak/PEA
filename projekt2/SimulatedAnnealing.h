#ifndef SIMULATEDANNEALING_H
#define SIMULATEDANNEALING_H
#define _USE_MATH_DEFINES

#include "matrixCost.h"

#include <vector>
#include <chrono>
#include <algorithm>
#include <stdlib.h>
#include <cmath>

class SimulatedAnnealing
{
    double rateTemperature = 0.997;
    double endTemperature = 0.001;
    int sizeTemperature = 100000;
    const matrixCost &matrix;
    int numberVertices;
    double temperature;
    
    void init();
    void annealingTemperature();
    void setTemperature();
    int calculateCostPath(std::vector<int> currPath);
    void doPermutation(std::vector<int> &currPath);
    void doPermutationTwo(std::vector<int> &currPath);
    double probability(int deltaCost);
    
public:
    SimulatedAnnealing(const matrixCost &orginalMatrix) : matrix(orginalMatrix) {};
    ~SimulatedAnnealing();
    
    // for test
    void setRateTemperature(double rate) {rateTemperature = rate;};
    double getRateTemperature() {return rateTemperature;};
    void setEndTemperature(double end) {endTemperature = end;};
    double getEndTemperature() {return endTemperature;};
    void setSizeTemperature(int size) {sizeTemperature = size;};
    int getSizeTemperature() {return sizeTemperature;};
    
    const Path searchSA(double time, char choiceNeighborhood);
    const Path searchSATime(double time, char choiceNeighborhood);
    
};

#endif // SIMULATEDANNEALING_H
