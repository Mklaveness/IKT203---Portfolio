#include<iostream>
using namespace std;

//includes
#include"Part1/TStack.h"
#include"Part1/TQueue.h"

#include"Part2/StringReversal.h"
#include"Part2/Factorial.h"
#include"Part2/WaitLine.h"

#include"Part3/TwoDimensionalGrid.h"
#include"Part3/GridDFS.h"
#include"Part3/GridBFS.h"

//note to self:
//Stack:
//LIFO(last in first out) a datastructure for storing data
//analogy: a pile of plates can take the top one.
//main operations: push(x) top of the stack, pop() take out of stack, peek()/top() see top element, isEmpty() check if empty ALL OF THESE O(1)

//queues:
//FIFO(first in first out) a datastructure for storing data
//analogy: a queue at the grocery store.
//main operations: enqueue(x) puts x at the back of the queue, dequeue() removes the last item in the queue, peek()/front() look at the first element, isEmpty() ALL OF THESE O(1)


//TASK REQUIREMENTS
//* ALL CODE AND COMMENTS: ENGLISH
//* FIXED SIZE ARRAYS: INT CONST AS MAX_SIZE AND PRIMITIVE DATATYPES(INT)
//* COMPLEXITY ANALYSIS FOR THE ALGORITHMS THAT ARE TO BE MADE


int main() {
    //test the TStack
    TStack s;
    if (s.isEmpty()) {
        cout << "helt tom" << endl;
    }
    else {
        cout << "ikke tom ass" << endl;
    }
    for (int i = 0; i < 10; i++) {
        s.Push(i);
    }
    cout << s.Peek() << endl;
    s.Pop();
    cout << s.Peek() << endl;
    if (s.isEmpty()) {
        cout << "helt tom" << endl;
    }
    else {
        cout << "ikke tom ass" << endl;
    }

    //test the queue
    TQueue q;
    if (q.isEmpty()) {
        cout << "helt tom" << endl;
    }
    else {
        cout << "ikke tom ass" << endl;
    }
    for (int i = 0; i < 10; i++) {
        q.Enqueue(i);
    }
    cout << q.Peek() << endl;

    q.Dequeue();

    cout << q.Peek() << endl;

    if (q.isEmpty()) {
        cout << "helt tom" << endl;
    }
    else {
        cout << "ikke tom ass" << endl;
    }

    string y = "hello";
    cout << stringReversal(y) << endl;

    cout << factorialStack(7) << endl;

    waitLine(5);

    Grid g = gridInit();
    SearchResult dfs = dfsFindZero(g.cells, g.start);
    SearchResult dbs = dbsFindZero(g.cells, g.start);
    if (dfs.found) {
        cout << "DFS found 0 at (" << dfs.where.row << ", " << dfs.where.col << ") after " << dfs.cellsVisited << " cells\n";
    }
    else {
        cout << "DFS found no zeroes\n";
    }

    if (dbs.found) {
        cout << "DBS found 0 at (" << dbs.where.row << ", " << dbs.where.col << ") after " << dbs.cellsVisited << " cells\n";
    }
    else {
        cout << "DBS found no zeroes\n";
    }

    return 0;
}