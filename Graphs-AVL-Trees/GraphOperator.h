#ifndef GraphOperator_H
#define GraphOperator_H
#include <cstdlib>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "AdjacencyNode.h"
#include "Vertex.h"
#include "AVLtree.h"
#include "GraphGenerator.h"
#include <map>
using namespace std;
class GraphOperator {
    private:
        bool *visited;
        map<int, vector<int>> components;
        GraphGenerator graph;
        int numberComponents;
    public:
        GraphOperator(GraphGenerator gr):graph(gr), numberComponents(0){
            visited = new bool[graph.getTree().getTotal()+1];
            //numberComponents = new int[graph.getTree().getTotal()+1];
        }
        void BFS(shared_ptr<Vertex> & node);
        void resetVisited();
        void ConnectedComponents(shared_ptr<Vertex> & node);
        bool IsAcyclic(shared_ptr<Vertex> &  node);
        bool DFSCycle(shared_ptr<Vertex> & node, int ancestor);
        void printComponents();
};       
#endif