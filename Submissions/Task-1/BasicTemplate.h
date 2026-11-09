//
// Created by mikae on 31.08.2026.
//

#ifndef TEMPLATESANDCALLBACKS_BASICTEMPLATE_H
#define TEMPLATESANDCALLBACKS_BASICTEMPLATE_H

#include <iostream>
using namespace std;


// template function that could take in all datatypes and return the size.
// printed in bytes (sizeof())

//a)
template <typename T>size_t PrintTypeSize(T v) {
    return sizeof(v);
}


//template function that could take in any type and return the biggest of to variables

//b)
template <typename T>T GetMax(T a, T b) {
    return (a > b) ? a : b;
}

#endif //TEMPLATESANDCALLBACKS_BASICTEMPLATE_H