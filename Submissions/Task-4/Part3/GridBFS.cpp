//
// Created by mikae on 22.10.2026.
//
#include"GridBFS.h"

//3c)
//Complexity: Time O(N^2) | Space O(N^2)
SearchResult dbsFindZero(const int grid[N][N], Cell start) {
    //init of the struct that keeps track of searched cells
    SearchResult result;
    //tracks cells that are visited
    bool visited[N][N] = {};
    //init of the stack
    TQueue que;

    //put cell to back of queue, cells encoded to a single int
    que.Enqueue(start.row * N + start.col);
    //mark the cell as true to not double visits
    visited[start.row][start.col] = true;

    //neibourgh offsets up down left right
    static const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    while (!que.isEmpty()) {
        //FIFO: take the oldest cell in the queue, so all cells at distance d
        //are processed before any cell at distance d+1 (level by level)
        int code = que.Peek();
        que.Dequeue();
        Cell current = {code / N, code % N }; //decode to row, col
        result.cellsVisited++;

        //check if current = cell with zero
        if (grid[current.row][current.col] == 0) {
            result.found = true;
            result.where = current;
            return result;
        }

        //enqueue all unvisited neighbours that lie inside the grid
        for (int i = 0; i < 4; i++) {
            int nr = current.row + dirs[i][0];
            int nc = current.col + dirs[i][1];
            if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visited[nr][nc]) {
                visited[nr][nc] = true;
                que.Enqueue(nr * N + nc);
            }
        }
    }
    return result;
}