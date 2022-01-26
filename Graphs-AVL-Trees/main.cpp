#include <cstdlib>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Vertex.h"
#include "AdjacencyNode.h"
#include "AVLtree.h"
#include "GraphGenerator.h"
#include "GraphOperator.h"
using namespace std;
int main(int argc, char *argv[]) {
     try {
		if (argc != 2) 
			throw invalid_argument("Error format: a.out insertFileName");
	} 
    catch (const invalid_argument& e)
    {
        cerr << "Error: " << e.what() << endl;
        exit(0);
    }

    //Set up
    string insertFilename = argv[1];
    GraphGenerator graph = GraphGenerator(insertFilename);
    cout << "The in order traversal:" << endl;
    int counter = 0;
    graph.getTree().inOrder(graph.getTree().getRoot(),counter);
    cout << "\nThe pre order traversal:" << endl;
    graph.getTree().preOrder(graph.getTree().getRoot());
    GraphOperator graphOP = GraphOperator(graph);
    graphOP.resetVisited();
    cout << "\nIs acyclic(Yes/No):" << endl;
    if (graphOP.IsAcyclic(graph.getTree().getRoot())){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    graphOP.resetVisited();
    cout << "Connected Components:" << endl;
    graphOP.ConnectedComponents(graph.getTree().getRoot());
    graphOP.printComponents();
    //graph.getTree().adjList(graph.getTree().getRoot());
    return 0;
}