#include "DynamicBitmask.h"

DynamicBitmask::DynamicBitmask()
{
    this->martixOrginalCost = nullptr;
    this->state = nullptr;
}

DynamicBitmask::~DynamicBitmask()
{
    if (this->martixOrginalCost)
        delete this->martixOrginalCost;

}

int DynamicBitmask::findPath(matrixCost *matrix)
{
    int result;
    this->numberVertices = matrix->getNumberVertices();
    this->martixOrginalCost = matrix->clone();
    
    this->state = new std::vector<std::vector<int>>(this->numberVertices);
    for (auto& el : *state)
        el = std::vector<int>((1 << this->numberVertices) - 1,INT_MAX);
    
    result = dynamicBitMask(0,1);
    
    delete state;
    return result;
}

int DynamicBitmask::dynamicBitMask(int currentVertex, int visited)
{
    if (visited == ((1 << this->numberVertices)) - 1)
        return this->martixOrginalCost->getCost(currentVertex, 0);
        
    if ((*state)[currentVertex][visited] != INT_MAX)
        return (*state)[currentVertex][visited];
        
    for (int i = 1; i < this->numberVertices; i++)
    {
        
        if (i == currentVertex || (visited & (1 << i)))
            continue;
        
        int value = this->martixOrginalCost->getCost(currentVertex, i) + dynamicBitMask(i, (visited | 1 << i));
        if (value < (*state)[currentVertex][visited])
            (*state)[currentVertex][visited] = value;
    }
    return (*state)[currentVertex][visited];
}

