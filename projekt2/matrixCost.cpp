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

int matrixCost::getNumberVertices() const
{
    return this->numberVertices;
}

int matrixCost::getCost(int i, int j) const
{
    return this->arrayVertices[i][j];
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
        this->flagGood = true;
        return true;
	}
    
    return false;
}

void matrixCost::show()
{
    for (int i=0; i<numberVertices; i++)
    {
        for (int j=0; j<numberVertices; j++)
        {
            std::cout<<std::setw(3)<<arrayVertices[i][j]<<"  ";
        }
        std::cout<<"\n";
    }
}

bool matrixCost::isGood()
{
    return flagGood;
}


