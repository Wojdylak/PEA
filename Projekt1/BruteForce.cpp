#include "BruteForce.h"

BruteForce::BruteForce(const matrixCost &originalMatrix)  : matrix(originalMatrix)
{
    numberVertices = matrix.getNumberVertices();
    stackMinPath = new int[numberVertices];
    stackTmpPath = new int[numberVertices]; 
}

BruteForce::~BruteForce()
{
    if (this->stackMinPath) 
        delete [] this->stackMinPath;
    if (this->stackTmpPath)
        delete [] this->stackTmpPath;
}

int BruteForce::calculatePathCost()
{
    int result=0;
    for (int i=0; i<numberVertices - 1; i++)
    {
        result += matrix.getCost(stackTmpPath[i], stackTmpPath[i+1]);
    }
    result += matrix.getCost(stackTmpPath[numberVertices-1], 0);
    return result;
}

void BruteForce::bruteForce(int vertex)
{
    if (vertex < numberVertices - 1)
    {
        for (int i = vertex; i<numberVertices; i++)
        {
            swap(stackTmpPath[vertex], stackTmpPath[i]);
            bruteForce(vertex+1);
            swap(stackTmpPath[vertex], stackTmpPath[i]);
        }
    }
    else 
    {
        weightTmpPath = calculatePathCost();
        if (weightTmpPath < weightMinPath)
        {
            weightMinPath = weightTmpPath;
            std::copy(stackTmpPath, stackTmpPath + numberVertices, stackMinPath);
        }
    }
}


// zwraca wskaznik na tablice
// pierwszy element waga sciezki 
// drugi ilosc elementow sciezki, i nastepne to sciezka
int * BruteForce::findPath()
{
    for (int i=0; i < numberVertices; i++)
    {
        stackMinPath[i] = i;
        stackTmpPath[i] = i; 
    }
    int *result = new int[this->numberVertices + 3];
    
    weightMinPath = calculatePathCost();
    bruteForce(1);
    
    result[0] = this->weightMinPath;
    result[1] = this->numberVertices + 1;
    std::copy(this->stackMinPath, this->stackMinPath + this->numberVertices, &result[2]);
    result[this->numberVertices + 2] = 0;

    return result;
}



