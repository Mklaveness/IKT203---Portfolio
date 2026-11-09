//
// Created by mikae on 04.11.2026.
//

#ifndef ALGORITHMIC_ORGANIZER_TLINKEDLIST_H
#define ALGORITHMIC_ORGANIZER_TLINKEDLIST_H


#include<iostream>
#include<chrono>
using namespace std;

#include"../TNode/TNode.h"

//REUSED CODE FROM TASK 5 : "Simple Search"

template <typename T>
class TLinkedList {
private:
    TNode<T>* head;
    TNode<T>* tail;
    //a boolean to determine wether the list can delete the TBankAccount to delete object safely
    bool ownsData;

public:
    //1b) constructor that sets value
    TLinkedList(bool ownsData);
    //1c) destructor
    ~TLinkedList();

    void Append(T* object);
    T* GetAtIndex(int index);

    void Remove(int index);

    void ShowList();

    //check if list is empty
    bool IsEmpty();

    //getter to get head
    TNode<T>* GetHead();

    void SetHead(TNode<T>* H);
    void SetTail(TNode<T>* T);
};

template <typename T>
TNode<T>* TLinkedList<T>::GetHead() {
    return head;
}

template <typename T>
void TLinkedList<T>::SetTail(TNode<T>* T) {
    tail = T;
}

template <typename T>
void TLinkedList<T>::SetHead(TNode<T>* H) {
    head = H;
}

//1b)
template <typename T>
TLinkedList<T>::TLinkedList(bool ownsData) : head(nullptr), ownsData(ownsData), tail(nullptr){}


//constructor that deletes if the list owns
//1c)
template <typename T>
TLinkedList<T>::~TLinkedList() {
    TNode<T>* current = head;
    while (current != nullptr) {
        TNode<T>* next = current->GetNext();
        if (ownsData) {
            delete current->GetData();
        }
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}

//not a spesific task but make adding elements to list easier
template <typename T>
void TLinkedList<T>::Append(T* object) {
    TNode<T>* newNode = new TNode<T>(object);

    //empty list check
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->SetNext(newNode);
    tail = newNode;
}

//not a spesific task
template <typename T>
T* TLinkedList<T>::GetAtIndex(int index) {
    if (index < 0) {
        return nullptr;
    }
    TNode<T>* current = head;

    for (int i = 0; i < index && current != nullptr; i++) {
        current = current->GetNext();
    }

    if (current == nullptr) {
        return nullptr;
    }

    return current->GetData();
}

//again not a spesific task but implemented for testing
template <typename T>
void TLinkedList<T>::Remove(int index) {
    if (index < 0 || head == nullptr) {
        return;
    }

    TNode<T>* deleteNode = nullptr;

    if (index == 0) {
        deleteNode = head;
        head = head->GetNext();
    }
    else {
        TNode<T>* prev = head;
        for (int i = 0; i < index-1 && prev != nullptr; i++) {
            prev = prev->GetNext();
        }

        if (prev == nullptr || prev->GetNext() == nullptr) {
            return;
        }

        deleteNode = prev->GetNext();
        prev->SetNext(deleteNode->GetNext());
    }
    if (ownsData) {
        delete deleteNode->GetData();
    }
    delete deleteNode;
}

//altso not a spesific task but made it easier to debug be seeing the list
template <typename T>
void TLinkedList<T>::ShowList() {
    TNode<T>* current = head;
    if (IsEmpty()) {
        cout << "No elements in list" << endl;
        return;
    }

    while (current != nullptr) {
        cout << *current->GetData() << endl;
        current = current->GetNext();
    }
}


//helping method to avoid checking if empty every time
template <typename T>
bool TLinkedList<T>::IsEmpty() {
    if (head == nullptr) {
        return true;
    }
    else {
        return false;
    }
}


#endif //ALGORITHMIC_ORGANIZER_TLINKEDLIST_H
