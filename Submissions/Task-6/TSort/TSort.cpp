//
// Created by mikae on 04.11.2026.
//

#include "TSort.h"


//1c) Constructor to set the original data sources
TSort::TSort(TBankAccount** arr, int count, TLinkedList<TBankAccount>* list) : bankArray(arr), arraySize(count), bankList(list), arrayIsSorted(false), sortedArray(nullptr){}

TSort::~TSort() {
    delete[] sortedArray;
    sortedArray = nullptr;
}

//2a) selection sort

/*Complexity analysis
*Selection sort looks through the entire list no mather how the unsorted data looks
*hence why time is always the same
*CASE      TIME        SPACE
*BEST      O(n^2)      O(1)
*AVERAGE   O(n^2)      O(1)
*WORST     O(n^2)      O(1)
*
* SWAPS : 1 per/round
 */
TBankAccount** TSort::SelectionSortArray(FCompareAccounts cmp, OperationSummary& sum) {
    //init of the summary datafields
    auto start = chrono::steady_clock::now();
    sum.comparisons = 0;
    sum.swaps = 0;
    sum.timeSpentMs = 0.0;

    TBankAccount** copy = new TBankAccount*[arraySize];

    //copy the list to the new list that is to be returned
    for (int i = 0; i < arraySize; i++) {
        copy[i] = bankArray[i];
    }

    for (int i = 0; i < arraySize -1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < arraySize; j++) {
            sum.comparisons++;
            if (cmp(copy[j], copy[minIdx]) < 0) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            TBankAccount* tmp = copy[i];
            copy[i] = copy[minIdx];
            copy[minIdx] = tmp;
            sum.swaps++;
        }
    }
    auto end = chrono::steady_clock::now();
    sum.timeSpentMs = chrono::duration<double, milli>(end-start).count();
    return copy;
}

//2a) Selction sort with LinkedList

/*Complexity analysis
*Selection sort looks through the entire list no mather how the unsorted data looks
*hence why time is always the same
*CASE      TIME        SPACE
*BEST      O(n^2)      O(1)
*AVERAGE   O(n^2)      O(1)
*WORST     O(n^2)      O(1)
*
*SWAPS : 1 per/round
*/
TLinkedList<TBankAccount>* TSort::SelectionSortList(FCompareAccounts cmp, OperationSummary& sum) {
    //init of the summary datafields
    auto start = chrono::steady_clock::now();
    sum.comparisons = 0;
    sum.swaps = 0;
    sum.timeSpentMs = 0.0;

    //new linked list for the return
    TLinkedList<TBankAccount>* copy = new TLinkedList<TBankAccount>(false);

    //copy to new list
    for (TNode<TBankAccount>* n = bankList->GetHead(); n != nullptr; n = n->GetNext()) {
        copy->Append(n->GetData());
    }

    for (TNode<TBankAccount>* i = copy->GetHead(); i != nullptr; i = i->GetNext()) {
        TNode<TBankAccount>* minNode = i;

        for (TNode<TBankAccount>* j = i->GetNext(); j != nullptr; j = j->GetNext()) {
            sum.comparisons++;
            if (cmp(j->GetData(), minNode->GetData()) < 0) {
                minNode = j;
            }
        }
        if (minNode != i) {
            TBankAccount* tmp = i->GetData();
            i->SetData(minNode->GetData());
            minNode->SetData(tmp);
            sum.swaps++;
        }
    }

    auto end = chrono::steady_clock::now();
    sum.timeSpentMs = chrono::duration<double, milli>(end-start).count();
    return copy;
}

/*Complexity analysis
*Bubble sort compares i and i+1 end swaps them acordingly so that it preforms multiple swaps each time it walks through the list
*CASE      TIME        SPACE
*BEST      O(n)        O(1)
*AVERAGE   O(n^2)      O(1)
*WORST     O(n^2)      O(1)
*
*SWAPS : all: N(N-1)/2 | in one round N-1-i
*/
TBankAccount** TSort::BubbleSortArray(FCompareAccounts cmp, OperationSummary& sum) {
    //init of the summary datafields
    auto start = chrono::steady_clock::now();
    sum.comparisons = 0;
    sum.swaps = 0;
    sum.timeSpentMs = 0.0;

    TBankAccount** copy = new TBankAccount*[arraySize];

    //copy the list to the new list that is to be returned
    for (int i = 0; i < arraySize; i++) {
        copy[i] = bankArray[i];
    }

    bool swaped;
    for (int i = 0; i < arraySize - 1; i++) {
        swaped = false;
        for (int j = 0; j < arraySize - i - 1; j++) {
            sum.comparisons++;
            if (cmp(copy[j], copy[j + 1]) > 0) {
                TBankAccount* tmp = copy[j];
                copy[j] = copy[j+1];
                copy[j+1] = tmp;
                sum.swaps++;
                swaped = true;
            }
        }
        if (!swaped) {
            break;
        }
    }

    auto end = chrono::steady_clock::now();
    sum.timeSpentMs = chrono::duration<double, milli>(end-start).count();
    return copy;
}



//3a) Quick sort pointer array
/*Complexity analysis
*Quick sort takes a pivot (in my case the last element in the array) and compares that to each element and puts the element
*on the "Left" or "Right" side based on the comparison. Therefor we get every element bigger in one side and smaller on the other
*do this multiple times and it becomes sorted. Hence why this is perfect for recursion because we do samme multiple times.
*CASE      TIME         SPACE
*BEST      O(n Log n)   O(log n))
*AVERAGE   O(n log n)   O(log n)
*WORST     O(n^2)       O(n)
*
*SWAPS : at most one per comparison, plus the pivot swap per partition
*/
TBankAccount** TSort::QuickSortArray(FCompareAccounts cmp, OperationSummary& sum) {
    //init of the summary datafields
    auto start = chrono::steady_clock::now();
    sum.comparisons = 0;
    sum.swaps = 0;
    sum.timeSpentMs = 0.0;

    TBankAccount** copy = new TBankAccount*[arraySize];

    //copy the list to the new list that is to be returned
    for (int i = 0; i < arraySize; i++) {
        copy[i] = bankArray[i];
    }


    if (arraySize <= 1) {
        return copy;
    }

    QuickSortRecursive(copy, 0, arraySize-1, cmp, sum);

    auto end = chrono::steady_clock::now();
    sum.timeSpentMs = chrono::duration<double, milli>(end-start).count();

    return copy;
}

//3a) quick sort recursive function
void TSort::QuickSortRecursive(TBankAccount** arr, int low, int high, FCompareAccounts cmp, OperationSummary& sum) {
    if (low < high) {
        int piv = Partition(arr, low, high, cmp, sum);
        QuickSortRecursive(arr, low, piv - 1, cmp, sum);
        QuickSortRecursive(arr, piv + 1, high, cmp, sum);
    }
}

int TSort::Partition(TBankAccount** arr, int low, int high, FCompareAccounts cmp, OperationSummary& sum) {
    //chose pivot
    TBankAccount* pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {
        sum.comparisons++;
        if (cmp(arr[j], pivot) < 0) {
            i++;
            TBankAccount* tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            sum.swaps++;
        }
    }

    //move pivot
    //returns potiotion of pivot
    TBankAccount* tmp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = tmp;
    sum.swaps++;
    return i+1;
}

//3b) Merge sort recusive
TNode<TBankAccount>* TSort::MergeSortLinkedListRecursive(TNode<TBankAccount>* node, FCompareAccounts cmp, OperationSummary& sum) {
    if (node == nullptr || node->GetNext() == nullptr) {
        return node;
    }

    //use fast and slow method for spliting the array
    TNode<TBankAccount>* slow = node;
    TNode<TBankAccount>* fast = node->GetNext();
    while (fast != nullptr && fast->GetNext() != nullptr) {
        slow = slow->GetNext();
        fast = fast->GetNext()->GetNext();
    }
    TNode<TBankAccount>* a = node;
    TNode<TBankAccount>* b = slow->GetNext();
    slow->SetNext(nullptr);

    //sort halfes
    a = MergeSortLinkedListRecursive(a, cmp, sum);
    b = MergeSortLinkedListRecursive(b, cmp, sum);

    //merge
    TNode<TBankAccount>* head = nullptr;
    TNode<TBankAccount>* tail = nullptr;

    while (a != nullptr && b != nullptr) {
        sum.comparisons++;
        TNode<TBankAccount>* pick;
        if (cmp(a->GetData(), b->GetData()) < 0) {
            pick = a;
            a = a->GetNext();
        }
        else {
            pick = b;
            b = b->GetNext();
        }
        if (head == nullptr) {
            head = pick;
        }
        else {
            tail->SetNext(pick);
        }
        tail = pick;
    }
    TNode<TBankAccount>* rest = (a != nullptr) ? a : b;
    tail->SetNext(rest);
    return head;
}


//3b) Merge sort
/*Complexity analysis
*Merge sort is a "devide and qounquer" algorithm where elements are devided into smaller sublists, each is sorted recursively, and the sorted sublists are
*merged back togheter by comparing their front elements
*
*CASE      TIME         SPACE
*BEST      O(n Log n)   O(n)
*AVERAGE   O(n log n)   O(n)
*WORST     O(n log n)   O(n)
*
*/
TLinkedList<TBankAccount>* TSort::MergeSortLinkedList(FCompareAccounts cmp, OperationSummary& sum) {
    //init of the summary datafields
    auto start = chrono::steady_clock::now();
    sum.comparisons = 0;
    sum.swaps = 0;
    sum.timeSpentMs = 0.0;

    //new linked list for the return
    TLinkedList<TBankAccount>* copy = new TLinkedList<TBankAccount>(false);

    //copy to new list
    for (TNode<TBankAccount>* n = bankList->GetHead(); n != nullptr; n = n->GetNext()) {
        copy->Append(n->GetData());
    }

    copy->SetHead(MergeSortLinkedListRecursive(copy->GetHead(), cmp, sum));
    TNode<TBankAccount>* last = nullptr;
    for (TNode<TBankAccount>* n = copy->GetHead(); n != nullptr; n = n->GetNext()) {
        last = n;
    }
    copy->SetTail(last);

    auto end = chrono::steady_clock::now();
    sum.timeSpentMs = chrono::duration<double, milli>(end - start).count();
    return copy;
}

//5a) binary search
TBankAccount* TSort::BinarySearch(TBankAccount* key, FCompareAccounts cmp, OperationSummary& sum) {
    auto start = chrono::steady_clock::now();
    sum.comparisons = 0;
    sum.swaps = 0;
    sum.timeSpentMs = 0.0;

    if (arrayIsSorted) {
        TBankAccount* result = BinarySearchRecursive(key, cmp, 0, arraySize - 1, sum);
        auto end = chrono::steady_clock::now();
        sum.timeSpentMs = chrono::duration<double, milli>(end - start).count();
        return result;
    }
    else {
        cout << "List not sorted so a search is not posible at this point" << endl;
        auto end = chrono::steady_clock::now();
        sum.timeSpentMs = chrono::duration<double, milli>(end - start).count();
        return nullptr;
    }
}

TBankAccount* TSort::BinarySearchRecursive(TBankAccount* key, FCompareAccounts cmp, int low, int high, OperationSummary& sum) {
    if (low > high) {
        return nullptr;
    }

    int mid = low + (high - low) / 2;

    int compare = cmp(key, sortedArray[mid]);
    sum.comparisons++;

    if (compare == 0) {
        return sortedArray[mid];
    }
    else if (compare < 0) {
        return BinarySearchRecursive(key, cmp, low, mid - 1, sum);
    }
    else {
        return BinarySearchRecursive(key, cmp, mid+1, high, sum);
    }
}

//5a) Sorts the array by last name, stores it internally and sets the sorted flag
void TSort::SortArrayByLastName(OperationSummary& sum) {
    TBankAccount** sorted = QuickSortArray(CompareByLastName, sum);

    delete[] sortedArray;
    sortedArray = new TBankAccount*[arraySize];
    for (int i = 0; i < arraySize; i++) {
        sortedArray[i] = sorted[i];
    }

    arrayIsSorted = true;
}