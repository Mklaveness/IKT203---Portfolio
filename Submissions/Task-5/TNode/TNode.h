//
// Created by mikae on 27.10.2026.
//

#ifndef SIMPLE_SEARCH_TNODE_H
#define SIMPLE_SEARCH_TNODE_H

#include<iostream>
using namespace std;


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
};

template <typename T>
TNode<T>::TNode(T* d) : data(d), next(nullptr){}

template <typename T>
TNode<T>* TNode<T>::GetNext() { return next;}

template <typename T>
T* TNode<T>::GetData(){return data;}

template <typename T>
void TNode<T>::SetNext(TNode<T>* node){next = node;}

#endif //SIMPLE_SEARCH_TNODE_H
