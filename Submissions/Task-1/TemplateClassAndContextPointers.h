//
// Created by mikae on 02.09.2026.
//

#ifndef TEMPLATESANDCALLBACKS_TEMPLATECLASSANDCONTEXTPOINTERS_H
#define TEMPLATESANDCALLBACKS_TEMPLATECLASSANDCONTEXTPOINTERS_H
#include <iostream>


//a)
//template class for aggregator that keeps track of a running total
template<typename T>
class TDataAggregator {
private:
    T stateTotal = 0;

public:
    T GetStateTotal() {
        return stateTotal;
    }

    //b)
    //ads the total to value then dobles it
    void Accumulate(T& val) {
        this->stateTotal += val;
        val *= 2;
    }

    //c)
    //static callback uses the agregator context
    static void StaticCallback(T& val, void* context) {
        TDataAggregator<T>* aggregator = static_cast<TDataAggregator<T>*>(context);

        aggregator->Accumulate(val);
    }
};

//d)
//alias for the functionpointer callbacks with context
template<typename T>
using FContextFunc = void(*)(T&, void*);

//process each element with context using the callback
template<typename T>
void ProcessWithContext(T array[], int size, FContextFunc<T> callback, void* context) {
    for (int i = 0; i < size; i++) {
        callback(array[i], context);
    }
}

#endif //TEMPLATESANDCALLBACKS_TEMPLATECLASSANDCONTEXTPOINTERS_H
