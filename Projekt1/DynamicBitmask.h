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
    
public:

    DynamicBitmask();
    ~DynamicBitmask();

    int findPath(matrixCost * matrix);
    int dynamicBitMask(int currentVertex, int visited);

};

#endif // DYNAMICBITMASK_H
