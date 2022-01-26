#include "Heap.h"
#include "MinMedianMaxSketch.h"
#include <cstdlib>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
template<class T>
void MinMedianMaxSketch<T>::insert(T element){
    //cout << median << endl;
    if (minHeap.get_size()== 0 && maxHeap.get_size()== 0){
        //cout << "equal" << endl;
        median = element;
        minimum = element;
        maximum = element;
    }
    if (element < median){
        //cout << "Max" << endl;
        maxHeap.insert(element);
    }
    else{
        minHeap.insert(element);
    }
    if (minHeap.get_size()!= 0 && maxHeap.get_size()!= 0){
        reBalance();
        setMedian();
    }
    if (element < get_minimum()){
        minimum = element;
    }
    if (element > get_maximum()){
        maximum = element;
    }
}
template<class T>
void MinMedianMaxSketch<T>::remove(T element){
    if (element <= median){
        maxHeap.remove(element);
    }
    else{
        minHeap.remove(element);
    }
    reBalance();
    setMedian();
    if (element == get_minimum()){
        setMinimum();
    }
    if (element == get_maximum()){
        setMaximum();
    }
}
template<class T>
bool MinMedianMaxSketch<T>::search(T element){
    if (element<=median){
        if(maxHeap.search(element)){
            return true;
        }
    }
    else{
        if(minHeap.search(element)){
            return true;
        }

    }
    return false;
}
template<class T>
void MinMedianMaxSketch<T>::reBalance(){
   if (abs(minHeap.get_size() - maxHeap.get_size()) >=2){
        if (minHeap.get_size()> maxHeap.get_size()){
            T x = minHeap.extract_root();
            //cout << "test" << x << endl;
            maxHeap.insert(x);
        }
        else{
            T x = maxHeap.extract_root();
            cout << "test" << endl;
            minHeap.insert(x);
        }
   }

}
template<class T>
void MinMedianMaxSketch<T>::setMedian(){
    if (minHeap.get_size() == maxHeap.get_size()){
        //cout << "eequal" << endl;
        median = maxHeap.get_root();
    }
    else{
        if (minHeap.get_size()<maxHeap.get_size()){
            //cout << "less than" << endl;
            median = maxHeap.get_root();
        }
        else{
            //cout << "greater than" << endl;
            median = minHeap.get_root();
        }
    }
}
template<class T>
void MinMedianMaxSketch<T>::setMinimum(){
   minimum = maxHeap.get_min();
}
template<class T>
void MinMedianMaxSketch<T>::setMaximum(){
    maximum = minHeap.get_max();
}
template<class T>
void MinMedianMaxSketch<T>::report(){
    maxHeap.report();
    cout << "Min Heap:" << endl;
    cout << "Size = " << minHeap.get_size() << endl;
    cout << "Min = " << minHeap.get_root() <<endl;
    cout << "Max = " << minHeap.get_max() <<endl;
    cout << "Max Heap:" << endl;
    cout << "Size = " << maxHeap.get_size() << endl;
    cout << "Min = " << maxHeap.get_min()<<endl;
    cout << "Max = " << maxHeap.get_root() <<endl;
    cout << "MinMedianMaxSketch::" << endl;
    cout << "Size = " << get_size() << endl;
    cout << "Min = " << get_minimum() <<endl;
    cout << "Max = " << get_maximum() <<endl;
    cout << "Median = " << get_median() << endl;
}

template class MinMedianMaxSketch<float>;
template class MinMedianMaxSketch<int>;