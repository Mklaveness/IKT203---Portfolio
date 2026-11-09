//
// Created by mikae on 12.10.2026.
//
#include"binary_recursion.h"

//2.1 power calculation
//Time: O(log n) | Space: O(log n)
int power(int base, int exponent) {
    //base case
    if (exponent == 0) {
        return 1;
    }

    //the calculation if exponent is even
    if ((exponent % 2) == 0) {
        int half = power(base, exponent/2);
        return half * half;
    }

    //calculation if exponent is odd
    else if ((exponent % 2) != 0) {
        int half = power(base, exponent/2);
        return base * half * half;
    }
}

//2.2 Fibonacci sequence
//Time: O(2^n) | Space: O(n)

//the issue with this solution is that fibonacci numbers are calculated more than necissary, in a iterativ
//solution the fibonacci numbers are not calculated more than necissary and a better time and space complexity
//iterativ solution: Time O(n) | Space O(1)
int fibonacci(int n) {
    //base cases o and 1
    if (n == 0) {
        return 0;
    }

    if (n==1) {
        return 1;
    }

    //recursive call
    return fibonacci(n-1) + fibonacci(n-2);
}


//2.3 count occurences of a character in a string
//Time: O(n^2) | Space: O(n^2)
int countOccurrences(string s, char c) {
    //counter for occurences
    int count = 0;
    //base case
    if (s == "") {
        return 0;
    }
    //check front of string for the char
    if (s[0] == c) {
        count ++;
    }
    //cutoff the front letter
    string bufferS = s.substr(1);

    //recursive call
    return count + countOccurrences(bufferS, c);
}