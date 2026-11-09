3d) Compare and contrast (key differences between DFS and DBS ALGORITHMS)

1) DFS (depth-first Search) algorithms uses a Stack who key principles are Last-in-first-out. A DFS takes a route as deep as possible before backtracking. While BFS(Breadth-first Search) Uses a queue who key principle is First-in-First-out. A DBS explores the grid level by level, so all cells at one level is explored before any at the next level. Both algorithms runs at O(N^2) time. Becuase BFS searches level by level, the first 0 it finds is garranteed to be the closest one. Where as DFS does not garuentee this.


2) SCENARIO

    BFS is a better choice for finding the shortest path between two points, for example nearest exit in a maze. DFS would be better if all posibilities or if less memory is needed because it only holds the current path.