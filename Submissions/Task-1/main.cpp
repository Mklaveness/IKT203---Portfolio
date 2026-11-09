#include <iostream>
#include "BasicTemplate.h"
#include "AdvancedTemplates.h"
#include "CallbacksAndTemplates.h"
#include "TemplateClassAndContextPointers.h"
using namespace std;

/*
 * ASSIGNMENT PRACTICES
 * LENGUAGE : ENGLISH
 * VARIABLE : "movieTitle"
 * FUNCTIONS : Append (verb)
 * CLASSES AND STRUCTS : TMovie (big T)
 * */

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.


// a)
//a teststruct for the task1 to try pass to printtypesize(template)
struct TtestStruct {
    int c;
    float d;
    string e;
};

// c)
// a struct with overloaded > operator to test Getmax
struct TStudent {
    string firstName;
    int courseGrade;


    bool operator>(const TStudent& other) const {
        return courseGrade > other.courseGrade;
    }
};


//2a)
//a simple add to integers function to declare a function pointer to
int Add(int number1, int number2) {
    return number1 + number2;
}

//2b)
// greet function for implementing a type alias
string Greet(string name) {
    return "Hello, " + name;
}

//c)
// to boolean functions for implementation of callback on filterandprint
bool IsEven(int number) {
    if ((number % 2) == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool IsOdd(int number) {
    if ((number % 2) != 0) {
        return true;
    }
    else {
        return false;
    }
}

//loops through array and calls the right function
void FilterAndPrint(int array[], int size, bool (*callback)(int)) {
    for (int i = 0; i < size; i++) {
        if (callback(array[i])) {
            cout << array[i] << endl;
        }
    }
}

//2d)

//three functions to execute by array of function oointers
void Play() {
    cout << "Playing game..." << endl;
}

void Pause() {
    cout << "Game paused." << endl;
}

void Quit() {
    cout << "Quitting game." << endl;
}



//3c)
void DoubleInt(int& val) {
    val *= 2;
}
void CapitalizeChar(char& val) {
    int ascii = val;
    if (ascii <= 122 && ascii >=97) {
        ascii -= 32;
        val = ascii;
    }
}



int main() {


    // a) test printtypesize with different datatypes
    int a = 8;
    double b = 8.3;

    TtestStruct myTestStruct;
    myTestStruct.c = 10;
    myTestStruct.d = 10.8;
    myTestStruct.e = "hello";

    cout << "1. Basic template functions" << endl;
    cout << "a)" << endl;
    cout << "size of int a = 8: " << PrintTypeSize<int>(a) << endl;
    cout << "size of double b = 8.3: " << PrintTypeSize<double>(b) << endl;
    cout << "size of TestStruct: " << PrintTypeSize<TtestStruct>(myTestStruct) << endl;

    // b) test getmax with different data
    cout << "\nb)" << endl;
    cout << "biggest number between 12 and 18: " << GetMax<int>(12, 18) << endl;
    cout << "biggest number between 12.129 and 12.338: " << GetMax<double>(12.129, 12.338) << endl;

    // c) getMax with grade from Tstudent struct
    cout << "\nc)" << endl;
    TStudent studentA{"Ola", 3};
    TStudent studentB{"Martin", 5};
    TStudent bestStudent = GetMax<TStudent>(studentA, studentB);
    cout << "best grade between instance of student A and B: " << bestStudent.firstName << " Grade: " << bestStudent.courseGrade << endl;

    cout << "\n2. Advanced Templates (Variadic and Non-Type)" << endl;

    // a) template implemented in AdvancedTemplates.h

    // b) non-type template parameter
    cout << "b)" << endl;
    TStaticArray<int, 5> myArray;
    myArray.Populate();
    myArray.Print();

    // c) print result
    cout << "\nc)" << endl;
    PrintContainer(myArray);

    cout << "\nStep 2: Global Callbacks (No Templates)" << endl;
    //3a) create and use a function pointer to add
    cout << "a)" << endl;
    using AddPtr = int (*)(int, int);
    AddPtr aPtr = &Add;


    //Implicit call: By calling pointer name direct as a normal function
    cout << aPtr(10, 8) << endl;

    //explicit call: dereference the pointer with * operator
    cout << (*aPtr)(8, 9) << endl;

    //b) create a function pointer to greet function
    cout << "\nb)" << endl;
    typedef string (*GreetPtr)(string);
    GreetPtr Gptr= &Greet;
    cout << Gptr("Mikael") << endl;

    cout << "\nc)" << endl;
    //2 boolean function (ISEVEN) (ISODD) with int as parameter
    //FilterAndPrint function accepts an array of int, arraysize and a callback function as a parameter
    int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "is Odd: " << endl;
    FilterAndPrint(numbers, 10, IsOdd);
    cout << "\nis even: " << endl;
    FilterAndPrint(numbers, 10, IsEven);

    cout << "d)" << endl;
    //3 void functions with no parameters PLAY (Playing Game...), PAUSE (Game Paused), QUIT (Quitting game.)
    using GameStatusPtr = void(*)();
    GameStatusPtr PlayPtr = &Play;
    GameStatusPtr PausePtr = &Pause;
    GameStatusPtr QuitPtr = &Quit;

    //use array of functionpointers to call the functions
    GameStatusPtr functions[3] = {PlayPtr, PausePtr, QuitPtr};
    for (int i = 0; i < 3; i++) {
        functions[i]();
    }

    cout << "Step 3: The bridge (Callbacks + Templates)" << endl;

    //a) callback with template function implemented in CallbacksAndTemplates.h


    //b) generic callback processing implemented in CallbacksAndTemplates.h

    //c) template callback functions

    //d) processing different data types using callback
    cout << "d)" << endl;
    //test arrays
    int integerArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char characterArray[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

    //print original before ProcessArray to see difference
    cout << "\n";
    for (int i = 0; i < 10; i++) {
        cout << integerArray[i];
    }
    cout << "\n";
    for (int i = 0; i < 10; i++) {
        cout << characterArray[i];
    }

    //process using type spesific callback
    ProcessArray(integerArray, 10, DoubleInt);
    ProcessArray(characterArray, 10, CapitalizeChar);

    //the results
    cout << "\nAfter ProcessArray:" << endl;;
    for (int i = 0; i < 10; i++) {
        cout << integerArray[i];
    }
    cout << "\n";
    for (int i = 0; i < 10; i++) {
        cout << characterArray[i];
    }

    cout << "\n\nStep 4: The OOP Template Class & Context Pointers" << endl;

    //create aggregator and testdata
    TDataAggregator<int> myAggregator;
    int testData[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //process data using callback and context pointer
    ProcessWithContext(testData, 10, TDataAggregator<int>::StaticCallback, &myAggregator);


    //print processed data and total
    for (int i = 0; i < 10; i++) {
        cout << testData[i] << endl;
    }
    cout << "state Total: " << myAggregator.GetStateTotal() << endl;




return 0;
}