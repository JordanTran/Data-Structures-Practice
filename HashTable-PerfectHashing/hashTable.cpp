#include "hashTable.h"
#include "hash24.h"
#include <memory>
#include <string>
#include <iostream>
using namespace std;

//NEEEED TO FIX! SEGMENT FAULT
bool hashTable::addElement(string newElement){
    bool success;
    int index = hashFunction.hash(newElement) % (totalWords*totalWords);
    if (wordArray[index] == ""){
        wordArray[index] = newElement;
        return true;
    }
    if (wordArray[index] == newElement){
        return false;
    }
    else{
        while (success != true){
            success = reHash();
        }
        addElement(newElement);
    }
    return false;
}

bool hashTable::reHash(){
    newHash();
    hashAttempts ++;
    int index;
    string* newWordArray = new string[totalWords*totalWords];
    for (int i =0; i < totalWords*totalWords; i++){
        if (wordArray[i] != ""){
            index = hashFunction.hash(wordArray[i]) % (totalWords*totalWords);
            newWordArray[index] = wordArray[i];
        }
    }
    if (collisions == 0){
        //delete wordArray;
        wordArray = newWordArray;
        return true;
    }
    else {
        return false;
    } 
}

void hashTable::newHash(){
    hashFunction = Hash24();
}

bool hashTable::searchBucket(){
    return true;
}

void hashTable::printElements() const{
    for (int i =0; i < totalWords*totalWords; i++){
        if (wordArray[i] != ""){
            cout << wordArray[i] << endl;
        }
    }
}