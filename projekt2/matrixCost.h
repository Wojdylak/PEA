#ifndef MATRIXCOST_H
#define MATRIXCOST_H

#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <vector>

struct Path{
    int cost;
    std::vector<int> path;
    double time;
};

class matrixCost
{
    int numberVertices;
    int ** arrayVertices;
    bool flagGood;
    
    void init(int number);
    bool fileReadLine(std::ifstream &input, int size, int numberRow);
    
public:
    matrixCost();
    matrixCost(int number);
    matrixCost(const matrixCost& obj);
    ~matrixCost();
    
    int getNumberVertices() const;
    int getCost(int i, int j) const;
    
    bool loadFile(char* path);
    void show();
    bool isGood();
    
};

#endif // MATRIXCOST_H
