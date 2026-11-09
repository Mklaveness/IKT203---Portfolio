//
// Created by mikae on 12.10.2026.
//
#include"advanced_recursion.h"


//3: advanced binary recursion
//3.1 largest element in an array using recursion
//Time: O(n) | Space: O(log n)
int findLargestElement(int arr[], int size) {
    //base case
    if (size == 1) {
        return arr[0];
    }

    //find half for devide and conquer
    int mid = size/2;
    //find largest in "left side"
    int left = findLargestElement(arr, mid);
    //find largest in "right side"
    int right = findLargestElement(arr + mid, size - mid);

    //check which side has biggest element
    if (left > right) {
        return left;
    }
    else {
        return right;
    }
}

//ASCII table traversal
//Time: O(n) | Space: O(n)
void traverseAsciiTable(char start, char end) {

    cout << start << endl;

    int asciiStart = (int)start;
    int asciiEnd = (int)end;

    //base case
    if (asciiStart == asciiEnd) {
        return;
    }


    traverseAsciiTable((char)(asciiStart + 1), end);
    cout << start << endl;
}