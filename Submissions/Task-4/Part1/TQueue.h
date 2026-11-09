//
// Created by mikae on 19.10.2026.
//

#ifndef STACKSANDQUES_TQUEUE_H
#define STACKSANDQUES_TQUEUE_H
#include<iostream>
using namespace std;

//1b) Create a queue class that can hold int values
class TQueue {
private:
    //Max size that can make it easier to manage the queue
    static const int MAX_SIZE = 40000;
    //array with max size
    int data[MAX_SIZE];
    //value to keep track of the index of the front value
    int front = 0;
    //value to keep track of the index of the back of the queue
    int back = -1;

public:
    //constructor that initialises the class to the set values over
    explicit TQueue() = default;

    //functions for managing the queue
    void Enqueue(int item);
    void Dequeue();
    int Peek() const;
    bool isEmpty() const;
};


#endif //STACKSANDQUES_TQUEUE_H
