//
// Created by mikae on 22.10.2026.
//
#include"WaitLine.h"

//2c)

//function to easier demonstrate how the queue works
//Complexity: Time O(n) | Space O(n)
void waitLine(int queueAmount) {
    TQueue qu;

    //people coming to the line
    for (int i = 1; i <= queueAmount; i++) {
        qu.Enqueue(i);
        cout << "Person: " << i << " arrived to the queue" << endl;
    }

    //people "getting help"
    while (!qu.isEmpty()) {
        int id = qu.Peek();
        qu.Dequeue();
        cout << "Person: " << id << " was served" << endl;
    }
}