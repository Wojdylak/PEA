#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include "matrixCost.h"

class BruteForce
{
    
    int weightMinPath, weightTmpPath, counterVertices, numberVertices;
    int *stackMinPath, *stackTmpPath;
    bool * visited;
    matrixCost * martixCost;
    
    void bruteForce(int vertex);
    
public:
    BruteForce();
    ~BruteForce();
    
    int * findPath(matrixCost * mCost);

};

#endif // BRUTEFORCE_H
