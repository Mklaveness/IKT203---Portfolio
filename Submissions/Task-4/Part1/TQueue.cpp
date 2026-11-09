//
// Created by mikae on 19.10.2026.
//

#include "TQueue.h"

//1b)

//function for putting a int value to the back of the queue
//Complexity: Time O(1) | Space O(1)
void TQueue::Enqueue(int item) {
    if (back == (MAX_SIZE - 1)) {
        cout << "could not add item: Queue full" << endl;
    }
    else {
        data[++back] = item;
    }
}

//function for removing the int at the front of the queue
//Complexity: Time O(1) | Space O(1)
void TQueue::Dequeue() {
    if (isEmpty()) {
        cout << "could not remove: Queue empty" << endl;
    }
    else {
        data[front++];
    }
}

//function for returing the front element of the queue
//Complexity: Time O(1) | Space O(1)
int TQueue::Peek() const {
    if (isEmpty()) {
        return -1;
    }
    else {
        return data[front];
    }
}

//function for seeing if queue is empty
//Complexity: Time O(1) | Space O(1)
bool TQueue::isEmpty() const {
    return front > back;
}