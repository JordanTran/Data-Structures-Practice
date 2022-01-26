#ifndef Heap_H
#define Heap_H
#include <cstdlib>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
template<class T>
class Heap {
    public:
        Heap(bool (*comparison)(T first,T second)):myHeap(std::vector<T>(2)), size(0), comparisonFcn(comparison){}
        //return the size of the heap and the complexity of this method
        int get_size() {return size;}
        // return the value stored in the root of the binary heap
        int get_root() {return myHeap[1];}
        //insert an element in the binary heap
        void insert(T element);
        //search for an element in the heap and remove it
        void remove(T element);
        //return the value of the root and remove it from the binary heap
        T extract_root();
        //search the heap and return the minimum element from the heap
        T get_min();
        //search the heap and return the maximum element from the heap
        T get_max();
        //return true if the element is present in the heap, else it will return false
        bool search(T element);
        //
        void percolateDown(int hole);

        void report();


    private:
        std::vector<T> myHeap;
        //indicates heap type
        bool (*comparisonFcn)(T first,T second);
        int size;
};       
#endif
template<class T>
bool lessThan(T a, T b);
template<class T>
bool greaterThan(T a , T b);