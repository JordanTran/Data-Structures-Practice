#ifndef AVLtree_H
#define AVLtree_H
#include <cstdlib>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "AdjacencyNode.h"
#include "Vertex.h"
using namespace std;
class AVLtree {
    public:
        AVLtree():root(nullptr), totalNodes(0){}

        void balance(shared_ptr<Vertex> & node);
        void insertVertex(int label,shared_ptr<Vertex> & node);
        void insertEdge(int node1, int node2);
        shared_ptr<Vertex> & lookup(int label,shared_ptr<Vertex> & node);
        void leftRotation(shared_ptr<Vertex> & node);
        void rightRotation(shared_ptr<Vertex> & node);
        void leftRightRotation(shared_ptr<Vertex> &  node);
        void rightLeftRotation(shared_ptr<Vertex> & node);
        void inOrder(shared_ptr<Vertex> node, int & count);
        void preOrder(shared_ptr<Vertex> node);
        int height(shared_ptr<Vertex> node);
        shared_ptr<Vertex> & getRoot() {return root;}
        int getTotal(){return totalNodes;}
        void adjList(shared_ptr<Vertex> node);
    private:
        shared_ptr<Vertex> root;
        int totalNodes;
        };       
#endif