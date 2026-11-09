//
// Created by mikae on 27.10.2026.
//

#ifndef SIMPLE_SEARCH_TLINKEDLIST_H
#define SIMPLE_SEARCH_TLINKEDLIST_H

#include<iostream>
#include<chrono>
using namespace std;

#include"../TNode/TNode.h"
#include"../Search/Search.h"

//1c) Create a generic TLinkedList class that holds pointer to nodes that holds pointer to TBankaccounts
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
    //2c) find method that return pointer to first element that matches
    T* Find(FCompareAccount aOnCompare, void* searchKey, SearchSummary& summary);
    //2d)
    TLinkedList* Every(FCompareAccount aOnCompare, void* searchKey, SearchSummary& summary);

    //check if list is empty
    bool IsEmpty();

    TNode<T>* GetHead();

};


//1b)
template <typename T>
TLinkedList<T>::TLinkedList(bool ownsData) : head(nullptr), ownsData(ownsData), tail(nullptr){}

template <typename T>
TNode<T>* TLinkedList<T>::GetHead() {
    return head;
}

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

//2c) find method that returns first element that matches as well as updating the search preformance struct
template <typename T>
T* TLinkedList<T>::Find(FCompareAccount aOnCompare, void* searchKey, SearchSummary& summary) {
    auto start = chrono::steady_clock::now();

    summary.comparisons = 0;
    summary.timeSpentMs = 0.0;
    TBankAccount* result = nullptr;

    TNode<T>* current = head;
    if (head == nullptr) {
        return nullptr;
    }
    while (current != nullptr) {
        summary.comparisons++;
        if (aOnCompare(current->GetData(), searchKey)) {
            result = current->GetData();
            break;
        }
        current = current->GetNext();
    }

    auto end = chrono::steady_clock::now();
    summary.timeSpentMs = chrono::duration<double, milli>(end-start).count();

    return result;
}

//2d) Every method, that returns a new linkedlist with all elements that matches the criteria. Also updating search summary struct
template <typename T>
TLinkedList<T>* TLinkedList<T>::Every(FCompareAccount aOnCompare, void* searchKey, SearchSummary& summary) {

    //start timer
    auto start = chrono::steady_clock::now();

    //false: to avoid doulbe delete
    TLinkedList<T>* resultList = new TLinkedList<T>(false);

    summary.comparisons = 0;
    summary.timeSpentMs = 0.0;

    TNode<T>* current = head;
    if (head == nullptr) {
        return nullptr;
    }
    while (current != nullptr) {
        summary.comparisons ++;
        if (aOnCompare(current->GetData(), searchKey)) {
            resultList->Append(current->GetData());
        }
        current = current->GetNext();
    }

    //end timer
    auto end = std::chrono::steady_clock::now();
    summary.timeSpentMs = std::chrono::duration<double, std::milli>(end - start).count();

    return resultList;
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



#endif //SIMPLE_SEARCH_TLINKEDLIST_H