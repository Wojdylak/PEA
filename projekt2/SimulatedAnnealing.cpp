#include "SimulatedAnnealing.h"


SimulatedAnnealing::~SimulatedAnnealing()
{
}

void SimulatedAnnealing::init()
{
    numberVertices = matrix.getNumberVertices();
}

void SimulatedAnnealing::annealingTemperature()
{
    temperature *= rateTemperature;
}

void SimulatedAnnealing::setTemperature()
{
    temperature = sizeTemperature * numberVertices;
}

int SimulatedAnnealing::calculateCostPath(std::vector<int> currPath)
{
    int cost = 0;
    for (int i=0; i < currPath.size() - 1; i++)
    {
        cost += matrix.getCost(currPath[i], currPath[i+1]);
    }
    cost += matrix.getCost(currPath[currPath.size() - 1], currPath[0]);
    
    return cost;
}

void SimulatedAnnealing::doPermutation(std::vector<int> &currPath)
{
    int vertexA, vertexB;
    vertexA = rand()%numberVertices;
    
    do{
        vertexB = rand() % numberVertices;
    } while (vertexA == vertexB);

    std::swap(currPath[vertexA], currPath[vertexB]);
}

void SimulatedAnnealing::doPermutationTwo(std::vector<int> &currPath)
{
    int vertexA, vertexB;
    vertexA = rand()%numberVertices;
    
    do{
        vertexB = rand() % numberVertices;
    } while (vertexA == vertexB || vertexA + 1 == vertexB || vertexB + 1 == vertexA);

    if (vertexA < vertexB)
    {
        vertexA++;
        do
        {
            std::swap(currPath[vertexA++], currPath[vertexB--]);
        } while (vertexA < vertexB);
        
    }
    else
    {
        vertexB++;
        do
        {
            std::swap(currPath[vertexB++], currPath[vertexA--]);
        } while (vertexB < vertexA);
    }
}

double SimulatedAnnealing::probability(int deltaCost)
{
    double power = (double)deltaCost / temperature;
    double wynik = pow(M_E, power);
    return wynik;
}

const Path SimulatedAnnealing::searchSA(double time, char choiceNeighborhood = '1')
{
    init();
    setTemperature();
    
    // time
    std::chrono::steady_clock::time_point startTime, endTime; 
    double currTime;
    // path
    std::vector<int> bestLocalPath, bestGlobalPath, tmpPath;
    int bestLocalCost, bestGlobalCost, tmpCost, numberAttempts;
    
    numberAttempts = numberVertices*numberVertices/4;
    
    for (int i=0; i<numberVertices; i++) tmpPath.push_back(i);
    std::random_shuffle(tmpPath.begin(), tmpPath.end());
    
    bestGlobalCost = bestLocalCost = tmpCost = calculateCostPath(tmpPath);
    bestGlobalPath = bestLocalPath = tmpPath;
    
    
    startTime = std::chrono::steady_clock::now();
    do{
        
        for (int i=0; i < numberAttempts; i++)
        {
            switch (choiceNeighborhood)
            {
                case '1': 
                    doPermutation(tmpPath);
                    break;
                case '2':
                    doPermutationTwo(tmpPath);
                    break;
                default :
                    doPermutation(tmpPath);
            }
            tmpCost = calculateCostPath(tmpPath);

            
            if (tmpCost < bestLocalCost )
            {
                bestLocalCost = tmpCost;
                bestLocalPath = tmpPath;
                if (bestLocalCost < bestGlobalCost)
                {
                    bestGlobalCost = bestLocalCost;
                    bestGlobalPath = bestLocalPath;
                }
            }
            else if (((double)rand() / (double)RAND_MAX) < probability(-(tmpCost - bestLocalCost)) )
            {
                bestLocalCost = tmpCost;
                bestLocalPath = tmpPath;
            }            
        } // end for
        
            
        annealingTemperature();
        endTime = std::chrono::steady_clock::now();
        currTime = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
    } while (currTime < time && temperature > endTemperature);
   
    return {bestGlobalCost, std::move(bestGlobalPath), 0};
}

const Path SimulatedAnnealing::searchSATime(double time, char choiceNeighborhood)
{
    Path path;
    double currTime;
    std::chrono::steady_clock::time_point startTime, endTime; 
    startTime = std::chrono::steady_clock::now();
    path = searchSA(time, choiceNeighborhood);
    endTime = std::chrono::steady_clock::now();
    currTime = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
    
    path.time = currTime;
    
    return std::move(path);
}

