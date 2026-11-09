cmake_minimum_required(VERSION 4.3)
project(Simple_Search)

set(CMAKE_CXX_STANDARD 20)

add_executable(Simple_Search main.cpp
        BankAccount/BankAccount.cpp
        BankAccount/BankAccount.h
        TLinkedList/TLinkedList.h
        TNode/TNode.h
        Search/Search.h
        Search/Search.cpp
        Populate/PopulateAccouncts.cpp
        Populate/PopulateAccounts.h)
