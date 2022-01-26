#ifndef Dictionary_H
#define Dictionary_H
#include <cmath>
#include <cstdlib>
#include <memory>
#include <string>
#include "hashTable.h"
#include "hash24.h"
using namespace std;
class Dictionary {
    public:
        Dictionary(string filename, string paramFileName);
        void readData(string filename, int tableSize);
        void setHashTables(string filename, int tableSize);
        Hash24 getHash() const{ return hashFunction;}
        int getTotalWords() const{ return totalWords+ duplicates;}
        int getTableSize() const{return tableSize;}
        int hashIt(string word);
        int maxCollision() const;
        void reportWords() const;
        void reportAttempts() const;
        void reportMaxCollision() const;

        bool find(string word);

        
    private:
        hashTable* hashTableArray;
        int totalWords;
        Hash24 hashFunction;
        int duplicates;
        int tableSize;
};       
#endif