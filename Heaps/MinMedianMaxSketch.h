#ifndef MinMedianMaxSketch_H
#define MinMedianMaxSketch_H
#include <cstdlib>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Heap.h"
using namespace std;
template<class T>
class MinMedianMaxSketch {
    public:
        MinMedianMaxSketch():minHeap(Heap<T>(&lessThan)), maxHeap(Heap<T>(&greaterThan)){}
        //Inserts an element in the MinMedianMaxSketch and updates the median,
        // maximum and minimum element if applicable
        void insert(T element);
        //remove an element from the MinMedianMaxSketch and update the median,
        // maximum and minimum element if applicable.
        void remove(T element);
        // take an element as a parameter and return true if
        // the element is present in the MinMedianMaxSketch, else it will return false
        bool search(T element);
        // rebalance Heaps
        void reBalance();
        //set Median
        void setMedian();
        //set Minumum
        void setMinimum();
        //set Maximum
        void setMaximum();
        //return the median element from the elements stored
        T get_median() const{return median;}
        //return the minimum element from the elements stored
        T get_minimum() const{return minimum;}
        //return the maximum element from the elements stored
        T get_maximum() const{return maximum;}
        //return the number of elements stored
        int get_size() {return minHeap.get_size() + maxHeap.get_size();}
        //report heap stats
        void report();

    private:
        Heap<T> minHeap;
        Heap<T> maxHeap;
        T minimum;
        T maximum;
        T median;
};       
#endif