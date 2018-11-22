#include <iostream>
#include <ctime>
#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

#include "MyFunctions.h"
#include "matrixCost.h"
#include "BruteForce.h"
#include "branchAndBound.h"
#include "DynamicBitmask.h"

using namespace std;

void MyMenu();

int main()
{
    srand(time(NULL));

    MyMenu();
    
	return 0;
}


void MyMenu()
{
    matrixCost * matrix = nullptr;
    matrix = new matrixCost();
    
    BruteForce tspBruteForce(*matrix);
    BranchAndBound tspBranchAndBound(*matrix);
    DynamicBitmask tspDynamicBitmask(*matrix);
    
    PathInt pathInt;
    Path path;

    int inNumber;
    char choice;
    bool loop1;
    string filePath;
    
    cout<<INTRO<<endl;
    
    loop1 = true;
    while (loop1)
    {
        cout<<MAIN_MENU;
        //get choice
        choice = getchar();
        
        switch (choice)
        {
            case '1':
            {
                cout << "Podaj ilosc miast: ";
                cin >> inNumber;
                matrix->generateRandom(inNumber);
                break;
            } // end case 1
            case '2':
            {
                cout<< "Podaj sciezke: ";
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cin>>filePath;
                if (matrix->loadFile(&filePath[0]))
                    cout<<"Wczytano poprawnie"<<endl;
                else
                    cout<<"Error"<<endl;
                break;
            } // end case 2
            case '3':
            {
                if (matrix->isGood())
                {
                    matrix->show();
                }
                else
                    cout<<"Nie ma macierzy "<<endl;
                break;
            } // end case 3
            case '4':
            {
                if (matrix->isGood())
                {
                    tspBruteForce.init();
                    pathInt = tspBruteForce.findPath();
                    
                    cout<<pathInt.cost<<endl;
                    for (int i=0; i<matrix->getNumberVertices(); i++)
                        cout << pathInt.path[i] << " - ";
                    cout<<"0"<<endl;
                }
                else
                    cout<<"Nie ma macierzy "<<endl;
                break;
            } // end case 4
            case '5':
            {
                if (matrix->isGood())
                {
                    tspBranchAndBound.init();
                    path = tspBranchAndBound.findPath();
                    cout << path.cost<< endl;
                    for (auto& el : path.path ) {
                        cout << el << " - ";
                    }
                    cout<<"0"<<endl;
                }
                else
                    cout<<"Nie ma macierzy "<<endl;
                break;
            } // end case 5
            case '6':
            {
                if (matrix->isGood())
                {
                    tspBranchAndBound.init();
                    path = tspBranchAndBound.findPathTwo();
                    cout << path.cost<< endl;
                    for (auto& el : path.path ) {
                        cout << el << " - ";
                    }
                    cout<<"0"<<endl;
                }
                else
                    cout<<"Nie ma macierzy "<<endl;
                break;
            } // end case 6
            case '7':
            {
                if (matrix->isGood())
                {
                    tspDynamicBitmask.init();
                    path = tspDynamicBitmask.findPath();
                    cout << path.cost<< endl;
                    for (auto& el : path.path ) {
                        cout << el << " - ";
                    }
                    cout<<"0"<<endl;
                }
                else
                    cout<<"Nie ma macierzy "<<endl;
                break;
            } // end case 7
            case '0':
                loop1 = false;
            break;
            
            default:
                break;
        } // end switch
        
        cout<<endl<<endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    } // end loop1
}



