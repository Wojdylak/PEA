#ifndef DYNAMICBITMASK_H
#define DYNAMICBITMASK_H

#include "matrixCost.h"

#include <iostream>
#include <vector>

class DynamicBitmask
{
    const matrixCost &matrix;
    int **state;
    int numberVertices;
    std::vector<int> path;
    
public:

    DynamicBitmask(const matrixCost &originalMatrix) : matrix(originalMatrix), state(nullptr), numberVertices(0) {};
    ~DynamicBitmask();

    void init();

    const Path findPath();
    int dynamicBitMask(int currentVertex, int visited);
    void getPath(int cost, int visited);

};

#endif // DYNAMICBITMASK_H
