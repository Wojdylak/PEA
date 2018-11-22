#include "BranchAndBound.h"


void BranchAndBound::init()
{
    numberVertices = matrix.getNumberVertices();
}

//sprawdzanie czy wchodzilismy juz do tego wierzcholka
bool BranchAndBound::checkRows(Node n, int j)
{
    for (int i = 0; i < n.level; i++){
        if (j == n.path[i])
        {
            return true;
        }
    }
    return false;
}

//sprawdzanie czy wychodzilismy z tego wierzcholka
bool BranchAndBound::checkColumns(Node n, int j)
{
    for (int i = 1; i <= n.level; i++){
        if (j == n.path[i])
        {
            return true;
        }
    }
    return false;
}

void BranchAndBound::setBound(Node &n)
{
    int min, tmp;
    n.bound = n.cost;
    
    for (int i=0; i < numberVertices; i++)
    {
        // jesli bylismy juz w jakims wierzcholku to juz go nie odwiedzamy
        if (checkRows(n, i))
            continue;
            
        min = INT_MAX;
        for (int j=0; j < numberVertices; j++)
        {
            if (checkColumns(n, j))
                continue;
                
            if (i == j)
                continue;
                
            tmp = matrix.getCost(i, j);
            if (tmp < min && tmp >= 0)
                min = tmp;
        }
        n.bound += min;
    }
}

void BranchAndBound::setBoundTwo(Node &n)
{
    int tmp = 0;
    matrixCost *matrixCopy;
    matrixCopy = matrix.clone();
    
    tmp +=  matrixCopy->reduceCostRows();
    tmp += matrixCopy->reduceCostColumns();
    
    for (int i=0; i < n.level; i++)
    {
        tmp += matrixCopy->getCost(n.path[i], n.path[i+1]);
        matrixCopy->reduceMatrix(n.path[i], n.path[i+1]);
        tmp += matrixCopy->reduceCostRows();
        tmp += matrixCopy->reduceCostColumns();
    }
    
    delete matrixCopy;
    matrixCopy = nullptr;
    n.bound = tmp;
}


const Path BranchAndBound::findPath()
{
    int bestCost = 0;
    std::priority_queue<Node> queue;
    
    std::vector<int> bestPath;
    bestPath.push_back(0);
    for (int i = 1; i<numberVertices; i++)
    {
        bestPath.push_back(i);
        bestCost += matrix.getCost(i -1, i);
    }
    bestCost += matrix.getCost(numberVertices - 1,0);

    Node tmp {0, 0, 0, 0, std::vector<int>(numberVertices, 0)};
    setBound(tmp);
    
    queue.push(tmp);
    
    while (!queue.empty())
    {
        Node currentNode = queue.top();
        queue.pop();
        
        //std::cout<<currentNode.position<<" "<<currentNode.bound<<" "<<bestCost<<std::endl;
        
        if (currentNode.bound > bestCost)
            break;
            
        if (currentNode.level == numberVertices - 1)
        {
            currentNode.cost += matrix.getCost(currentNode.position, 0);
            if (currentNode.cost < bestCost)
            {
                bestCost = std::move(currentNode.cost);
                bestPath = std::move(currentNode.path);
            }
        }
        
        for (int i = 1; i < numberVertices; ++i)
        {
            if (find(currentNode.path.begin(), currentNode.path.end(), i) != currentNode.path.end() ||
            i == currentNode.position ||
            (currentNode.cost + matrix.getCost(currentNode.position, i)) > bestCost )
                continue;
                
                
            currentNode.path[currentNode.level + 1] = i;
            tmp = {i, 0, currentNode.cost + matrix.getCost(currentNode.position, i), currentNode.level + 1, currentNode.path};
            setBound(tmp);
            queue.push(tmp);
        }
    } // end while
    
    return {std::move(bestCost), std::move(bestPath)};
}

const Path BranchAndBound::findPathTwo()
{
    int bestCost = 0;
    std::priority_queue<Node> queue;
    
    std::vector<int> bestPath;
    bestPath.push_back(0);
    for (int i = 1; i<numberVertices; i++)
    {
        bestPath.push_back(i);
        bestCost += matrix.getCost(i -1, i);
    }
    bestCost += matrix.getCost(numberVertices - 1,0);

    Node tmp {0, 0, 0, 0, std::vector<int>(numberVertices, 0)};
    setBoundTwo(tmp);
    
    queue.push(tmp);
    
    while (!queue.empty())
    {
        Node currentNode = queue.top();
        queue.pop();
        
        //std::cout<<currentNode.position<<" "<<currentNode.bound<<" "<<bestCost<<std::endl;
        
        if (currentNode.bound > bestCost)
            break;
            
        if (currentNode.level == numberVertices - 1)
        {
            currentNode.cost += matrix.getCost(currentNode.position, 0);
            if (currentNode.cost < bestCost)
            {
                bestCost = std::move(currentNode.cost);
                bestPath = std::move(currentNode.path);
            }
        }
        
        for (int i = 1; i < numberVertices; ++i)
        {
            if (find(currentNode.path.begin(), currentNode.path.end(), i) != currentNode.path.end() ||
            i == currentNode.position ||
            (currentNode.cost + matrix.getCost(currentNode.position, i)) > bestCost )
                continue;
                
                
            currentNode.path[currentNode.level + 1] = i;
            tmp = {i, 0, currentNode.cost + matrix.getCost(currentNode.position, i), currentNode.level + 1, currentNode.path};
            setBoundTwo(tmp);
            queue.push(tmp);
        }
    } // end while
    
    return {std::move(bestCost), std::move(bestPath)};
}