//
// Created by mikae on 22.09.2026.
//

#ifndef LINKEDLIST_TMOVIENODE_H
#define LINKEDLIST_TMOVIENODE_H

#include"../TMovie/TMovie.h"
using namespace std;


//2 node that stores the pointer of an instance of TMovie and a new node.
//3 and pointer to previous node
class TMovieNode {
private:
    //pointer to the TMovie stored in this node
    TMovie* data;
    //pointer to the next node
    TMovieNode* next;
    //pointer to previous node 3.1
    TMovieNode* previous;

public:
    //constructor initialises the movie pointer and node pointers
    TMovieNode(TMovie* movie);
    //destructor deletes the TMovie object stored by the node
    ~TMovieNode();

    //Getter methods to access the next and prev pointers
    TMovieNode* GetNext();
    TMovieNode* GetPrevious();

    //setters methods to set new pointers
    void SetNext(TMovieNode* node);
    void SetPrevious(TMovieNode* node);

    //getter to retrieve the TMovie object stored in this node
    TMovie* GetData();
};

#endif //LINKEDLIST_TMOVIENODE_H
