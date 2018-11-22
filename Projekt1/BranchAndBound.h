#ifndef BRANCHANDBOUND_H
#define BRANCHANDBOUND_H

#include "matrixCost.h"

#include <queue>
#include <iostream>
#include <algorithm>

class BranchAndBound
{
    int numberVertices;
    const matrixCost &matrix;
    
public:
    BranchAndBound(const matrixCost &orginalMatrix) : matrix(orginalMatrix) {};
    ~BranchAndBound() {};

    void init();

    bool checkRows(Node n, int j);
    bool checkColumns(Node n, int j);

    void setBound(Node &n);
    void setBoundTwo(Node &n);

    const Path findPath();
    const Path findPathTwo();
    
};

#endif // BRANCHANDBOUND_H
