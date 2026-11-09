//
// Created by mikae on 19.10.2026.
//

#ifndef STACKSANDQUES_TSTACK_H
#define STACKSANDQUES_TSTACK_H
#include<iostream>
using namespace std;

//1a) create stack class that can hold int values
class TStack {
private:
    //max size to easier manage the stack
    static const int MAX_SIZE = 40000;
    //array set to max size
    int data[MAX_SIZE];
    //int to keep track of where the top int is
    int top = -1;

public:
    //constructor that sets values to ones initialised in class
    TStack() = default;

    //functions for managing the stack
    void Push(int item);
    void Pop();
    int Peek() const;
    bool isEmpty() const;
};


#endif //STACKSANDQUES_TSTACK_H
