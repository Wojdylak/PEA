#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include <iterator>

#include "matrixCost.h"

inline void swap(int &a, int &b)
{ int c = a; a = b; b = c; }


class BruteForce
{
    
    int weightMinPath, weightTmpPath, numberVertices;
    int *stackMinPath, *stackTmpPath;
    const matrixCost &matrix;
    
    // oblicz sciezke dla tymczasowego stosu
    int calculatePathCost();
    void bruteForce(int vertex);
    
public:
    BruteForce(const matrixCost &originalMatrix);
    ~BruteForce();
    
    void init();
    
    const PathInt findPath();

};

#endif // BRUTEFORCE_H
