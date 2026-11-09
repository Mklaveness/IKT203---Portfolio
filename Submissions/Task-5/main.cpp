#include<iostream>
using namespace std;

/*
 * CODE AND COMMENTS MUST BE IN ENGLISH
 *
 * NAMING CONVENTIONS:
 * CLASS: TBankAccount
 * DATA FIELDS: camelCase
 * FUNCTIONS: PascalCase
 * ENUM: EBankAccountType
 * TYPEDEF FUNCTION: FCompareAccount
 *
 * ENCAPSULATION:
 * -Private datafields
 * -public methods
 *
 * MEMORY MANAGEMENT
 * NOT ALLOWED: std::unique_ptr
 *
 * PERFORMANCE ANALYSIS: All search functions must accept a reference to a SearchSummary object and update it accordingly.
 */

//includes
#include"BankAccount/BankAccount.h"
#include"TNode/TNode.h"
#include"TLinkedList/TLinkedList.h"
#include"Search/Search.h"
#include"Populate/PopulateAccounts.h"


int main() {


    //2a) selection sort
    TLinkedList<TBankAccount> account(false);
    SearchSummary SearchOps = {0, 0.0};

    int count;
    PopulateAccountsLinkedList(account);
    TBankAccount** bankArr = PopulateAccountsArray(account, count);

    TBankAccount* key = new TBankAccount("1", EBankAccountType::Savings, "Gabbie", "Lillow", 1717200000);


    auto start = chrono::steady_clock::now();
    TBankAccount* found = nullptr;
    for (int i = 0; i < count; i++) {
        SearchOps.comparisons++;
        if (CompareByLastName(key, bankArr[i]) == 0) {
            found = bankArr[i];
            break;
        }
    }
    auto end = chrono::steady_clock::now();
    SearchOps.timeSpentMs = chrono::duration<double, milli>(end - start).count();

    if (found != nullptr) {
        cout << "Account found: " << endl;
        cout << found->GetLastName() << endl;
        cout << "\nPreformance data search: " << endl;
        cout << "Time spent: " << SearchOps.timeSpentMs << endl;
        cout << "Amount of comparisons: " << SearchOps.comparisons << endl;
    }
        /*
    //3a) Populate a linkedlist with bankaccounts as well as a array of TBankAccounts
    TLinkedList<TBankAccount> accounts(true);
    TBankAccount** accountArray = new TBankAccount*[4];

    TBankAccount* a = new TBankAccount("1001", EBankAccountType::Checking, "Ola", "Nordmann", 1704067200);
    TBankAccount* b = new TBankAccount("1002", EBankAccountType::Loan, "Sigrid", "Larsen", 1709251200);
    TBankAccount* c = new TBankAccount("1003", EBankAccountType::Credit, "Martin", "Martinson", 1717200000);
    TBankAccount* d = new TBankAccount("1004", EBankAccountType::Savings, "Astrid", "Astrup", 1717200000);

    accounts.Append(a);
    accountArray[0] = a;

    accounts.Append(b);
    accountArray[1] = b;

    accounts.Append(c);
    accountArray[2] = c;

    accounts.Append(d);
    accountArray[3] = d;

    //3b)
    SearchSummary sum;
    TBankAccount* found = FindAccountByNumber(accountArray, 4, "1004", sum);
    cout << found->GetOwner() << endl;
    cout << sum.comparisons << endl;
    cout << sum.timeSpentMs << endl;

    //3c)
    SearchSummary summen;
    PrintEveryAccountInDateRange(accountArray, 4, 1767225600, 1798761600, summen);
    cout << summen.comparisons << endl;
    cout << summen.timeSpentMs << endl;

    //4a) populate TLinkedList with random data from csv file
    TLinkedList<TBankAccount> baccounts(true);
    PopulateAccounts(baccounts);

    //4b) account near the end
    cout << "\n--- Account near the end of the list ---" << endl;

    string accountNr = "7000";
    SearchSummary sumy;
    TBankAccount* bankAccountFound = baccounts.Find(CompareAccountNumber, &accountNr, sumy);
    if (bankAccountFound == nullptr) {
        cout << "did not find any match" << endl;
    }
    else {
        cout << "Account found" << endl;
        cout << "Found: " << bankAccountFound->GetAccountNumber() << endl;
    }

    cout << "Comparisons: " << sumy.comparisons << endl;
    cout << "Time spent: " << sumy.timeSpentMs << endl;

    //4b) account not in the list
    cout << "\n--- Account not in the list ---" << endl;
    accountNr = "10000";
    bankAccountFound = baccounts.Find(CompareAccountNumber, &accountNr, sumy);
    if (bankAccountFound == nullptr) {
        cout << "did not find any match" << endl;
    }
    else {
        cout << "Account found" << endl;
        cout << "Found: " << bankAccountFound->GetAccountNumber() << endl;
    }

    cout << "Comparisons: " << sumy.comparisons << endl;
    cout << "Time spent: " << sumy.timeSpentMs << endl;

    //4c) Every method to find all accounts created in june 2024
    cout << "\n--- 4c) every method find June 2024 ---" << endl;
    monthYear mY;
    mY = {6, 2024};
    TLinkedList<TBankAccount>* searchResults = baccounts.Every(CompareAccountMonth, &mY, sumy);
    searchResults->ShowList();

    cout << "Comparisons: " << sumy.comparisons << endl;
    cout << "Time spent: " << sumy.timeSpentMs << endl;

    //4d) use PrintEveryAccountInDateRange()
    cout << "\n--- 4c) find every account in a date range" << endl;

    //copy elements from linkedlist to a array

    //first count elements
    int size = 0;
    while (baccounts.GetAtIndex(size) != nullptr) {
        size++;
    }

    //copy
    TBankAccount** baccountArray = new TBankAccount*[size];
    for (int i = 0; i < size; i++) {
        baccountArray[i] = baccounts.GetAtIndex(i);
    }

    SearchSummary sumq1;
    PrintEveryAccountInDateRange(baccountArray, size, 1704067200, 1711929599, sumq1);

    cout << "Comparisons: " << sumq1.comparisons << endl;
    cout << "Time spent: " << sumq1.timeSpentMs << endl;
    delete[] baccountArray;

    */

    return 0;


}