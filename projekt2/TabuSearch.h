#ifndef TABUSEARCH_H
#define TABUSEARCH_H

#include <stdlib.h>
#include <chrono>
#include <algorithm>

#include "matrixCost.h"

class TabuSearch
{
    int tabuLength = 20;
    int iterationsTabuSearch = 1000;
    int numberCriticalEvent = 50;
    
    int numberVertices;
    const matrixCost &matrix;
    std::vector<std::vector<int>> tabuList;
    int bestGlobalCost;
    std::vector<int> bestGlobalPath;
    std::vector<int> listRandomVerticlesGreedy;
    
    void init();
    
    int calculateCostPath(std::vector<int> currPath);
    bool isInTabuList(int vertexA, int vertexB);
    void cleanTabuList();
    void getBestNearbySolutionOne(std::vector<int> &currPath);
    void getBestNearbySolutionTwo(std::vector<int> &currPath);
    std::vector<int> greedy(int start);
    std::vector<int> restart();
    bool criticalEvent(int iterations);
    
public:
    TabuSearch(const matrixCost &orginalMatrix) : matrix(orginalMatrix) {};
    ~TabuSearch();
    
    
    void setTabuLength(int length) {tabuLength = length;};
    int getTabuLength() {return tabuLength;};
    void setIterations(int i) {iterationsTabuSearch = i;};
    int getIterations() {return iterationsTabuSearch;};
    void setNumberCriticalEvent(int number) {numberCriticalEvent = number;};
    int getNumberCriticalEvent() {return numberCriticalEvent;};
    
    const Path searchTS(double time, char choiceNeighborhood, bool turnDiversification);
    const Path searchTSTime(double time, char choiceNeighborhood, bool turnDiversification);

};

#endif // TABUSEARCH_H
