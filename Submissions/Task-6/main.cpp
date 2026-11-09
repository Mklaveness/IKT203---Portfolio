#include<iostream>
using namespace std;

#include"TBankAccount/TBankAccount.h"
#include "TSort/TSort.h"
#include"Sorting/FCompareAccounts.h"
#include"TLinkedList/TLinkedList.h"
#include"Sorting/OperationSummary.h"
#include"Populate/PopulateAccounts.h"

int main() {

    //2a) selection sort
    TLinkedList<TBankAccount> account(false);
    OperationSummary SortOps;
    OperationSummary SearchOps;

    int count;
    PopulateAccountsLinkedList(account);
    TBankAccount** bankArr = PopulateAccountsArray(account, count);

    TSort sort(bankArr, count, &account);


    TBankAccount* key = new TBankAccount("1", EBankAccountType::Savings, "Gabbie", "Lillow", 1717200000);

    sort.SortArrayByLastName(SortOps);
    TBankAccount* result = sort.BinarySearch(key, CompareByLastName, SearchOps);
    if (result != nullptr) {
        cout << "Account found" << endl;
        cout << result->GetLastName() << endl;
    }
    else {
        cout << "no match" << endl;
    }

    cout << "\nPreformance data sort: " << endl;
    cout << "Time Spent: " << SortOps.timeSpentMs << endl;
    cout << "Amount of Comparisons: " << SortOps.comparisons << endl;
    cout << "amount of swaps: " << SortOps.swaps << endl;

    cout << "\nPreformance data search: " << endl;
    cout << "Time spent: " << SearchOps.timeSpentMs << endl;
    cout << "Amount of comparisons: " << SearchOps.comparisons << endl;


    //selection sort with array
    cout << "---2a) Selection Sort (with array)--" << endl;

    //print before 4 elements to see if realy sorted
    cout << "\ntest output to see if realy sorted" << endl;
    //print balance before sorted
    cout << "before" << endl;
    for (int i = 0; i < 4; i++) {
        double balance = bankArr[i]->GetBalance();
        cout << balance << endl;
    }

    TBankAccount** sorted = sort.SelectionSortArray(CompareByBalance, SortOps);

    cout << "\nAfter" << endl;
    //print balance after sorted
    for (int i = 0; i < 4; i++) {
        double balance = sorted[i]->GetBalance();
        cout << balance << endl;;
    }


    cout << "\nPreformance data (Selection Sort with array): " << endl;
    cout << "Time Spent: " << SortOps.timeSpentMs << endl;
    cout << "Amount of Comparisons: " << SortOps.comparisons << endl;
    cout << "Amount of swaps when sorted: " << SortOps.swaps << endl;



    cout << "\n---2a) Selection Sort (with list) ---" << endl;
    cout << "Before sorted" << endl;


    //testoutput to se if sorted
    TNode<TBankAccount>* ac = account.GetHead();
    cout << "\ntest output to see if realy sorted" << endl;
    for (int i = 0; i < 4; i++){
        cout << ac->GetData()->GetBalance() << endl;
        ac = ac->GetNext();
    }

    TLinkedList<TBankAccount>* sortedList = sort.SelectionSortList(CompareByBalance, SortOps);
    cout << "After sorted" << endl;

    TNode<TBankAccount>* acsort = sortedList->GetHead();
    for (int i = 0; i < 4; i++) {
        cout << acsort->GetData()->GetBalance() << endl;
        acsort = acsort->GetNext();
    }

    cout << "\nPreformance data: " << endl;
    cout << "Time Spent: " << SortOps.timeSpentMs << endl;
    cout << "Amount of Comparisons: " << SortOps.comparisons << endl;
    cout << "Amount of swaps when sorted: " << SortOps.swaps << endl;




    cout << "\n---2b) Bubble Sort(with pointer array) ---" << endl;
    cout << "Before" << endl;
    for (int i = 0; i < 4; i++) {
        double balance = bankArr[i]->GetBalance();
        cout << balance << endl;
    }
    TBankAccount** sortedBubbleSort = sort.BubbleSortArray(CompareByBalance, SortOps);

    cout << "After" << endl;
    for (int i = 0; i < 4; i++) {
        double balance = sortedBubbleSort[i]->GetBalance();
        cout << balance << endl;;
    }

    cout << "\nPreformance data: " << endl;
    cout << "Time Spent: " << SortOps.timeSpentMs << endl;
    cout << "Amount of Comparisons: " << SortOps.comparisons << endl;
    cout << "Amount of swaps when sorted: " << SortOps.swaps << endl;



    cout << "\n3a) --- Quick sort (On the array) ---" << endl;

    cout << "Little test with the first 4 numbers to see if sorted" << endl;
    cout << "Before" << endl;
    for (int i = 0; i < 4; i++) {
        double balance = bankArr[i]->GetBalance();
        cout << balance << endl;
    }
    TBankAccount** sortedQuickSort = sort.QuickSortArray(CompareByBalance, SortOps);
    cout << "After" << endl;
    for (int i = 0; i < 4; i++) {
        double balance = sortedQuickSort[i]->GetBalance();
        cout << balance << endl;
    }
    cout << "\nPreformance data: " << endl;
    cout << "Time Spent: " << SortOps.timeSpentMs << endl;
    cout << "Amount of Comparisons: " << SortOps.comparisons << endl;
    cout << "Amount of swaps when sorted: " << SortOps.swaps << endl;



    cout << "\n---3b) Merge sort with Linked List ---" << endl;
    cout << "Before" << endl;


    TNode<TBankAccount>* acc = account.GetHead();
    cout << "\ntest output to see if realy sorted" << endl;
    for (int i = 0; i < 4; i++){
        cout << acc->GetData()->GetBalance() << endl;
        acc = acc->GetNext();
    }

    TLinkedList<TBankAccount>* MergeSortedList = sort.MergeSortLinkedList(CompareByBalance, SortOps);
    TNode<TBankAccount>* sortAc = MergeSortedList->GetHead();
    cout << "After" << endl;
    cout << "\ntest output to see if realy sorted" << endl;
    for (int i = 0; i < 4; i++){
        cout << sortAc->GetData()->GetBalance() << endl;
        sortAc = sortAc->GetNext();
    }

    cout << "\nPreformance data: " << endl;
    cout << "Time Spent: " << SortOps.timeSpentMs << endl;
    cout << "Amount of Comparisons: " << SortOps.comparisons << endl;
    cout << "Amount of swaps when sorted: " << SortOps.swaps << endl;



    return 0;
}