//
// Created by mikae on 12.10.2026.
//
#include"basic_recursion.h"


//1.1 Natural Numbers Recursivly
//Time: O(n) | Space: O(n)
void printNaturalNumbers(int n) {
    //base case(when should the algorithm stop)
    if (n == 0) {
        return;
    }

    //recursive call
    printNaturalNumbers(n-1);

    //print
    cout << n << endl;
}

//1.2 Factroial calculation (recursivly)
//Time: O(n) | Space: O(n)
int calculateFactorial(int n) {
    //base case
    if (n == 1 || n == 0) {
        return 1;
    }

    //recursive call
    return n * calculateFactorial(n-1);
}