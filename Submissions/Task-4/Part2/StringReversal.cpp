//
// Created by mikae on 20.10.2026.
//
#include"StringReversal.h"

//2a)

//function that uses the stack class to reverse a letters in a string
//Complexity: Time O(n) | Space O(n)
string stringReversal(string x) {
    TStack st;
    for (int i = 0; i < x.size(); i++) {
        st.Push(x[i]);
    }
    string result = "";
    for (int i = 0; i < x.size(); i++) {
        result += static_cast<char>(st.Peek());
        st.Pop();
    }
    return result;
}

//The stack is a perfect tool for this task because to reverse a string you put each letter a side in the stack from
//first to last, the stack is lined up perfectly that when you take the top ones (lifo) and put them back in the string
//they make the reversed string perfectly