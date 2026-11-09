#include <iostream>
using namespace std;

//includes for the functions in the task
#include"Part 1/basic_recursion.h"
#include"Part 2/binary_recursion.h"
#include"Part 3/advanced_recursion.h"

//note to self
//linear recursion: function that calls on itself one time/p time, linear because amount of recursive call grows linearly N
//example: sum(n) and returns when 0, and calls it self -1. then n=10 will conclude in 10 recursive calls.


int main() {
    //test 1.1 natrual numbers recursivly
    cout << "recursive call: " << endl;
    printNaturalNumbers(7);

    //test 1.2 factorial calculation recusivly
    cout << "\nfactorial call: " << endl;
    cout << calculateFactorial(2);

    //test 2.1 power calculation
    cout << "\npower calculation: " << endl;
    cout << power(2, 0);

    //test 2.2 fibonacci series
    cout << "\nFibonacci sequence: " << endl;
    cout << fibonacci(10);

    //test 2.3 count occurences of a character in a string
    cout << "\nOccurrences of a in abracadabra" << endl;
    cout << countOccurrences("abracadabra", 'a');

    //test 3.1 largest element in an array
    int arr[4] = {10, -7, 3, -6};
    int size = 4;
    cout << "\nFind largest element: " << endl;
    cout << findLargestElement(arr, size);

    //test 3.2 ASCII table traversal
    cout << "\nTraverse a ascii table and print before and after the reccursion" << endl;
    traverseAsciiTable('A', 'D');


    return 0;
}