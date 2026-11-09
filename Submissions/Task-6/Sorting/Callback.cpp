//
// Created by mikae on 04.11.2026.
//

#include"FCompareAccounts.h"

//4a) balance
int CompareByBalance(TBankAccount* a, TBankAccount* b) {
    if (a->GetBalance() > b->GetBalance()) {
        return 1;
    }
    if (a->GetBalance() < b->GetBalance()) {
        return -1;
    }
    return 0;
}

//4a) last name
int CompareByLastName(TBankAccount* a, TBankAccount* b) {
    return a->GetLastName().compare(b->GetLastName());
}