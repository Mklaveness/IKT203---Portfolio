//
// Created by mikae on 22.10.2026.
//
#include"TwoDimensionalGrid.h"

//3a)
//grid initializaion that initialized the grid and puts a random number in each cell as well as a random start grid
//Complexity: Time O(N^2) | Space O(N^2)
Grid gridInit() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> valueDist(0, 9);
    uniform_int_distribution<int> indexDist(0, N - 1);

    //100x100 two-dimensional int grid
    Grid g;
    //populate with random values between 0, 9
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            g.cells[i][j] = valueDist(gen);
        }
    }

    //create a random start cell
    g.start = {indexDist(gen), indexDist(gen)};

    //output for telling start and value of start
    cout << "Starting cell: (" << g.start.row << ", " << g.start.col << ")\n";
    cout << "Value of starting cell: " << g.cells[g.start.row][g.start.col] << "\n";

    return g;
}
