//
// Created by mikae on 22.10.2026.
//

#ifndef STACKSANDQUES_TWODIMENSIONALGRID_H
#define STACKSANDQUES_TWODIMENSIONALGRID_H
#include<iostream>
#include<random>
using namespace std;

//3a) 100x100 grid
//a constant for the grid levels
const int N = 100;
//structure that holds row and colum saved ass one to easier manage
struct Cell{ int row, col;};
//structure that holds the grid with the cell of start
struct Grid {
    int cells[N][N];
    Cell start;
};
//function to initialise the grid
Grid gridInit();

//3b/c)
//struct to keep track of the searched cells
struct SearchResult {
    bool found = false;
    Cell where{-1, -1};
    int cellsVisited = 0;
};

#endif //STACKSANDQUES_TWODIMENSIONALGRID_H
