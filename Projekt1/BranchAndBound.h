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
    
    /**
     * @brief znajduje najkrotrsza sciezke 
     * @param matrix Wskaznik na obiekt klasy MatrixCost ktora przechowuje graf
     * @return zwraca wektor z sciezka
     */
    std::vector<int> findPath(matrixCost * matrix);
    
    /**
     * @brief znajduje najkrotsza sciezke (algorytm Little)
     * @param matrix Wskaznik na obiekt klasy MatrixCost ktora przechowuje graf
     * @return zwraca wektor z sciezka
     */
    std::vector<int> findPathTwo(matrixCost * matrix);


};

#endif // BRANCHANDBOUND_H
