#include "DynamicBitmask.h"

#include <iomanip>

DynamicBitmask::~DynamicBitmask()
{
    for(int i = 0; i <numberVertices; i++)
    {
        delete [] state[i];
    }
    delete [] state;
}

void DynamicBitmask::init()
{
    this->~DynamicBitmask();
    numberVertices = matrix.getNumberVertices();
    state = new int * [numberVertices];
    int tmp = 1 << (numberVertices - 1);
    for(int i = 0; i <numberVertices; i++)
    {
        state[i] = new int[tmp];
        for (int j=0; j<tmp;j++)
            state[i][j] = INT_MAX;
    }
}

const Path DynamicBitmask::findPath()
{
    int result;
    int numberSubsets = (1 << (numberVertices - 1));
    
    result = dynamicBitMask(0, numberSubsets- 1);
    
    path.push_back(0);
    getPath(result, numberSubsets - 1);
    
    return {result, std::move(path)};
}

int DynamicBitmask::dynamicBitMask(int currentVertex, int visited)
{
    if (visited == 0)
    {
        state[currentVertex][visited] = matrix.getCost(0, currentVertex);
        return matrix.getCost(0, currentVertex);
    }
        
    if (state[currentVertex][visited] != INT_MAX)
        return state[currentVertex][visited];
        
    for (int i = 1; i < numberVertices; i++)
    {
        
        if (i == currentVertex || !(visited & (1 << (i-1))))
            continue;
        int value = matrix.getCost(i, currentVertex) + dynamicBitMask(i, (visited ^ 1 << (i-1)));
        if (value < state[currentVertex][visited])
            state[currentVertex][visited] = value;
    }
    
    return state[currentVertex][visited];
}

void DynamicBitmask::getPath(int cost, int visited)
{
    // czy juz w tym wiezle znalezlismy wierzcholek
    bool flag = false; 
    int tmp;
        
    for (int i=1; i < numberVertices; i++)
    {
        if (visited & (1 << (i -1)) && !flag)
        {
            tmp =  (visited ^ (1 << (i - 1)));
            // jesli koszt podzbioru dla tego wierzcholka i koszt przejscia z niego do poprzedniego rowna sie kosztowi to sprawdzamy ten wezel
            if (state[i][tmp] + matrix.getCost(i, path.back()) == cost)
            {
                path.push_back(i);
                getPath(state[i][tmp], tmp);
                flag = true;
            }
            
        }
    }
}

