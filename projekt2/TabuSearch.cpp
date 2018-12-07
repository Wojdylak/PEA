#include "TabuSearch.h"

TabuSearch::~TabuSearch()
{
}

void TabuSearch::init()
{
    for (auto& el : tabuList)
        std::vector<int>().swap(el);
    std::vector<std::vector<int>>().swap(tabuList);
    std::vector<int>().swap(bestGlobalPath);
    std::vector<int>().swap(listRandomVerticlesGreedy);

    
    numberVertices = matrix.getNumberVertices();
    tabuList.resize(numberVertices, std::vector<int>(numberVertices, 0));
}

int TabuSearch::calculateCostPath(std::vector<int> currPath)
{
    int cost = 0;
    for (int i=0; i < currPath.size() - 1; i++)
    {
        cost += matrix.getCost(currPath[i], currPath[i+1]);
    }
    cost += matrix.getCost(currPath[currPath.size() - 1], currPath[0]);
    
    return cost;
}

bool TabuSearch::isInTabuList(int vertexA, int vertexB)
{
    if (vertexA > vertexB){
        if (tabuList[vertexA][vertexB] > 0) return true;
    }
    else{
        if (tabuList[vertexB][vertexA] > 0) return true;
    }
    return false;
}

void TabuSearch::cleanTabuList()
{
    for (auto& row : tabuList)
            for (auto& el : row)
                el = 0;
}

void TabuSearch::getBestNearbySolutionOne(std::vector<int> &currPath)
{
    bool flagIsBetterPath = false;
    int bestCost = calculateCostPath(currPath);
    int vertexA, vertexB, currCost;
    
    for (int i=1; i < numberVertices; i++)
    {
        for (int j=(i+1); j < numberVertices; j++)
        {
            std::swap(currPath[i], currPath[j]);
            currCost = calculateCostPath(currPath);
            if ((currCost < bestCost && !isInTabuList(currPath[i], currPath[j])) || currCost < bestGlobalCost)
            {
                vertexA = i; 
                vertexB = j;
                bestCost = currCost;
                flagIsBetterPath = true;
            }
            std::swap(currPath[i], currPath[j]);
        }
    }
    
    if (flagIsBetterPath)
    {
        std::swap(currPath[vertexA], currPath[vertexB]);
        if (currPath[vertexA] < currPath[vertexB]) tabuList[currPath[vertexA]][currPath[vertexB]] = tabuLength;
        if (currPath[vertexA] > currPath[vertexB]) tabuList[currPath[vertexB]][currPath[vertexA]] = tabuLength;
    }
    
}

void TabuSearch::getBestNearbySolutionTwo(std::vector<int> &currPath)
{
    bool flagIsBetterPath = false;
    int bestCost = calculateCostPath(currPath);
    int vertexA, vertexB, currCost, tmpA, tmpB;
    
    for (int i=1; i < numberVertices - 2; i++)
    {
        for (int j=(i+2); j < numberVertices; j++)
        {
            tmpA = i; tmpB = j;
            tmpA++;
            do
            {
                std::swap(currPath[tmpA++], currPath[tmpB--]);
            } while (tmpA < tmpB);
            
            currCost = calculateCostPath(currPath);
            if ((currCost < bestCost && !isInTabuList(currPath[i], currPath[j])) || currCost < bestGlobalCost)
            {
                vertexA = i; 
                vertexB = j;
                bestCost = currCost;
                flagIsBetterPath = true;
            }
            
            tmpA = i; tmpB = j;
            tmpA++;
            do
            {
                std::swap(currPath[tmpA++], currPath[tmpB--]);
            } while (tmpA < tmpB);
        }
    }
    
    if (flagIsBetterPath)
    {
        vertexA++;
        do
        {
            std::swap(currPath[vertexA++], currPath[vertexB--]);
        } while (vertexA < vertexB);
        
        if (currPath[vertexA] < currPath[vertexB]) tabuList[currPath[vertexA]][currPath[vertexB]] = tabuLength;
        if (currPath[vertexA] > currPath[vertexB]) tabuList[currPath[vertexB]][currPath[vertexA]] = tabuLength;
    }
    
}

std::vector<int> TabuSearch::greedy(int start)
{
    std::vector<int> path(numberVertices);
    bool visited[numberVertices] {false};
    int min, minNumber, tmp, cost = 0;
    
    path[0] = start;
    visited[start] = true;
    
    for (int i=1; i<numberVertices; i++)
    {
        min = INT_MAX;
        minNumber = 0;
        for (int j=0; j<numberVertices; j++)
        {
            // odwiedzony albo sam do siebie
            if (visited[j] || path[i-1] == j)
                continue;
            
            tmp = matrix.getCost(path[i-1], j);
            if (tmp < min)
            {
                min = tmp;
                minNumber = j;
            }
        }
        visited[minNumber] = true;
        path[i] = minNumber;
        cost += min;
    }
    cost += matrix.getCost(path[numberVertices-1], start);
    
    return std::move(path);
}

std::vector<int> TabuSearch::restart()
{
    std::vector<int> path;
    bool flagIsRandom;
    int randStart;
    
    if (listRandomVerticlesGreedy.size() < numberVertices)
    {
        do
        {
            flagIsRandom = false;
            randStart = rand() % numberVertices; 
            for (auto& el : listRandomVerticlesGreedy)
                if (el == randStart){
                    flagIsRandom = true;
                    break;
                }
        } while (flagIsRandom);        
        listRandomVerticlesGreedy.push_back(randStart);
        path = greedy(randStart);
    }
    else
    {
        for (int i=0; i<numberVertices; i++) path.push_back(i);
        std::random_shuffle(path.begin(), path.end());
    }
         

    return std::move(path);
}

bool TabuSearch::criticalEvent(int iterations)
{
    if (iterations < numberCriticalEvent)
        return false;
    return true;
}

const Path TabuSearch::searchTS(double time, char choiceNeighborhood = '1', bool turnDiversification = false)
{
    init();
    // time
    std::chrono::steady_clock::time_point startTime, endTime; 
    double currTime;
    // path
    std::vector<int> bestPath, currPath;
    int currCost, iterationsCriticalEvent = 0, counterIterations = 0;
    
    bestGlobalPath = currPath = restart();
    bestGlobalCost = currCost = calculateCostPath(currPath);
    
    startTime = std::chrono::steady_clock::now();
    do{
        switch (choiceNeighborhood)
            {
                case '1': 
                    getBestNearbySolutionOne(currPath);
                    break;
                case '2':
                    getBestNearbySolutionTwo(currPath);
                    break;
                default :
                    getBestNearbySolutionOne(currPath);
            }
        
        currCost = calculateCostPath(currPath);
        
        if (currCost < bestGlobalCost)
        {
            bestGlobalCost = currCost;
            bestGlobalPath = currPath;
            iterationsCriticalEvent = 0;
        }
        else 
            iterationsCriticalEvent++;
                
        for (auto& row : tabuList)
            for (auto& el : row)
                if (el > 0) el--;
        
        if (turnDiversification)
        {            
            if (criticalEvent(iterationsCriticalEvent)){
                currPath = restart();
                currCost = calculateCostPath(currPath);
                iterationsCriticalEvent = 0;
                cleanTabuList();
            }
                
            if (currCost < bestGlobalCost)
            {
                bestGlobalCost = currCost;
                bestGlobalPath = currPath;
            }
        }
        
        endTime = std::chrono::steady_clock::now();
        currTime = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
    } while (currTime < time && iterationsTabuSearch > counterIterations++);
    
    return {bestGlobalCost, std::move(bestGlobalPath), 0};
}

const Path TabuSearch::searchTSTime(double time, char choiceNeighborhood, bool turnDiversification)
{
    Path path;
    double currTime;
    std::chrono::steady_clock::time_point startTime, endTime; 
    startTime = std::chrono::steady_clock::now();
    path = searchTS(time, choiceNeighborhood, turnDiversification);
    endTime = std::chrono::steady_clock::now();
    currTime = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
    
    path.time = currTime;
    
    return std::move(path);
}