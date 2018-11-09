#include <iterator>

#include "BruteForce.h"

BruteForce::BruteForce()
{
    this->stackMinPath = nullptr;
    this->stackTmpPath = nullptr;
    this->visited = nullptr;
}

BruteForce::~BruteForce()
{
    if (this->stackMinPath) 
        delete [] this->stackMinPath;
    if (this->stackTmpPath)
        delete [] this->stackTmpPath;
    if (this->visited)
        delete [] this->visited;
}

void BruteForce::bruteForce(int vertex)
{
    int tmp;
    this->stackTmpPath[this->counterVertices++] = vertex;
    this->visited[vertex] = true;
    
    if (this->counterVertices < this->numberVertices)
    {
        for (int i=1; i<this->numberVertices; i++)
        {
            if ((i != vertex) && !this->visited[i]) 
            {
                tmp = this->martixCost->getCost(vertex, i);
                this->weightTmpPath += tmp;
                this->bruteForce(i);
                this->weightTmpPath -= tmp;
            }
        }
    }
    else
    {
        tmp = this->martixCost->getCost(vertex, 0);
        this->weightTmpPath += tmp;
        if (this->weightTmpPath < this->weightMinPath)
        {
            this->weightMinPath = this->weightTmpPath;
            std::copy(this->stackTmpPath, this->stackTmpPath + this->numberVertices, this->stackMinPath);
        }
        this->weightTmpPath -= tmp;
    }
    this->counterVertices--;
    this->visited[vertex] = false;
}

int * BruteForce::findPath(matrixCost * mCost)
{
    this->martixCost = mCost;
    
    this->numberVertices = this->martixCost->getNumberVertices();
    this->weightMinPath = INT_MAX;
    this->weightTmpPath = 0;
    this->counterVertices = 0;
    this->stackMinPath = new int[this->numberVertices];
    this->stackTmpPath = new int[this->numberVertices]; 
    this->visited = new bool[this->numberVertices] {false};
    int *result = new int[this->numberVertices + 3];
    
    this->bruteForce(0);
    
    result[0] = this->weightMinPath;
    result[1] = this->numberVertices + 1;
    std::copy(this->stackMinPath, this->stackMinPath + this->numberVertices, &result[2]);
    result[this->numberVertices + 2] = 0;

    return result;
}

