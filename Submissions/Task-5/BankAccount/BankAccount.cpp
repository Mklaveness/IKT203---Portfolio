//
// Created by mikae on 27.10.2026.
//

#include "BankAccount.h"

//1b) Create a bank account class that holds all the appropriate information a bank account need
TBankAccount::TBankAccount(const std::string& accountNumber,
              EBankAccountType accountType,
              const std::string& ownerFirstName,
              const std::string& ownerLastName, time_t creationTimeStamp)
      : accountNumber(accountNumber),
        accountType(accountType),
        ownerFirstName(ownerFirstName),
        ownerLastName(ownerLastName),
        creationTimeStamp(creationTimeStamp),
        balance(generateBalance(accountType)){}




double TBankAccount::randomBetween(double min, double max)
{
    static mt19937 gen(random_device{}());
    uniform_real_distribution<double> dist(min, max);
    return dist(gen);
}

double TBankAccount::generateBalance(EBankAccountType type)
{
    switch (type)
    {
        case EBankAccountType::Loan:   return randomBetween(-50000, -25000);
        case EBankAccountType::Credit: return randomBetween(-1000, 0);
        default:                       return randomBetween(0, 1000);
    }
}

string TBankAccount::GetOwner() const {
    return ownerFirstName;
}

string TBankAccount::GetLastName() const {
    return ownerLastName;
}

string TBankAccount::GetAccountNumber() const {
    return accountNumber;
}

time_t TBankAccount::GetCreationTime() const {
    return creationTimeStamp;
}

//overload the << operator such that the generic class can print bank details
ostream& operator<<(ostream& os, const TBankAccount& acc) {
    time_t created = acc.GetCreationTime();
    tm* t = gmtime(&created);
    os << "Account: " << acc.GetAccountNumber()
    << " | Owner: " << acc.GetOwner()
    << " | Created: " << t->tm_year + 1900 << "-" << t->tm_mon +1 << "-" << t->tm_mday;
    return os;
}