///*#include <fstream>
//#include <iostream>
//#include <iomanip>
//
//
//#include "TSPproblem.h"
//
//TSPproblem::TSPproblem()
//{
//}
//
//TSPproblem::~TSPproblem()
//{
///*    for(int i = 0; i < this->numberVerticle; i++)
//    {
//        delete [] this->arrayVerticles[i];
//    }
//    delete [] this->arrayVerticles;
//    
//    if (this->stackMinPath) 
//        delete [] this->stackMinPath;
//    if (this->stackTmpPath)
//        delete [] this->stackTmpPath;
//    if (this->visited)
//        delete [] this->visited;
//    */
//}   
//
//void TSPproblem::init(int n)
//{
//    this->numberVerticle = n;
//        
//    this->arrayVerticles = new int * [n];
//    for(int i = 0; i < n; i++)
//    {
//        this->arrayVerticles[i] = new int[n];
//    }
//}
//
//int * TSPproblem::bruteForce()
//{
//    this->weightMinPath = INT_MAX;
//    this->weightTmpPath = 0;
//    this->counterVerticles = 0;
//    this->stackMinPath = new int[this->numberVerticle];
//    this->stackTmpPath = new int[this->numberVerticle]; 
//    this->visited = new bool[this->numberVerticle] {false};
//    int *result = new int[this->numberVerticle + 3];
//    
//    this->bruteForceRec(0);
//    
//    result[0] = this->weightMinPath;
//    result[1] = this->numberVerticle + 1;
//    std::copy(this->stackMinPath, this->stackMinPath + this->numberVerticle, &result[2]);
//    result[this->numberVerticle + 2] = 0;
//
//    return result;
//}
//
//void TSPproblem::bruteForceRec(int v)
//{
//    this->stackTmpPath[this->counterVerticles++] = v;
//    this->visited[v] = true;
//    
//    if (this->counterVerticles < this->numberVerticle)
//    {
//        for (int i=1; i<this->numberVerticle; i++)
//        {
//            if ((i != v) && !this->visited[i]) 
//            {
//                this->weightTmpPath += this->arrayVerticles[v][i];
//                this->bruteForceRec(i);
//                this->weightTmpPath -= this->arrayVerticles[v][i];
//            }
//        }
//    }
//    else
//    {
//        this->weightTmpPath += this->arrayVerticles[v][0];
//        if (this->weightTmpPath < this->weightMinPath)
//        {
//            this->weightMinPath = this->weightTmpPath;
//            std::copy(this->stackTmpPath, this->stackTmpPath + this->numberVerticle, this->stackMinPath);
//        }
//        this->weightTmpPath -= this->arrayVerticles[v][0];
//    }
//    this->counterVerticles--;
//    this->visited[v] = false;*/
//}
//
//*/
