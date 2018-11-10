#include "BranchAndBound.h"

BranchAndBound::BranchAndBound()
{
    this->martixOrginalCost = nullptr;
    
}

BranchAndBound::~BranchAndBound()
{
    if (this->martixOrginalCost)
        delete this->martixOrginalCost;
}

//sprawdzanie czy byliśmy juz w danym wierzcholku
bool BranchAndBound::checkRows(Node *n, int j)
{
    for (int i = 0; i < n->path.size() - 1; i++){
        if (j == n->path[i])
        {
            return true;
        }
    }
    return false;
}

//sprawdzanie czy bylismy juz w danym wierzcholku
bool BranchAndBound::checkColumns(Node *n, int j)
{
    for (int i = 1; i < n->path.size(); i++){
        if (j == n->path[i])
        {
            return true;
        }
    }
    return false;
}

int BranchAndBound::getValue(Node *n)
{
    int value = 0;
    
    for (int i=0; i < n->path.size()-1; i++)
    {
        value += this->martixOrginalCost->getCost(n->path[i], n->path[i+1]);
    }
    return value;
}

void BranchAndBound::setBound(Node *n)
{
    int min,tmp;
    n->bound = getValue(n);
    
    for (int i=0; i<this->numberVertices; i++)
    {
        // jesli bylismy juz w jakims wierzcholku to juz go nie odwiedzamy
        if (this->checkRows(n, i)){
            continue;
        }
        min = INT_MAX;
        for (int j=0; j<this->numberVertices; j++)
        {
            if (this->checkColumns(n, j)){
                continue;
            }
            
            if (i == j){
                continue;
            }
            
            tmp = martixOrginalCost->getCost(i, j);
            if (tmp < min && tmp >= 0){
                min = tmp;
            }
        }
        n->bound += min;
    }
}

void BranchAndBound::setBoundTwo(Node *n)
{
    int tmp = 0;
    this->matrixCopyCost = this->martixOrginalCost->clone();
    
    tmp +=  this->matrixCopyCost->reduceCostRows();
    tmp += this->matrixCopyCost->reduceCostColumns();
    
    for (int i=0; i<n->path.size()-1; i++)
    {
        tmp += this->matrixCopyCost->getCost(n->path[i], n->path[i+1]);
        this->matrixCopyCost->reduceMatrix(n->path[i], n->path[i+1]);
        tmp += this->matrixCopyCost->reduceCostRows();
        tmp += this->matrixCopyCost->reduceCostColumns();
    }
    
    delete this->matrixCopyCost;
    this->matrixCopyCost = nullptr;
    n->bound = tmp;
}

std::vector<int> BranchAndBound::findPath(matrixCost * matrix)
{
    this->numberVertices = matrix->getNumberVertices();
    this->martixOrginalCost = matrix->clone();
    int bestValue = INT_MAX;
    std::vector<int> tmpPath;
    std::vector<int> resultPath;
    this->checkedNode = new Node();
    
    tmpPath.push_back(0);
    this->checkedNode->level = 1; 
    this->checkedNode->path = tmpPath;
    this->setBound(this->checkedNode);
    
    
    
    queue.push(this->checkedNode);
    
    while(!queue.empty())
    {
        this->checkedNode = this->queue.top();
        this->queue.pop();
     
   
        if (this->checkedNode->bound < bestValue)
        {
            for (int i=1; i< this->numberVertices; i++)
            {
                if (!this->checkColumns(this->checkedNode, i))
                {
                    this->tmpNode = new Node();
                    this->tmpNode->path = this->checkedNode->path;
                    this->tmpNode->path.push_back(i);
                    this->tmpNode->level = this->checkedNode->level +1;
                    this->setBound(this->tmpNode);
                    
                    if (this->tmpNode->level == this->numberVertices)
                    {
                        this->tmpNode->path.push_back(0);
                        this->setBound(this->tmpNode);
                        if (this->tmpNode->bound < bestValue)
                        {
                            bestValue = this->tmpNode->bound;
                            resultPath = this->tmpNode->path;
                        }
                    }
                    
                    if (this->tmpNode->bound < bestValue)
                    {
                        queue.push(this->tmpNode);
                    }
                    else
                        delete this->tmpNode;
                    this->tmpNode = nullptr;
                }
            }
        }
        delete this->checkedNode;
        this->checkedNode = nullptr;
    } //end while
    
    resultPath.push_back(bestValue);
    
    delete this->martixOrginalCost;
    this->martixOrginalCost = nullptr;
    
    return resultPath;
    
}

std::vector<int> BranchAndBound::findPathTwo(matrixCost * matrix)
{
//    std::cout<<1<<std::endl;
    this->numberVertices = matrix->getNumberVertices();
    this->martixOrginalCost = matrix->clone();
    int bestValue = INT_MAX;
    std::vector<int> tmpPath;
    std::vector<int> resultPath;
    this->checkedNode = new Node();
    
    
//    std::cout<<2<<std::endl;
    
    tmpPath.push_back(0);
    this->checkedNode->level = 1; 
    this->checkedNode->path = tmpPath;
    this->setBoundTwo(this->checkedNode);

    queue.push(this->checkedNode);
    
    while(!queue.empty())
    {
        this->checkedNode = this->queue.top();
        this->queue.pop();
     
        if (bestValue != INT_MAX)
            std::cout<<bestValue<<std::endl;
        
        std::cout<<std::endl;
     
        if (this->checkedNode->bound < bestValue)
        {
            for (int i=1; i< this->numberVertices; i++)
            {
                if (!this->checkColumns(this->checkedNode, i))
                {
                    this->tmpNode = new Node();
                    this->tmpNode->path = this->checkedNode->path;
                    this->tmpNode->path.push_back(i);
                    this->tmpNode->level = this->checkedNode->level +1;
                    this->setBoundTwo(this->tmpNode);
                    
                    if (this->tmpNode->level == this->numberVertices)
                    {
                        this->tmpNode->path.push_back(0);
                        this->setBound(this->tmpNode);
                        if (this->tmpNode->bound < bestValue)
                        {
                            bestValue = this->tmpNode->bound;
                            resultPath = this->tmpNode->path;
                        }
                    }
                    
                    if (this->tmpNode->bound < bestValue)
                    {
                        queue.push(this->tmpNode);
                    }
                    else
                        delete this->tmpNode;
                    this->tmpNode = nullptr;
                }
            }
            
            
        }
        delete this->checkedNode;
        this->checkedNode = nullptr;
    } //end while
    
    resultPath.push_back(bestValue);
    
    delete this->martixOrginalCost;
    this->martixOrginalCost = nullptr;
    
    return resultPath;
}
//*/