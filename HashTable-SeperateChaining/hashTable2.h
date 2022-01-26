#ifndef HASH_H
#define HASH_H
#include "bucket.h"
#include <memory>
#include <string>

class HashTable {
    public:
  	    HashTable(unsigned long long int size) : bucketArray(new Bucket[size]), elements(0) {}
        
        //return pointer to Hashtable
        shared_ptr<Bucket[]> getBucketArray() const{ return bucketArray;}

        //Return number of words in hashtable
        int getNumberOfElements() const{ return elements;}

        //set bucket pointer to given array
        void setBucketArray(shared_ptr<Bucket[]> arrayOfBuckets){ bucketArray = arrayOfBuckets;}

        //insert word into hashtable
        void insertString(string insertString, unsigned long long int constant, unsigned long long int primeNumber);

        //Read in file and calculate collisions per index and 
        //initiate buckets arrays with their size being number of collisions + 1 
        void setBuckets(string fileName, unsigned long long int constant , unsigned long long int primeNumber);

        //Read in file and insert words in hashtable
        int readData(string fileName, unsigned long long int constant , unsigned long long int primeNumber);

        //calculate size for bucket
        void bucketSize(string insertString, unsigned long long int constant, unsigned long long int primeNumber);

        //Print entire Hashtable. Bucket index and all elements
        void printTable(unsigned long long int primeNumber);

        //Free memory of all allocated bucket arrays
        void deleteTable(unsigned long long int size);

        //Calculate the max collisions of bucket array
        int maxCollisions(unsigned long long int size);

        //Print list of number of elements 0-20 and how many buckets have the corresponding number of elements
        void reportCollisions(unsigned long long int size);

        //Print all keys in bucket with most colissions
        void reportMaxCollision(unsigned long long int size);

        //Prints if word is found in hashtable and its location. Returns bool if found
        bool query(string word, unsigned long long int size);

    private:
        shared_ptr<Bucket[]> bucketArray;
        int elements;

};
//Return the Hashed index of a string
unsigned long long int hashString(string insertString, unsigned long long int constant, unsigned long long int primeNumber);
int hashString1();
unsigned long long int hashPower(unsigned long long int number , unsigned long long int power , unsigned long long int modulo);
unsigned long long int hashChar(char letter , unsigned long long int constant , unsigned long long int power, unsigned long long int modulo);
#endif