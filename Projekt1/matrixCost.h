#ifndef MATRIXCOST_H
#define MATRIXCOST_H

class matrixCost
{
    int numberVertices;
    int ** arrayVertices;
    bool flagGood;
    
    void init(int number);
    void setInfinity();
    void setZero();
    
    
public:
    matrixCost();
    matrixCost(int number);
    matrixCost(const matrixCost& obj);
    ~matrixCost();
    
    int getNumberVertices();
    int getCost(int i, int j);
    int reduceCostRows();
    int reduceCostColumns();
    void reduceMatrix(int row, int column);
    
    bool loadFile(char* path);
    void generateRandom(int number);
    void show();
    bool isGood();
    
    matrixCost * clone() const;
};

#endif // MATRIXCOST_H
