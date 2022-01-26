#ifndef AdjacencyNode_H
#define AdjacencyNode_H
#include <cstdlib>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class AdjacencyNode {
    public:
        AdjacencyNode(int number):label(number), nextNode(NULL){}
        AdjacencyNode():label(0),nextNode(NULL){}; 
        int getLabel(){return label;}
        AdjacencyNode* getNext(){return nextNode;}
        int label;
        AdjacencyNode* nextNode;
        };       
#endif