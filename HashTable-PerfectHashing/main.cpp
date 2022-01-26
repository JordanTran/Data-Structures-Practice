#include <iostream> 
#include <memory>
#include <vector>
#include <fstream>
#include "hash24.h"
#include "hashTable.h"
#include "Dictionary.h"
using namespace std; 
int main(int argc, char *argv[]) {
    try {
		if (argc < 3 || argc > 4) 
			throw invalid_argument("Error format: a.out Paramfilename DatasetFilename QueryWords(optional)");
	} 
    catch (const invalid_argument& e)
    {
        cerr << "Error: " << e.what() << endl;
        exit(0);
    }
    string paramFilename = argv[1];
    string dataSetFilename = argv[2];
    string queryWordsFile= " ";
    if (argc == 4){
            queryWordsFile = argv[3];
    }
    Dictionary test = Dictionary(dataSetFilename, paramFilename);
    test.getHash().dump();
    cout << "Number of words = " << test.getTotalWords() << endl;
    cout << "Table size = " << test.getTableSize()<< endl;
    cout << "Max collisions = " << test.maxCollision()  << endl;
    test.reportWords();
    test.reportMaxCollision();
    test.reportAttempts();
    vector<string> words;
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
            cout  <<  "Queries:" << endl;
            for (auto & word : words){
                    if (test.find(word)){
                        cout<< word<< " found at " << test.hashIt(word) << endl;
                    }
                    else{
                        cout<< word<< " not found" << endl;
                    }
                }
        }
    }
    return 0;
}