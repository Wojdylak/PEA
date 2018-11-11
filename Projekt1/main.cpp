#include <iostream>
#include <ctime>
#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <vector>


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
    BruteForce * tspBruteForce = nullptr;
    BranchAndBound * tspBranchAndBound = nullptr;
    vector<int> tspPath;
    int * tspPathStack = nullptr;
    int inNumber;
    char choice;
    bool loop1;
    string path;
    
    
    matrix = new matrixCost();
    
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
                cin>>path;
                if (matrix->loadFile(&path[0]))
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
                    int * wsk;
                    tspBruteForce = new BruteForce();
                    tspPathStack = tspBruteForce->findPath(matrix);
                    
                    wsk = tspPathStack;
                    
                    cout<<*tspPathStack++<<endl;
                    int n = *tspPathStack++ - 1;
                    cout<<*tspPathStack++;
                    while (n--)
                    {
                        cout<<" - "<<*tspPathStack++;
                    }
                    cout<<endl;
                    tspPathStack = nullptr;
                    delete tspBruteForce;
                    delete wsk;
                }
                else
                    cout<<"Nie ma macierzy "<<endl;
                break;
            } // end case 4
            case '5':
            {
                if (matrix->isGood())
                {
                    tspBranchAndBound = new BranchAndBound();
                    tspPath = tspBranchAndBound->findPath(matrix);
                    
                    cout << tspPath[tspPath.size()-1] << endl;
                    
                    for (int i = 0; i < tspPath.size() - 1; i++) {

                    if (i != 0) std::cout << " - ";
                    std::cout << tspPath[i];
                    }
                    delete tspBranchAndBound;
                }
                else
                    cout<<"Nie ma macierzy "<<endl;
                break;
            } // end case 5
            case '6':
            {
                if (matrix->isGood())
                {
                    tspBranchAndBound = new BranchAndBound();
                    tspPath = tspBranchAndBound->findPathTwo(matrix);
                    
                    cout << tspPath[tspPath.size()-1] << endl;
                    
                    for (int i = 0; i < tspPath.size() - 1; i++) {
                        if (i != 0) std::cout << " - ";
                        std::cout << tspPath[i];
                        }
                    delete tspBranchAndBound;
                }
                else
                    cout<<"Nie ma macierzy "<<endl;
                break;
            } // end case 6
            case '7':
            {
                if (matrix->isGood())
                {
                    ;
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



