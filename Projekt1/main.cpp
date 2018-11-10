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
    
//    int * path, *wsk;
    matrixCost * obj, * obj2;
//    BruteForce * tsp;
    BranchAndBound * tspBranchAndBound;
    vector<int> tspPath;
    
    obj = new matrixCost();
//    tsp = new tspBruteForce();
    tspBranchAndBound = new BranchAndBound();

    
    obj->loadFile("tsp_17.txt");

//    obj2 = obj->clone();
//    obj->generateRandom(5);
    
    obj->show();
//    tspBranchAndBound->findPathTwo(obj);
    
    
    tspPath = tspBranchAndBound->findPathTwo(obj);
    
    cout << tspPath[tspPath.size()-1] << endl;
    for (int i = 0; i < tspPath.size() - 1; i++) 
    {
        if (i != 0) cout << " - ";
        cout << tspPath[i];
    }
/*
    double avg;

    std::fstream input("BB1_3.txt", std::ios::out);
	if (input.good())
	{
        
        for (int i=2; i<25;i+=2)
        {
            avg =0.0;
            for (int j=0; j<100; j++)
            {
                cout<<i<<" "<<j<<endl;
                obj = new matrixCost();
                tspBranchAndBound = new BranchAndBound();
                obj->generateRandom(i);
                chrono::steady_clock::time_point start_time = chrono::steady_clock::now();
                tspBranchAndBound->findPathTwo(obj);
                chrono::steady_clock::time_point end_time = chrono::steady_clock::now();
                avg += chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
                delete tspBranchAndBound;
                delete obj;
            }
            avg /= 100;
            input<<i<<" "<<setprecision(20)<<avg<<endl;
        }
        
		input.close();
	}
*/

//    DynamicBitmask * karol;
//    karol = new DynamicBitmask;
//
//    cout<<karol->findPath(obj)<<endl;
//
//    delete karol;

//    MyMenu();

//    delete wsk;
    delete obj;
//    delete obj2;
//    delete tsp;
    delete tspBranchAndBound;



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



