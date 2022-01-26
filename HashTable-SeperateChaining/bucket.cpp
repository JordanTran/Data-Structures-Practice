#include "bucket.h"
#include <memory>
#include <string>
#include <iostream>
using namespace std;

void Bucket::addElement(string newElement){
    this->elements[this->insertIndex] = newElement;
    this->insertIndex++;
}

void Bucket::printElements(){
    for (int i =0; i < insertIndex+1; i++){
        cout << elements[i] << " ";
    }
}

bool Bucket::searchBucket(string line){
    for (int i =0; i < insertIndex+1; i++){
        if (elements[i] == line){
            return true;
        }
    }
    return false;
}

int Bucket::searchBucketIndex(string line){
    int index = -1;
    for (int i =0; i < insertIndex+1; i++){
        if (elements[i] == line){
            index = i;
        }
    }
    return index;
}