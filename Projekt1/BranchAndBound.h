#ifndef BRANCHANDBOUND_H
#define BRANCHANDBOUND_H

#include "Node.h"
#include "matrixCost.h"

#include <queue>
#include <iostream>

class BranchAndBound
{
    int numberVertices;
    Node *checkedNode, *tmpNode;
    matrixCost * martixOrginalCost, * matrixCopyCost;
    std::priority_queue<Node*, std::vector<Node*>, comp> queue;
    
public:
    BranchAndBound();
    ~BranchAndBound();

    bool checkRows(Node *n, int j);
    bool checkColumns(Node *n, int j);
    int getValue(Node *n);
    void setBound(Node *n);
    void setBoundTwo(Node *n);
    
    std::vector<int> findPath(matrixCost * matrix);
    std::vector<int> findPathTwo(matrixCost * matrix);


};

#endif // BRANCHANDBOUND_H
