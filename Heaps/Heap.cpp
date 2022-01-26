#include "Heap.h"
#include <cstdlib>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
template<class T>
void Heap<T>::insert(T element){
    if(get_size() == myHeap.size()-1){
        myHeap.resize(myHeap.size()*2);
    }
    int hole = get_size() + 1;
    T copy = element;
    myHeap[0] = copy;
    for(; comparisonFcn(element, myHeap[hole/2]); hole/=2){
        myHeap[hole] = myHeap[hole/2];
    }
    myHeap[hole] = myHeap[0];
    size++;
}
template<class T>
void Heap<T>::percolateDown(int hole){
    int childIndex;
    T temp = std::move(myHeap[hole]);
    for(;hole*2 <= get_size(); hole = childIndex){
        childIndex = hole * 2;
        if (childIndex != get_size() && comparisonFcn(myHeap[childIndex+1],myHeap[childIndex])){
            childIndex++;
        }
        if (comparisonFcn(myHeap[childIndex], temp)){
            myHeap[hole] = std::move(myHeap[childIndex]);
        }
        else
            break;
    }
    myHeap[hole] = std::move(temp);
}
template<class T>
void Heap<T>::remove(T element){
    int hole = 0;
    for (const auto data: myHeap){
        hole++;
        if (hole != 0 && element == data){
            break;
        }
    }
    if (!(hole == get_size() && myHeap[hole] != element)){
        myHeap[hole] = myHeap[size];
        size--;
        cout<< hole << endl;
        percolateDown(hole);
    }
}

template<class T>
T Heap<T>::extract_root(){
    T root = get_root();
    myHeap[1] = std::move(myHeap[size--]);
    percolateDown(1);
    return root;
}

template<class T>
T Heap<T>::get_min(){
    int index = 0;
    if (comparisonFcn(0,1) == true){
        return get_root();
    }
    T min = get_root();
    for (const auto data: myHeap){
        if (index < 100){
            //cout << index << " :  "<< data<< endl;
        }
        if (index != 0 && index < size && comparisonFcn(min, data)){
            min = data;
        }
        index++;
    }
    return min;

}

template<class T>
T Heap<T>::get_max(){
    int index = 0;
    if (comparisonFcn(1,0) == true){
        return get_root();
    }
    T max = get_root();
    for (const auto data: myHeap){
        if (index < 100){
            //cout <<index << " :  "<< data<< endl;
        }
        if (index != 0 && index < size && comparisonFcn(max, data)){
            max = data;
        }
        index++;
    }
    return max;

}

template<class T>
bool Heap<T>::search(T element){
    for (const auto data: myHeap){
        if (data == element){
            return true;
        }
    }
    return false;
}

template<class T>
bool lessThan(T a, T b)
{
    return a < b;
}
template<class T>
bool greaterThan(T a , T b)
{
    return a > b;
}
template<class T>
void Heap<T>::report(){
    int index = 0;
    for (const auto data:myHeap){
        if (index < 100){
            cout << index << ": " <<  data << endl;
        }
        index ++;
    }
}
template bool lessThan<int>(int,int);
template bool lessThan<float>(float,float);
template bool greaterThan<int>(int,int);
template bool greaterThan<float>(float,float);
template class Heap<float>;
template class Heap<int>;