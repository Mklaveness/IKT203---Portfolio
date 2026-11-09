//
// Created by mikae on 01.09.2026.
//

#ifndef TEMPLATESANDCALLBACKS_CALLBACKSANDTEMPLATES_H
#define TEMPLATESANDCALLBACKS_CALLBACKSANDTEMPLATES_H
#include <iostream>

//A alias to a function that returns T datatype
//a)
template<typename T>
using FActionFunc = void(*)(T&);


//process each element in an array defined by the callback function
//b)
template<typename T>
void ProcessArray(T* arr, int size, FActionFunc<T> callback) {
    for (int i = 0; i < size; i++) {
        callback(arr[i]);
    }
}
#endif //TEMPLATESANDCALLBACKS_CALLBACKSANDTEMPLATES_H
