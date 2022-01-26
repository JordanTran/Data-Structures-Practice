#include <iostream> 
#include <memory>
#include <vector>
#include <fstream>
#include "hashTable.h"
#include "bucket.h"
using namespace std; 
int main(int argc, char *argv[]) {
 
    try {
		if (argc < 3 || argc > 4) 
			throw invalid_argument("Error format: a.out PCfilenamep DatasetFilename QueryWords(optional)");
	} 
    catch (const invalid_argument& e)
    {
        cerr << "Error: " << e.what() << endl;
        exit(0);
    }

    //Set up
    string pCFilename = argv[1];
    string dataSetFilename = argv[2];
    string queryWordsFile= " ";
    if (argc == 4){
            queryWordsFile = argv[3];
    }

    vector<unsigned long long int> pc;
    std::ifstream pcFile(pCFilename);
    if(!pcFile.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    if(pcFile.good()) {
        string variable;
        while(std::getline(pcFile, variable)){
            pc.push_back(stoll(variable));
        }
    }

    vector<string> words;
    int totalWords = 0;
    HashTable testHash = HashTable(pc[0]);
    //Creat Hash
    testHash.setBuckets(dataSetFilename , pc[1] , pc[0]);
    totalWords = testHash.readData(dataSetFilename , pc[1] , pc[0]);

    //Report
    cout<< "Size of input: " << totalWords << endl;
    cout << "Number of words in table: " << testHash.getNumberOfElements() << endl;
    cout << "Primary array size: " << pc[0] << endl;
    cout << "Maximum number of collisions in a hashbucket: " << testHash.maxCollisions(pc[0]) << endl;
    testHash.reportCollisions(pc[0]);
    testHash.reportMaxCollision(pc[0]);

    //Query
    if (argc == 4){
        std::ifstream myFile(queryWordsFile);
        if(!myFile.is_open()) {
            throw std::runtime_error("Could not open file");
        }
        if(myFile.good()) {
            string line;
            while(std::getline(myFile, line)){
                words.push_back(line);
            }
            cout <<endl <<  "Queries" << endl;
            for (auto & word : words){
                    testHash.query(word,pc[0]);
                }
        }
    //Testing
    //testHash.printTable(pc[0]); 

    //cout << hashString1("hello", pc[1], pc[0]); 
    //hashString1();
    //cout << endl << hashPower(4, 0, 456) << endl;
    }
    return 0;
}
