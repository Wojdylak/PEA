#ifndef MATRIXCOST_H
#define MATRIXCOST_H

#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <vector>

struct PathInt{
    int cost;
    int *path;
};

struct Path{
    int cost;
    std::vector<int> path;
};

struct Node{
    int position;
    int bound;
    int cost;
    int level;
    std::vector<int> path;
    bool operator<(const Node& rhs) const
    {
        return bound > rhs.bound;
    }
};


class matrixCost
{
    int numberVertices;
    int ** arrayVertices;
    bool flagGood;
    
    void init(int number);
    bool fileReadLine(std::ifstream &input, int size, int numberRow);
    void setInfinity();
    void setZero();
    
    
public:
    matrixCost();
    matrixCost(int number);
    matrixCost(const matrixCost& obj);
    ~matrixCost();
    
    int getNumberVertices() const;
    int getCost(int i, int j) const;
    int reduceCostRows();
    int reduceCostColumns();
    void reduceMatrix(int row, int column);
    
    bool loadFile(char* path);
    void generateRandom(int number);
    void show();
    bool isGood();
    
    matrixCost * clone() const;
};

#endif // MATRIXCOST_H
