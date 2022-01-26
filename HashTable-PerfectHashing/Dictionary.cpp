#include "hashTable.h"
#include "hash24.h"
#include "Dictionary.h"
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

Dictionary::Dictionary(string filename, string paramFileName){
    vector<unsigned long long int> params;
    std::ifstream paramFile(paramFileName);
    if(!paramFile.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    if(paramFile.good()) {
        string variable;
        while(std::getline(paramFile, variable)){
            params.push_back(stoll(variable));
        }
    }
    paramFile.close();
    hashFunction = Hash24(params[1],params[2],params[3]);
    tableSize = params[0];
    hashTableArray = new hashTable[params[0]];
    totalWords = 0;
    readData(filename, params[0]);
    setHashTables(filename, params[0]);
}

void Dictionary::readData(string filename, int tableSize){
    std::ifstream myFile(filename);
    if(!myFile.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    if(myFile.good()) {
        string line;
        unsigned long long int hashIndex;
        while(std::getline(myFile, line)){
            hashIndex = hashFunction.hash(line) % (tableSize);
            hashTableArray[hashIndex].incWords();
        }
    }
    myFile.close();
    for (unsigned int i = 0; i < tableSize; i++){
        if (hashTableArray[i].getTotalWords() != 0){
            hashTableArray[i].setArray();
        }
    }
}

void Dictionary::setHashTables(string filename, int tableSize){
    std::ifstream myFile(filename);
    if(!myFile.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    if(myFile.good()) {
        string line;
        unsigned long long int hashIndex;
        while(std::getline(myFile, line)){
            hashIndex = hashFunction.hash(line) % (tableSize);
            if (hashTableArray[hashIndex].addElement(line) == true){
                totalWords++;;
            }
            else{
                duplicates++;
            }
        }
    }
    myFile.close();
}

int Dictionary::maxCollision() const{
    int maxCol = 0;
    for (unsigned int i = 0; i <  tableSize; i++){
            if (hashTableArray[i].getTotalWords() > maxCol){
                maxCol = hashTableArray[i].getTotalWords();
            }   
        }
    return maxCol;
}

void Dictionary::reportWords() const{
    int numberOfWords = 0;
    for( int j = 0 ; j< 21 ; j++){
        for (unsigned int i = 0; i < tableSize; i++){
            if (hashTableArray[i].getTotalWords() == j){
                numberOfWords++;
            }
        }
        cout << "# of primary slots with "<< j <<" words = " <<  numberOfWords << endl;
        numberOfWords = 0;
    }
}

void Dictionary::reportAttempts() const{
    int numberOfattempts = 0;
    int totalAttempts = 0;
    int totalHashTables = 0;
    cout << "Number of hash functions tried:" << endl;
    for( int j = 1 ; j< 21 ; j++){
        for (unsigned int i = 0; i < tableSize; i++){
            if (hashTableArray[i].getTotalWords() != 0 && hashTableArray[i].getAttempts() == j){
                numberOfattempts++;
                totalHashTables++;
                totalAttempts +=j;
            }
        }
        cout << "# of secondary hash tables trying "<< j <<" hash functions = "<< numberOfattempts<< endl;
        numberOfattempts = 0;
    }
    cout << "Average # of hash functions tried = "<< float(totalAttempts) / float(totalHashTables) << endl;
}

void Dictionary::reportMaxCollision() const{
    int index = 0;
    int maxCol = maxCollision();
    while(hashTableArray[index].getTotalWords() != maxCol){
        index++;
    }
    cout << "** Words in the slot with most collisions ***"<<endl;
    hashTableArray[index].printElements();
}

bool Dictionary::find(string word){
    int firstIndex = hashFunction.hash(word) % tableSize;
    if (hashTableArray[firstIndex].getTotalWords() != 0){
        int secondIndex = hashTableArray[firstIndex].getHash().hash(word) % (hashTableArray[firstIndex].getTotalWords() * hashTableArray[firstIndex].getTotalWords());
        if (hashTableArray[firstIndex].getWordArray()[secondIndex] == word){
            return true;
        }
    }
    return false;
}

int Dictionary::hashIt(string word){
    return hashFunction.hash(word) % tableSize;
}