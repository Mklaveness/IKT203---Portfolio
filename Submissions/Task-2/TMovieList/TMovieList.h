//
// Created by mikae on 23.09.2026.
//

#ifndef LINKEDLIST_TMOVIELIST_H
#define LINKEDLIST_TMOVIELIST_H
#include"../TMovieNode/TMovieNode.h"
#include"../TMovie/TMovie.h"
#include"../FCheckMovie.h"

using namespace std;
#include<iostream>

//2.2 a class to hold the list, with a constructor that initialises the head
//and a destructor that iterates through the nodes to delete them safely

class TMovieList {
private:
    TMovieNode* head;
    TMovieNode* tail;

public:
    TMovieList();
    ~TMovieList();

    //2.5 methods for putting a new node at the start(Prepend) and end(append)
    //refactored to suit a double linkedlist
    void Append(TMovie* movie);
    void Prepend(TMovie* movie);
    
    //2.6 GetAtIndex and remove functions for the linked list
    //refactored for the doble linked list
    TMovie* GetAtIndex(int index);
    void Remove(int index);

    // bonus REVERSE method
    // manipulate the pointers not make new nodes
    void Reverse();
    void ShowList();
    TMovie* SearchFor(FCheckMovie callback, void* criteria);
};


#endif //LINKEDLIST_TMOVIELIST_H
