#ifndef hashTable_H
#define hashTable_H
#include <cmath>
#include <cstdlib>
#include <memory>
#include <string>
#include "hash24.h"
using namespace std;
class hashTable {
    public:
        hashTable():hashFunction(Hash24()), totalWords(0), hashAttempts(1){}

        void setArray(){
            wordArray = new string[totalWords*totalWords];
        }

        bool addElement(string newElement);

        unsigned long int getTotalWords() const{return totalWords;}
        void incWords(){ totalWords++;}
        int getAttempts() const{return hashAttempts;}
        void incAttempts(){ hashAttempts++;}
        bool reHash();
        Hash24 getHash() const{ return hashFunction;}
        void printElements() const;
        string* getWordArray() const{ return wordArray;}
        void newHash();

        bool searchBucket();

    private:
        int collisions;
        Hash24 hashFunction;
        string* wordArray;
        unsigned long int totalWords;
        unsigned long int hashAttempts;
};       
#endif