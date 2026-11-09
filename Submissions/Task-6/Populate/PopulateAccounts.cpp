//
// Created by mikae on 05.11.2026.
//

#include"PopulateAccounts.h"

//REUSED CODE FROM TASK 5 (SIMPLE SEARCH)

//4b) populating the accounts
void PopulateAccountsLinkedList(TLinkedList<TBankAccount>& accounts) {
    //csv file with all random names
    ifstream file("names.csv");
    if (!file.is_open()) {
        cerr << "Could not open names.csv" << endl;
        return;
    }
    string line;
    //used a int and incremented to be able to easily manage which id that is at the end of the list for the demonstration
    int accountNumber = 1;

    //program lasts while csv file still contains columns
    while (getline(file, line)) {
        string firstName;
        string lastName;
        bool devider = false;


        //devide first name and last name
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ',') {
                devider = true;
                continue;
            }
            if (!devider) {
                firstName += line[i];
            }
            else {
                lastName += line[i];
            }
        }



        //get random bankNr, random bank account type and random time_t between start and end of 2024
        //6 for ekstactly 6000 acounts such that testing will be predictable
        for (int i = 0; i < 6; i++) {
            TBankAccount* acc = new TBankAccount(to_string(accountNumber), static_cast<EBankAccountType>(RandomNumber(0, 4)), firstName, lastName, RandomNumber(1704067200, 1735689599));
            accounts.Append(acc);
            accountNumber++;
        }
    }
}

//use results from PopulateList to copy to get fair test data
TBankAccount** PopulateAccountsArray(TLinkedList<TBankAccount>& account, int& count) {
    count = 0;
    for (TNode<TBankAccount>* n = account.GetHead(); n != nullptr; n = n->GetNext()) {
        count++;
    }

    TBankAccount** populatedArr = new TBankAccount*[count];

    int i = 0;
    for (TNode<TBankAccount>* n = account.GetHead(); n != nullptr; n = n->GetNext()) {
        populatedArr[i++] = n->GetData();
    }
    return populatedArr;
}

int RandomNumber(int min, int max) {
    static mt19937 rng(random_device{}());
    uniform_int_distribution<int> amountDist(min, max);

    return amountDist(rng);
}