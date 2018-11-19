#ifndef DYNAMICBITMASK_H
#define DYNAMICBITMASK_H

#include "matrixCost.h"

#include <iostream>
#include <vector>

class DynamicBitmask
{
    int numberVertices;
    matrixCost * martixOrginalCost;
    std::vector<std::vector<int>> *state;
    std::vector<int> path;
    
public:

    DynamicBitmask();
    ~DynamicBitmask();

    std::vector<int> findPath(matrixCost * matrix);
    int dynamicBitMask(int currentVertex, int visited);
    void getPath(int cost, int visited);

};

#endif // DYNAMICBITMASK_H
