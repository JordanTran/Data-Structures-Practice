#include "AVLtree.h"
#include <cstdlib>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int AVLtree::height(shared_ptr<Vertex> node){
    return node == nullptr ? -1 : node->getHeight();
}
void AVLtree::balance(shared_ptr<Vertex> & node){
    if (node == nullptr){
        return;
    }
    //Left subtree violates height constraint
    if (height(node->getLeftChild()) - height(node->getRightChild()) > 1){
        if (height(node->getLeftChild()->getLeftChild()) >= height(node->getLeftChild()->getRightChild())){
            rightRotation(node);
        }
        else{
            leftRightRotation(node);
        }
    }
    //Right subtree violates height constraint
    else if (height(node->getRightChild()) - height(node->getLeftChild()) > 1){
        if (height(node->getRightChild()->getRightChild()) >= height(node->getRightChild()->getLeftChild())){
            leftRotation(node);
        }
        else{
            rightLeftRotation(node);
        }
    }
    node->setHeight(max(height(node->getLeftChild()), height(node->getRightChild()))+1);
}

void AVLtree::insertVertex(int label, shared_ptr<Vertex> & node){
    //Empty Spot
    if (node == nullptr || root == nullptr){
        node = make_shared<Vertex>(label);
        totalNodes++;
    }
    //less than node
    else if (label < node->getLabel()){
        insertVertex(label, node->getLeftChild());
    }
    //greater than node
    else if (label > node->getLabel()){
        insertVertex(label, node->getRightChild());
    }
    //restructure and set height
    balance(node);
}

void AVLtree::insertEdge(int node1, int node2){
    shared_ptr<Vertex> vertex1; 
    vertex1 = lookup(node1,root);
    shared_ptr<Vertex> vertex2;
    vertex2 = lookup(node2,root);
    if (vertex1 == nullptr){
        insertVertex(node1, root);
        vertex1 = lookup(node1,root);
    }
    if (vertex2 == nullptr){
        insertVertex(node2, root);
        vertex2 = lookup(node2,root);
    }
    vertex1->insertAdjacency(node2);
    vertex2->insertAdjacency(node1);
}

shared_ptr<Vertex> & AVLtree::lookup(int label,shared_ptr<Vertex> & node){
    if(node == nullptr){
        return node;
    }
    else if (node->getLabel() == label){
        return node;
    }
    if (label > node->getLabel()){
        return lookup(label,node->getRightChild());
    }
    return lookup(label, node->getLeftChild());
}

void AVLtree::leftRotation(shared_ptr<Vertex> & node){
    shared_ptr<Vertex> hold = node->getRightChild();
    node->getRightChild() = hold->getLeftChild();
    hold->getLeftChild() = node;
    node->setHeight(max(height(node->getLeftChild()), height(node->getRightChild()))+1);
    hold->setHeight(max(height(hold->getRightChild()),height(node))+1);
    node = hold;
}

void AVLtree::rightRotation(shared_ptr<Vertex> & node){
    shared_ptr<Vertex> hold = node->getLeftChild();
    node->getLeftChild() = hold->getRightChild();
    hold->getRightChild() = node;
    node->setHeight(max(height(node->getLeftChild()), height(node->getRightChild()))+1);
    hold->setHeight(max(height(hold->getLeftChild()),height(node))+1);
    node = hold;
}

void AVLtree::leftRightRotation(shared_ptr<Vertex> & node){
    leftRotation(node->getLeftChild());
    rightRotation(node);
}

void AVLtree::rightLeftRotation(shared_ptr<Vertex> & node){
    rightRotation(node->getRightChild());
    leftRotation(node);
}

void AVLtree::inOrder(shared_ptr<Vertex> node, int& count){
    if (node == nullptr) {
        return;
    }
    inOrder(node->getLeftChild(), count);
    if (count ==0){
        cout << node->getLabel();
        count++;
    }
    else{
        cout << " " << node->getLabel();
    }
    inOrder(node->getRightChild(), count);
}

void AVLtree::preOrder(shared_ptr<Vertex> node){
    if (node == nullptr){
        return;
    }
    if (node->getLabel() == root->getLabel()){
        cout << node->getLabel();
    }
    else{
        cout << " " << node->getLabel();
    }
    preOrder(node->getLeftChild());
    preOrder(node->getRightChild());
}
void AVLtree::adjList(shared_ptr<Vertex> node){
    if (node == nullptr){
        return;
    }
    cout << node->getLabel() << ": ";
    node->getAdjacencyList().printAdj();
    cout << endl;
    adjList(node->getLeftChild());
    adjList(node->getRightChild());
}