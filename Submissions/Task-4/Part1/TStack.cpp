//
// Created by mikae on 19.10.2026.
//

#include "TStack.h"

//1a)
//function for adding an int to the stack
//Complexity: Time O(1) | Space O(1)
    void TStack::Push(int item) {
    if (top == (MAX_SIZE - 1)) {
        cout << "can not add item: STACK OVERFLOW" << endl;
    }
    else {
        data[++top] = item;
    }
}

//function to remove the top int from the stack and does a check so it does not remove from empty stack
//Complexity: Time O(1) | Space O(1)
void TStack::Pop() {
    if (isEmpty()) {
        cout << "nothing to 'pop'" << endl;
    }
    else {
        --top;
    }
}

//function to see the int element at the top of the stack
//Complexity: Time O(1) | Space O(1)
int TStack::Peek() const {
    if (isEmpty()) {
        return -1;
    }
    else {
        return data[top];
    }
}

//function to check the stack if it contains any int values
//Complexity: Time O(1) | Space O(1)
bool TStack::isEmpty() const {
    if (top == -1) {
        return true;
    }
    else {
        return false;
    }
}