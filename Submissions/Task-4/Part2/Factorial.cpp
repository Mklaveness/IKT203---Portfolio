//
// Created by mikae on 20.10.2026.
//
#include"Factorial.h"
#include"../Part1/TStack.h"

//2b)

//function to determine the factorial of a given number using a stack
//Complexity: Time O(n) | Space O(n)
int factorialStack(int n) {
    TStack st;
    for (int i = 2; i <= n; i++) {
        st.Push(i);
    }
    int result = 1;
    while (!st.isEmpty()) {
        result *= st.Peek();
        st.Pop();
    }
    return result;
}