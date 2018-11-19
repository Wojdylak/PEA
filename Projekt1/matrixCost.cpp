#include "matrixCost.h"

matrixCost::matrixCost()
{
    this->numberVertices = 0;
    this->arrayVertices = nullptr;
    this->flagGood = false;
}

matrixCost::matrixCost(int number)
{
    this->flagGood = false;
    this->init(number);
}

matrixCost::matrixCost(const matrixCost& obj)
{
    int n = obj.numberVertices;
    this->init(n);

    for (int i=0; i<n; i++)
    {
        std::copy(&obj.arrayVertices[i][0], &obj.arrayVertices[i][n], &this->arrayVertices[i][0]);
    }

}

matrixCost::~matrixCost()
{
    for(int i = 0; i < this->numberVertices; i++)
    {
        delete [] this->arrayVertices[i];
    }
    delete [] this->arrayVertices;
}

void matrixCost::init(int number)
{
    this->numberVertices = number;
        
    this->arrayVertices = new int * [number];
    for(int i = 0; i <number; i++)
    {
        this->arrayVertices[i] = new int[number];
    }
}

void matrixCost::setInfinity()
{
    for (int i=0; i<this->numberVertices; i++)
    {
        this->arrayVertices[i][i] = -1;
    }
}

void matrixCost::setZero()
{
    for (int i=0; i<this->numberVertices; i++)
    {
        this->arrayVertices[i][i] = 0;
    }
}


int matrixCost::getNumberVertices() const
{
    return this->numberVertices;
}

int matrixCost::getCost(int i, int j) const
{
    return this->arrayVertices[i][j];
}

int matrixCost::reduceCostRows()
{
    int lowCost=0, min;
    
    for (int i=0; i<this->numberVertices; i++)
    {
        min = INT_MAX;
        for (int j=0; j<this->numberVertices; j++)
        {
            if (this->arrayVertices[i][j] >= 0 && this->arrayVertices[i][j] < min)
                min = this->arrayVertices[i][j];
        }
        
        if (min > 0 && min != INT_MAX)
        {
            lowCost += min;
            for (int j=0; j < this->numberVertices; j++)
            {
                if (this->arrayVertices[i][j] >= 0)
                    this->arrayVertices[i][j] -= min;
            }
        }
    }
    return lowCost;
}

int matrixCost::reduceCostColumns()
{
    int lowCost=0, min;
    
    for (int i=0; i<this->numberVertices; i++)
    {
        min = INT_MAX;
        for (int j=0; j<this->numberVertices; j++)
        {
            if (this->arrayVertices[j][i] >= 0 && this->arrayVertices[j][i] < min)
                min = this->arrayVertices[j][i];
        }
        
        if (min > 0 && min != INT_MAX)
        {
            lowCost += min;
            for (int j=0; j < this->numberVertices; j++)
            {
                if (this->arrayVertices[j][i] >= 0)
                    this->arrayVertices[j][i] -= min;
            }
        }
    }
    return lowCost;
}

void matrixCost::reduceMatrix(int row, int column)
{
    for (int i=0; i<this->numberVertices; i++)
    {
        this->arrayVertices[i][column] = -1;
        this->arrayVertices[row][i] = -1;
    }
    
    this->arrayVertices[column][row] = -1;
}

bool matrixCost::fileReadLine(std::ifstream &input, int size, int numberRow)
{
    std::string s;
    std::getline(input, s);
    
    if(input.fail() || s.empty())
        return false;
        
    std::istringstream in_ss(s);
    
    for (int i = 0; i < size; i++)
    {
        in_ss >> arrayVertices[numberRow][i];
        if(in_ss.fail())
            return (false);
    }
    
    return true;
}

bool matrixCost::loadFile(char* path)
{
    int number;
    this->flagGood = false;
    std::ifstream input(path, std::ios::in);
    
	if (input.good())
	{
        input >> number;
        // po wczytaniu wyczysc linie
        input.ignore(INT_MAX, '\n');

        if(input.fail())
        {
            input.close();
            return false;
        }
        // usuwa i tworzy nowa macierz
        this->~matrixCost();
        this->init(number);
        for (int i=0; i<number; i++)
        {
            // jesli wczytalo zle to koniec 
            if (!fileReadLine(input, number, i))
            {
                input.close();
                return false;
            }
        }
		input.close();
        this->setInfinity();
        this->flagGood = true;
        return true;
	}
    
    return false;
}

void matrixCost::generateRandom(int number)
{
    this->~matrixCost();
    this->init(number);
    
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            if (i == j)
                this->arrayVertices[i][j] = -1;
            else
                this->arrayVertices[i][j] = rand() %100;
        }
    }
    this->flagGood = true;
}


void matrixCost::show()
{
    this->setZero();
    for (int i=0; i<this->numberVertices; i++)
    {
        for (int j=0; j<this->numberVertices; j++)
        {
            std::cout<<std::setw(3)<<this->arrayVertices[i][j]<<"  ";
        }
        std::cout<<"\n";
    }
    this->setInfinity();
}

bool matrixCost::isGood()
{
    return this->flagGood;
}

matrixCost* matrixCost::clone() const
{
    return new matrixCost(*this);
}