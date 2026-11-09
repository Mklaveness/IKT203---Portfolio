//
// Created by mikae on 28.10.2026.
//

#include"Search.h"
#include"chrono"
#include"../TLinkedList/TLinkedList.h"

//3b) standalone function for finding a account in an array that matches the accountNumber
TBankAccount* FindAccountByNumber(TBankAccount** accountArray, int arraySize, const string& accountNumber, SearchSummary& summary) {
    auto start = chrono::steady_clock::now();

    summary.comparisons = 0;
    summary.timeSpentMs = 0.0;
    TBankAccount* result = nullptr;

    for (int i = 0; i < arraySize; i++) {
        summary.comparisons++;
        if (accountArray[i]->GetAccountNumber() == accountNumber) {
            result = accountArray[i];
            break;
        }
    }

    auto end = chrono::steady_clock::now();
    summary.timeSpentMs = chrono::duration<double, milli>(end - start).count();

    return result;
}

//3c) Standalone function for printing every account that matches a spesific time range
void PrintEveryAccountInDateRange(TBankAccount** accountArray, int arraySize, time_t fromDate, time_t toDate, SearchSummary& summary) {
    auto start = chrono::steady_clock::now();

    summary.comparisons = 0;
    summary.timeSpentMs = 0.0;

    for (int i = 0; i < arraySize; i++) {
        summary.comparisons++;
        if (accountArray[i]->GetCreationTime() >= fromDate && accountArray[i]->GetCreationTime() <= toDate) {
            cout << *accountArray[i] << endl;
        }
    }

    auto end = chrono::steady_clock::now();
    summary.timeSpentMs = chrono::duration<double, milli>(end - start).count();

}

bool CompareAccountNumber(TBankAccount* account, void* searchKey) {
    string* key = static_cast<string*>(searchKey);
    return account->GetAccountNumber() == *key;
}


bool CompareAccountMonth(TBankAccount* account, void* searchKey) {
    monthYear* key = static_cast<monthYear*>(searchKey);

    time_t timeCreated = account->GetCreationTime();
    tm* t = gmtime(&timeCreated);

    return(t->tm_year + 1900 == key->year && t->tm_mon + 1 == key->month);
}


int CompareByLastName(TBankAccount* a, TBankAccount* b) {
    return a->GetLastName().compare(b->GetLastName());
}