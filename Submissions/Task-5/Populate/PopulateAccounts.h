//
// Created by mikae on 01.11.2026.
//

#ifndef SIMPLE_SEARCH_POPULATEACCOUNTS_H
#define SIMPLE_SEARCH_POPULATEACCOUNTS_H
#include<iostream>
#include<fstream>

#include"../TLinkedList/TLinkedList.h"
#include"../BankAccount/BankAccount.h"
using namespace std;

//4a) populate accounts
void PopulateAccountsLinkedList(TLinkedList<TBankAccount>& accounts);
TBankAccount** PopulateAccountsArray(TLinkedList<TBankAccount>& account, int& count);
int RandomNumber(int min, int max);


#endif //SIMPLE_SEARCH_POPULATEACCOUNTS_H
