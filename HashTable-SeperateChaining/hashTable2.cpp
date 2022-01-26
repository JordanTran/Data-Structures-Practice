#include "hashTable.h"
#include "bucket.h"
#include <memory>
#include <string>
#include <math.h>
#include <fstream>
#include <iostream>
using namespace std;

unsigned long long int hashString(string insertString, unsigned long long int constant, unsigned long long int primeNumber){
    unsigned long long int hashedIndex = 0;
    for (unsigned long long int i = 0; i < insertString.length(); i++){
        //hashedIndex = hashedIndex+ (int(insertString[i]*pow(constant,i))%primeNumber);
        hashedIndex += hashChar(insertString[i], constant , i , primeNumber);
        
        
        //hashedIndex = (hashedIndex*constant + insertString[i])%primeNumber;
        //hashedIndex = (hashedIndex*constant)%primeNumber + insertString[i];
    }
    return hashedIndex%primeNumber;}

int hashString1(){
    string  word = "gahuku";
    int p = 70717;
    int c = 31147;
    int hashI = 0;
    int wordInt;
    for (int i = 0; i < 6; i++){
        hashI += hashChar(word[i], c , i , p); 
    }
    hashI = hashI%p;
    cout << hashI;
    return hashI;
}

unsigned long long int hashPower(unsigned long long int number , unsigned long long int power , unsigned long long int modulo){
    unsigned long long int hashedExp = 1;
    for (unsigned long long int i =0 ; i < power; i ++){
        hashedExp = (hashedExp*(number%modulo))%modulo; 
    }
    return hashedExp%modulo;
}
unsigned long long int hashChar(char letter , unsigned long long int constant , unsigned long long int power, unsigned long long int modulo){
    return ((unsigned long long int)(int(letter)%modulo)*hashPower(constant,power , modulo))%modulo;
}

void HashTable::insertString(string insertString, unsigned long long int constant, unsigned long long int primeNumber){
    unsigned long long int hashIndex = hashString(insertString, constant, primeNumber);
    bucketArray[hashIndex].addElement(insertString);
}

void HashTable::bucketSize(string insertString, unsigned long long int constant, unsigned long long int primeNumber){
    unsigned long long int hashIndex = hashString(insertString, constant, primeNumber);
    bucketArray[hashIndex].setCollisions(bucketArray[hashIndex].getCollisions()+1);
}

void HashTable::setBuckets(string fileName, unsigned long long int constant , unsigned long long int primeNumber){
    std::ifstream myFile(fileName);
    if(!myFile.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    if(myFile.good()) {
        string line;
        while(std::getline(myFile, line)){
            this->bucketSize(line, constant, primeNumber);
        }
    }
    myFile.close();
    for (unsigned int i = 0; i < primeNumber; i++){
        if (bucketArray[i].getInsertIndex() == 0){
            bucketArray[i].setElements(bucketArray[i].getCollisions()+1);
        }
    }
}
void HashTable::printTable(unsigned long long int primeNumber){
    for (unsigned int i = 0; i < primeNumber; i++){
        if (bucketArray[i].getInsertIndex() != 0){
            cout << i << ": " ;
            bucketArray[i].printElements();
            cout << endl;
        }
    }
    cout << "size: " << elements << endl;
}
int HashTable::readData(string fileName, unsigned long long int constant , unsigned long long int primeNumber){
    std::ifstream myFile(fileName);
    int words;
    if(!myFile.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    if(myFile.good()) {
        string line;
        while(std::getline(myFile, line)){
            words++;
            if (bucketArray[hashString(line, constant , primeNumber)].searchBucket(line) == false){
                this->insertString(line, constant, primeNumber);
                elements++;
            }
            else{
                bucketArray[hashString(line, constant , primeNumber)].setCollisions(bucketArray[hashString(line, constant , primeNumber)].getCollisions()-1);
            }
        }
    }

    myFile.close();
    return words;
}

void HashTable::deleteTable(unsigned long long int size){
    for (unsigned int i = 0; i < size; i++){
            bucketArray[i].deleteElements();
        }
}

int HashTable::maxCollisions(unsigned long long int size){
    int maxCol = 0;
    for (unsigned int i = 0; i < size; i++){
            if (bucketArray[i].getCollisions() > maxCol){
                maxCol = bucketArray[i].getCollisions();
            }   
        }
    return maxCol;
}

void HashTable::reportCollisions(unsigned long long int size){
    int numberOfBuckets = 0;
    cout << "The number of hashbuckets b with x elements:" << endl;
    for( int j = 0 ; j< 21 ; j++){
        for (unsigned int i = 0; i < size; i++){
            if (bucketArray[i].getCollisions()+1 == j){
                numberOfBuckets++;
            }
        }
        cout << "x=" << j << " : b=" << numberOfBuckets << endl;
        numberOfBuckets = 0;
    }
}

void HashTable::reportMaxCollision(unsigned long long int size){
    int index = 0;
    int maxCol = -1;
    for (unsigned int i = 0; i < size; i++){
            if (bucketArray[i].getCollisions() > maxCol){
                maxCol = bucketArray[i].getCollisions();
                index = i;
            }   
        }
    cout << "Keys in most populated bucket: ";
    bucketArray[index].printElements();
    cout << endl;
}

bool HashTable::query(string word, unsigned long long int size){
    int index = 0;
    for (unsigned int i = 0; i < size; i++){
        index = bucketArray[i].searchBucketIndex(word);
        if (index != -1){
            cout << "Key \"" << word << "\" exists at (" << i << "," << index <<")." << endl;
            return true;
        }
    }
    cout << "Key \"" << word <<"\" does not exist." << endl;
    return false;
}