#include "BruteForce.h"

BruteForce::BruteForce(const matrixCost &originalMatrix) : matrix(originalMatrix) 
{
    stackTmpPath = nullptr;
    stackMinPath = nullptr;
}

BruteForce::~BruteForce()
{
    delete [] stackTmpPath;
    delete [] stackMinPath;
}

void BruteForce::init()
{
    this->~BruteForce();
    numberVertices = matrix.getNumberVertices();
    stackMinPath = new int[numberVertices];
    stackTmpPath = new int[numberVertices]; 
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


const PathInt BruteForce::findPath()
{
    for (int i=0; i < numberVertices; i++)
    {
        stackMinPath[i] = i;
        stackTmpPath[i] = i; 
    }
    
    weightMinPath = calculatePathCost();
    bruteForce(1);
    
    return {weightMinPath, stackMinPath};
    // maybe move(stackMinPath)
}



