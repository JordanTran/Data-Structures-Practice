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
#include "GraphOperator.h"
#include <algorithm>
#include <list>
#include <map>
using namespace std;

void GraphOperator::ConnectedComponents(shared_ptr<Vertex> & node){
    if (node == nullptr){
        return;
    }
    
    ConnectedComponents(node->getLeftChild());
     if (visited[node->getLabel()] == false){
        numberComponents++;
        BFS(node);
    }
    ConnectedComponents(node->getRightChild());
}

void GraphOperator::BFS(shared_ptr<Vertex> & node) {
    list<int> queue;
    visited[node->getLabel()] = true;
    if (components.count(numberComponents)){
        components[numberComponents].push_back(node->getLabel());
    }
    else{
        components.insert(pair<int,vector<int> >(numberComponents, vector<int>()));
        components[numberComponents].push_back(node->getLabel());
    }
    queue.push_back(node->getLabel());
    AdjacencyNode* temp;
    while (!queue.empty()) {
        int currVertex = queue.front();
        queue.pop_front();
        temp = graph.getTree().lookup(currVertex, graph.getTree().getRoot())->getAdjacencyList().getHead();
        while (temp != NULL) {
            if (!visited[temp->getLabel()]) {
                visited[temp->getLabel()] = true;
                queue.push_back(temp->getLabel());
                components[numberComponents].push_back(temp->getLabel());
            }
            temp = temp->nextNode;
        }
    }
}
bool myfunction (int i,int j) { return (i<j); }
void GraphOperator::printComponents(){
    int comp = 1;
    int counting = 0;
    while(components.count(comp) > 0){
        std::sort (components[comp].begin(), components[comp].end(), myfunction);
        counting = 0;
        for (auto i: components[comp]){
            if (counting == 0){
                cout << i;
                counting++;
            }
            else{
                cout << " " << i;
            } 
        }
        cout << endl;
        comp++;
    }
}

bool GraphOperator::IsAcyclic(shared_ptr<Vertex> & node){   
    if (node == nullptr){
        return true;
    }
    if (visited[node->getLabel()] == false){
       if (DFSCycle(node, -1)){
             return false;
       }
    } 
    if (IsAcyclic(node->getLeftChild()) == false){
         return false;
    }
    if (IsAcyclic(node->getRightChild())== false){
        return false;
    }
    return true;
}


bool GraphOperator::DFSCycle(shared_ptr<Vertex> & node, int ancestor){
    visited[node->getLabel()] = true;
    AdjacencyNode* temp = node->getAdjacencyList().getHead();
    while (temp != NULL) {
        if (!visited[temp->getLabel()])
        {
           if (DFSCycle(graph.getTree().lookup(temp->getLabel(), graph.getTree().getRoot()), node->getLabel()))
              return true;
        }
        else if (temp->getLabel() != ancestor)
            return true;
        temp = temp->nextNode;
    }
    return false;
}

void GraphOperator::resetVisited(){
    for (int i =0 ; i< graph.getTree().getTotal()+1; i++){
        visited[i] = false;
    }

}