//
// Created by mikae on 04.11.2026.
//

#ifndef ALGORITHMIC_ORGANIZER_TSORT_H
#define ALGORITHMIC_ORGANIZER_TSORT_H

//have to return new list or array

#include "../TBankAccount/TBankAccount.h"
#include "../TLinkedList/TLinkedList.h"
#include "../Sorting/FCompareAccounts.h"
#include "../Sorting/OperationSummary.h"
#include "../TNode/TNode.h"

#include<ctime>

//1c) TSort class that is the dedicated sorting engine
class TSort {
private:
    TBankAccount** bankArray;
    const int arraySize;
    TLinkedList<TBankAccount>* bankList;

    bool arrayIsSorted;
    TBankAccount** sortedArray;

    //3a) quick sort array
    void QuickSortRecursive(TBankAccount** arr, int low, int high, FCompareAccounts cmp, OperationSummary& sum);
    int Partition(TBankAccount** arr, int low, int high, FCompareAccounts cmp, OperationSummary& sum);

    //3b) merge sort on linkedlist
    TNode<TBankAccount>* MergeSortLinkedListRecursive(TNode<TBankAccount>*, FCompareAccounts cmp, OperationSummary& sum);
    //5a) Binary search recursive function
    TBankAccount* BinarySearchRecursive(TBankAccount* key, FCompareAccounts cmp, int low, int high, OperationSummary& sum);
public:
    //contructor to set original data sources
    TSort(TBankAccount** bankArray, int arraySize, TLinkedList<TBankAccount>* bankList);
    ~TSort();

    //2a) selection sort (with array)
    TBankAccount** SelectionSortArray(FCompareAccounts cmp, OperationSummary& sum);
    //2a) seleciton sort (with linkedlist)
    TLinkedList<TBankAccount>* SelectionSortList(FCompareAccounts cmp, OperationSummary& sum);
    //2b) Bubble sort on array
    TBankAccount** BubbleSortArray(FCompareAccounts cmp, OperationSummary& sum);
    //3a) Quick sort pointer array
    TBankAccount** QuickSortArray(FCompareAccounts cmp, OperationSummary& sum);

    //3b) Merge sort on the linked list
    TLinkedList<TBankAccount>* MergeSortLinkedList(FCompareAccounts cmp, OperationSummary& sum);

    //5a) Binary Search
    TBankAccount* BinarySearch(TBankAccount* key, FCompareAccounts cmp, OperationSummary& sum);

    //5a) wrapper function
    void SortArrayByLastName(OperationSummary& sum);
};


#endif //ALGORITHMIC_ORGANIZER_TSORT_H
