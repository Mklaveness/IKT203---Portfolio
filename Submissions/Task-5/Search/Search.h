//
// Created by mikae on 28.10.2026.
//

#ifndef SIMPLE_SEARCH_SEARCHSUMMARY_H
#define SIMPLE_SEARCH_SEARCHSUMMARY_H
#include<iostream>
using namespace std;

#include"../BankAccount/BankAccount.h"

//2a) struct to hold preformce data
struct SearchSummary {
    long long comparisons;
    double timeSpentMs;
};

//2b) callback function function pointer
typedef bool (*FCompareAccount)(TBankAccount* account, void* searchKey);

//3b) create a standalone function finding account by its account number
TBankAccount* FindAccountByNumber(TBankAccount** accountArray, int arraySize, const string& accountNumber, SearchSummary& summary);

//3c) create a standalone function that prints every account in a spesific date
void PrintEveryAccountInDateRange(TBankAccount** accountArray, int arraySize, time_t fromDate, time_t toDate, SearchSummary& summary);

//4b) find method
bool CompareAccountNumber(TBankAccount* account, void* searchKey);

//4c) find month and year
struct monthYear {
    int month;
    int year;
};

//4d) struct that holds multiple months
//this has some expectencies: that months are sorted and are continious
struct multipleMonthYear {
    int arrMonth[12]; //at most 12 months
    int howManyMonths; //how many of the months are initialised
    int year;
};

bool CompareAccountMonth(TBankAccount* account, void* searchKey);

int CompareByLastName(TBankAccount* a, TBankAccount* b);
#endif //SIMPLE_SEARCH_SEARCHSUMMARY_H
