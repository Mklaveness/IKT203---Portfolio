//
// Created by mikae on 04.11.2026.
//

#ifndef ALGORITHMIC_ORGANIZER_TNODE_H
#define ALGORITHMIC_ORGANIZER_TNODE_H

#include<iostream>
using namespace std;

// REUSED CODE FROM TASK 5 : "Simple Search"

template <typename T>
class TNode {
private:
    T* data;
    TNode<T>* next;

public:
    //constructor
    TNode(T* d);

    //getter to retrive next node in list
    TNode<T>* GetNext();
    T* GetData();


    //set next
    void SetNext(TNode<T>* node);
    //sett data
    void SetData(T* d);
};

template <typename T>
TNode<T>::TNode(T* d) : data(d), next(nullptr){}

template <typename T>
TNode<T>* TNode<T>::GetNext() { return next;}

template <typename T>
T* TNode<T>::GetData(){return data;}

template <typename T>
void TNode<T>::SetNext(TNode<T>* node){next = node;}

template <typename T>
void TNode<T>::SetData(T* d) {
    data = d;
}

#endif //ALGORITHMIC_ORGANIZER_TNODE_H
