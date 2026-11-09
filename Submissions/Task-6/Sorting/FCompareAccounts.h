//
// Created by mikae on 04.11.2026.
//

#ifndef ALGORITHMIC_ORGANIZER_FCOMPAREACCOUNTS_H
#define ALGORITHMIC_ORGANIZER_FCOMPAREACCOUNTS_H
#include"../TBankAccount/TBankAccount.h"

//1a) typedef function pointer
typedef int (*FCompareAccounts)(TBankAccount* a, TBankAccount* b);

//4a) callback test function that compares bank account balance
int CompareByBalance(TBankAccount* a, TBankAccount* b);
//4a) callback test function that compares last names
int CompareByLastName(TBankAccount* a, TBankAccount* b);

#endif //ALGORITHMIC_ORGANIZER_FCOMPAREACCOUNTS_H
