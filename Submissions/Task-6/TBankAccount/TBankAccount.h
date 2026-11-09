//
// Created by mikae on 04.11.2026.
//

#ifndef ALGORITHMIC_ORGANIZER_TBANKACCOUNT_H
#define ALGORITHMIC_ORGANIZER_TBANKACCOUNT_H

#include<iostream>
#include<ctime>
#include<random>

using namespace std;

//* REUSED CODE FROM TASK 5 "Simple Search"


//1a) Create a enum class to represent types of bankaccount
enum class EBankAccountType {
    Checking,
    Savings,
    Credit,
    Pension,
    Loan
};

//1b) Create a bank account class that holds all the appropriate information a bank account need
class TBankAccount {
private:
    string accountNumber;
    EBankAccountType accountType;
    string ownerFirstName;
    string ownerLastName;
    time_t creationTimeStamp;
    double balance;

    //function to set a random value
    double randomBetween(double min, double max);
    //function to set the random balance to apropriate bank account type
    double generateBalance(EBankAccountType type);


public:
    //constructor to set the account
    TBankAccount(const std::string& accountNumber,
              EBankAccountType accountType,
              const std::string& ownerFirstName,
              const std::string& ownerLastName, time_t creationTimeStamp);

    string GetOwner() const;
    string GetLastName() const;
    string GetAccountNumber() const;
    time_t GetCreationTime() const;
    double GetBalance() const;

};

//overload << operator so that the generic TLinkedList can print accounts
ostream& operator<<(ostream& os, const TBankAccount& acc);



#endif //ALGORITHMIC_ORGANIZER_TBANKACCOUNT_H
