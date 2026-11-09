cmake_minimum_required(VERSION 4.3)
project(Algorithmic_organizer)

set(CMAKE_CXX_STANDARD 20)

add_executable(Algorithmic_organizer main.cpp
        "Sorting/FCompareAccounts.h"
        TBankAccount/TBankAccount.cpp
        TBankAccount/TBankAccount.h
        "Sorting/OperationSummary.h"
        "Sorting/Callback.cpp"
        "TSort/TSort.cpp"
        "TSort/TSort.h"
        TNode/TNode.h
        TNode/TNode.h
        TLinkedList/TLinkedList.h
        Populate/PopulateAccounts.h
        Populate/PopulateAccounts.cpp)
