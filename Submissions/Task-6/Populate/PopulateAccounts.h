//
// Created by mikae on 05.11.2026.
//

#ifndef ALGORITHMIC_ORGANIZER_POPULATEACCOUNTS_H
#define ALGORITHMIC_ORGANIZER_POPULATEACCOUNTS_H

#include<iostream>
#include<fstream>

#include"../TLinkedList/TLinkedList.h"
#include"../TBankAccount/TBankAccount.h"

using namespace std;

//4b)
void PopulateAccountsLinkedList(TLinkedList<TBankAccount>& accounts);
TBankAccount** PopulateAccountsArray(TLinkedList<TBankAccount>& accounts, int& count);
int RandomNumber(int min, int max);

#endif //ALGORITHMIC_ORGANIZER_POPULATEACCOUNTS_H
