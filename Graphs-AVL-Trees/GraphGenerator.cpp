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
#include <sstream>
using namespace std;
    
    
GraphGenerator::GraphGenerator(string filename){
    std::ifstream myFile(filename);
    if(!myFile.is_open()) {
         throw std::runtime_error("Could not open file");
    }
    string line;
    string node1;
    string node2;
    if(myFile.good()) {
        while(std::getline(myFile, line)){ 
            std::stringstream ss(line);
            std::getline(ss,node1,',');
            std::getline(ss,node2,',');
            if (node1 != "" && node2 != ""){
                graph.insertEdge(stoi(node1) , stoi(node2));
            }
        }
    }
}
