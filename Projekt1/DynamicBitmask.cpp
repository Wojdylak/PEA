#include "DynamicBitmask.h"

#include <iomanip>

DynamicBitmask::DynamicBitmask()
{
    this->martixOrginalCost = nullptr;
    this->state = nullptr;
}

DynamicBitmask::~DynamicBitmask()
{
    this->path.clear();
    if (this->martixOrginalCost)
        delete this->martixOrginalCost;

}

std::vector<int> DynamicBitmask::findPath(matrixCost *matrix)
{
    int result;
    this->numberVertices = matrix->getNumberVertices();
    this->martixOrginalCost = matrix->clone();
    int numberSubsets = (1 << this->numberVertices - 1);
    std::vector<int> tmp;
    
    this->state = new std::vector<std::vector<int>>(this->numberVertices);
    for (auto& el : *state)
        el = std::vector<int>(numberSubsets,INT_MAX);
    
    result = dynamicBitMask(0, numberSubsets- 1);
    
    this->path.clear();
    this->path.push_back(0);
    this->getPath(result, numberSubsets - 1);
    this->path.push_back(result);
    
    while (!(*state).empty())
    {
        tmp = (*state).back();
        (*state).pop_back();
        tmp.clear();
    }

    
    return path;
}

int DynamicBitmask::dynamicBitMask(int currentVertex, int visited)
{
    if (visited == 0)
    {
        (*state)[currentVertex][visited] = this->martixOrginalCost->getCost(0, currentVertex);
        return this->martixOrginalCost->getCost(0, currentVertex);
    }
        
    if ((*state)[currentVertex][visited] != INT_MAX)
        return (*state)[currentVertex][visited];
        
    for (int i = 1; i < this->numberVertices; i++)
    {
        
        if (i == currentVertex || !(visited & (1 << i-1)))
            continue;
        int value = this->martixOrginalCost->getCost(i, currentVertex) + dynamicBitMask(i, (visited ^ 1 << i-1));
        if (value < (*state)[currentVertex][visited])
            (*state)[currentVertex][visited] = value;
    }
    
    return (*state)[currentVertex][visited];
}

void DynamicBitmask::getPath(int cost, int visited)
{
    // czy juz w tym wiezle znalezlismy wierzcholek
    bool flag = false; 
    int tmp;
    if (!visited)
        this->path.push_back(0);
        
    for (int i=1; i < this->numberVertices; i++)
    {
        if (visited & (1 << i -1) && !flag)
        {
            tmp =  (visited ^ (1 << i - 1));
            // jesli koszt podzbioru dla tego wierzcholka i koszt przejscia z niego do poprzedniego rowna sie kosztowi to sprawdzamy ten wezel
            if ((*state)[i][tmp] + this->martixOrginalCost->getCost(i, this->path.back()) == cost)
            {
                this->path.push_back(i);
                this->getPath((*state)[i][tmp], tmp);
                flag = true;
            }
            
        }
    }
}

