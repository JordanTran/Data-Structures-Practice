#ifndef AdjList_H
#define AdjList_H
#include <cstdlib>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "AdjacencyNode.h"
class AdjacencyList {
    private:
        AdjacencyNode* head;
    public:
        AdjacencyList() { head = NULL; }
        AdjacencyNode* getHead(){return head;}
        void insertNode(int data){
            AdjacencyNode* newNode = new AdjacencyNode(data);
            if (head == NULL) {
                head = newNode;
                return;
            }
            AdjacencyNode* temp = head;
            while (temp->nextNode != NULL) {
                temp = temp->nextNode;
            }
            temp->nextNode = newNode;
            }
        void printAdj(){
            AdjacencyNode* temp = head;
            while (temp->nextNode != NULL) {
                cout << temp->getLabel() << " ";
                temp = temp->nextNode;
            }
            cout << temp->getLabel() << " ";
        }

};      
#endif