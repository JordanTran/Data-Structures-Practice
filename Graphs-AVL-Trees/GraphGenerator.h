#ifndef GraphGenerator_H
#define GraphGenerator_H
#include <cstdlib>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "AdjacencyNode.h"
#include "Vertex.h"
#include "AVLtree.h"

using namespace std;
class GraphGenerator {
    public:
        GraphGenerator(string filename);
        AVLtree & getTree(){return graph;}
    private:
        AVLtree graph;
};       
#endif