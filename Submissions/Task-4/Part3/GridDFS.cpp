//
// Created by mikae on 22.10.2026.
//

#include"GridDFS.h"

//3b)
//Complexity: Time O(N^2) | Space O(N^2)
SearchResult dfsFindZero(const int grid[N][N], Cell start) {
    //init of the struct that keeps track of searched cells
    SearchResult result;
    //tracks cells that are visited
    bool visited[N][N] = {};
    //init of the stack
    TStack stack;

    //push to stack, cells encoded to a single int
    stack.Push(start.row * N + start.col);
    //mark the cell as true to not double visits
    visited[start.row][start.col] = true;

    //neibourgh offsets up down left right
    static const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    while (!stack.isEmpty()) {
        //LIFO: pop the most recently pushed cell, so the search keeps going
        //depper along one path before backtracking
        int code = stack.Peek();
        stack.Pop();
        Cell current = {code/N, code % N }; //decode to cell row instead of int
        result.cellsVisited++;

        //goal check: stop when cell with 0
        if (grid[current.row][current.col] == 0) {
            result.found = true;
            result.where = current;
            return result;
        }

        //push all unvisited neigbhourgs that lie inside grid
        for (int i = 0; i < 4; i++) {
            int nr = current.row + dirs[i][0];
            int nc = current.col + dirs[i][1];
            if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visited[nr][nc]) {
                visited[nr][nc] = true;
                stack.Push(nr * N + nc);
            }
        }
    }
    return result;
}
