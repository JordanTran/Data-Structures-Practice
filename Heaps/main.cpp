#include <cstdlib>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Heap.h"
#include "MinMedianMaxSketch.h"
using namespace std;
int main(int argc, char *argv[]) {
     try {
		if (argc != 4) 
			throw invalid_argument("Error format: a.out  “heap” insertFileName removeFileName");
	} 
    catch (const invalid_argument& e)
    {
        cerr << "Error: " << e.what() << endl;
        exit(0);
    }

    //Set up
    MinMedianMaxSketch<int> testing = MinMedianMaxSketch<int>();
    string insertFilename = argv[2];
    string removeFilename = argv[3];
    Heap<int> minHeap = Heap<int>(&lessThan);
    Heap<int> maxHeap = Heap<int>(&greaterThan);
    std::ifstream myFile(insertFilename);
        if(!myFile.is_open()) {
            throw std::runtime_error("Could not open file");
        }
        if(myFile.good()) {
            string line;

            while(std::getline(myFile, line)){ 
                if (line != ""){
                    testing.insert(stoi(line));
                }              
            }
        }
    std::ifstream myFile2(removeFilename);
        if(!myFile2.is_open()) {
            throw std::runtime_error("Could not open file");
        }
        if(myFile2.good()) {
            string line;

            while(std::getline(myFile2, line)){ 
                if (line != ""){
                    testing.remove(stoi(line));
                }              
            }
        }
    testing.report();
    //maxHeap.report();
    return 0;
}