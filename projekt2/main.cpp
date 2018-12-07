#include <iostream>
#include <ctime>

#include "matrixCost.h"
#include "SimulatedAnnealing.h"
#include "TabuSearch.h"
#include "MyFunctions.h"

using namespace std;

void MyMenu();

int main()
{
    srand(time(NULL));
	
    matrixCost *obj;
    obj = new matrixCost();
    
    if (obj->loadFile("tsp_17.txt"))
        obj->show();
    
	return 0;
}


