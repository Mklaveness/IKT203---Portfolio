//
// Created by mikae on 23.09.2026.
//

#include "TMovieList.h"
#include<iostream>

//constructor that initialises the head and tail of the linked list
//also links them togheter
TMovieList::TMovieList() {
    head = new TMovieNode(nullptr);
    tail = new TMovieNode(nullptr);

    head->SetNext(tail);
    tail->SetPrevious(head);
}

//destructor iterates through the list and deletes nodes
//aswell as the TMovie objects stored in the node
TMovieList::~TMovieList() {
    TMovieNode* current = head;
    while (current != nullptr) {
        TMovieNode* next = current->GetNext();
        delete current;
        current = next;
    }
}

//ads a new movie to the end of the list
//with a tail pointer allows the method to preform at a O(1) time.
void TMovieList::Append(TMovie* movie) {
    TMovieNode* current = tail->GetPrevious();
    TMovieNode* newNode = new TMovieNode(movie);

    current->SetNext(newNode);
    newNode->SetPrevious(current);
    newNode->SetNext(tail);
    tail->SetPrevious(newNode);
}

//ads a new movie to start of the list
void TMovieList::Prepend(TMovie* movie) {
    TMovieNode* current = head->GetNext();
    TMovieNode* newNode = new TMovieNode(movie);

    newNode->SetNext(current);
    newNode->SetPrevious(head);
    head->SetNext(newNode);
    current->SetPrevious(newNode);
}

//returns a movie from the list based on a given index
//returns nullptr if the index is not valid or "out of bounds"
TMovie* TMovieList::GetAtIndex(int index) {
    if (index < 0) {
        return nullptr;
    }
    TMovieNode* current = head->GetNext();

    for (int i = 0; i < index && current != tail; i++) {
        current = current->GetNext();
    }

    if (current == tail) {
        return nullptr;
    }
    return current->GetData();
}

//removes the node from the list at a given index
//the methods adjusts pointers before deleting the node
void TMovieList::Remove(int index) {
    TMovieNode* current = head->GetNext();

    if (index < 0) {
        return;
    }

    for (int i = 0; i < index && current != tail; i++) {
        current = current->GetNext();
    }

    if (current == tail) {
        return;
    }

    TMovieNode* deleteNode = current;

    current->GetPrevious()->SetNext(current->GetNext());
    current->GetNext()->SetPrevious(current->GetPrevious());


    delete deleteNode;
}

//bonus: reverses the order of the list in-place without creating temporary nodes.
//each node swaps its pointers before the head and tail

void TMovieList::Reverse() {
    TMovieNode* current = head->GetNext();

    //nothing to reverse
    if (current == tail) {
        return;
    }
    for (int i = 0; current != tail; i++) {
        TMovieNode* next = current->GetNext();
        TMovieNode* previous = current->GetPrevious();

        current->SetNext(previous);
        current->SetPrevious(next);

        current = next;
    }

    TMovieNode* first = tail->GetPrevious();
    TMovieNode* last = head->GetNext();

    head->SetNext(first);
    first->SetPrevious(head);

    tail->SetPrevious(last);
    last->SetNext(tail);
}

//a display function that iterates the list and prints the name of the movie to the terminal
//not a task, but made it simpler to display and debug
void TMovieList::ShowList() {
    TMovieNode* current = head->GetNext();
    for (int i = 0; current != tail; i++) {
        TMovie* movie = current->GetData();
        if (current->GetNext() == tail) {
            cout << movie->GetTitle() << endl;
        }
        else {
            cout << movie->GetTitle() << " --- > ";
        }
        current = current->GetNext();
    }
}

//search for a movie that matches a given criteria
//the callback functions determines the criteria
TMovie* TMovieList::SearchFor(FCheckMovie callback, void* criteria) {
    TMovieNode* current = head->GetNext();

    while (current != tail) {
        if (callback(current->GetData(), criteria)) {
            return current->GetData();
        }
        current = current->GetNext();
    }
    return nullptr;
}