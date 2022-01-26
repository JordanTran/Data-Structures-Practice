#ifndef BUCKET_H
#define BUCKET_H
#include <cmath>
#include <cstdlib>
#include <memory>
#include <string>
using namespace std;
class Bucket {
    public:
  	    Bucket() : collisions(0), elements(NULL), insertIndex(0) {}

        //returns number of collisions in bucket
        int getCollisions() const{ return collisions;}
        
        //returns string array of words
        string* getElements() const{return elements;}
        
        //returns index where you'd insert new word.
        int getInsertIndex() const { return insertIndex;}

        //set number of collisions in bucket
        void setCollisions(int number_of_collisions) {collisions = number_of_collisions;} 
        
        //set string array pointer to dynamically allocated string array with given size
        void setElements(int size) { 
            elements = new string[size];
            collisions--;
        }
        
        //sets index of the index where you'd insert new word.
        void setInsertIndex(int index){insertIndex = index;}

        //add word to string array
        void addElement(string newElement);

        //free memory of word array
        void deleteElements(){delete elements;}

        //prints all words in bucket
        void printElements();

        //return True if search word is found. False if not found
        bool searchBucket(string line);

        //return index of search word if found. returns -1 if not found
        int searchBucketIndex(string line);

    private:
        string* elements;
        int collisions;
        int insertIndex;
};       
#endif