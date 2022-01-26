#ifndef Vertex_H
#define Vertex_H
#include <cstdlib>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "AdjacencyNode.h"
#include "AdjacencyList.h"
using namespace std;
class Vertex {
    public:
        Vertex(int number):label(number), leftChild(nullptr), rightChild(nullptr), adjacencyList(), height(0) {}
        
        int getLabel() const{return label;}
        int getHeight() {return height;}        
        shared_ptr<Vertex> & getLeftChild() {return leftChild;}
        shared_ptr<Vertex> & getRightChild() {return rightChild;}
        AdjacencyList getAdjacencyList() {return adjacencyList;}

        void setHeight(int newHeight){height = newHeight;}
        void setLeftChild(shared_ptr<Vertex> child){leftChild = child;}
        void setRightChild(shared_ptr<Vertex> child){rightChild = child;}
        void insertAdjacency(int node){ adjacencyList.insertNode(node);}
        //void insertAdjacency(int node){adjacencyList.push_back(node);}
    private:
        int label;
        int height;
        shared_ptr<Vertex> leftChild;
        shared_ptr<Vertex> rightChild;
        //vector<int> adjacencyList;
        AdjacencyList adjacencyList;
        };       
#endif