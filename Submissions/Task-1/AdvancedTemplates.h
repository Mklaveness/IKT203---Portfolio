//
// Created by mikae on 01.09.2026.
//

#ifndef TEMPLATESANDCALLBACKS_ADVANCEDTEMPLATES_H
#define TEMPLATESANDCALLBACKS_ADVANCEDTEMPLATES_H
#include <iostream>


//a template struct that acts as a tuple
//a)
template<typename... Args>
struct TDataPack {

};


//class that holds a array of T type and functions to handle it
//b)
template <typename T, int Size>
class TStaticArray {
private:
    T data[Size];

public:
    void Populate() {
        T bufferData;
        for (int i = 0; i < Size; i++) {
            cout << "please enter data to the array: ";
            cin >> bufferData;
            data[i] = bufferData;
        }
    }
    void Print() {
        for (int i = 0; i < Size; i++) {
            cout << data[i] << endl;
        }
    }
    T GetData(int index) const {
        return data[index];
    }
};


// // Prints all elements in a container using its GetData() function.
//c)
template <template <typename, int> class Container, typename T, int N>
void PrintContainer(Container<T, N> container) {
    for (int i = 0; i < N; i++) {
        cout << container.GetData(i) << endl;
    }
}



#endif //TEMPLATESANDCALLBACKS_ADVANCEDTEMPLATES_H
