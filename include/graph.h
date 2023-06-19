#pragma once

#include <iostream>
#include <queue>
#include <stack>
#include <vector>

class Graph {
   private:
    int nVertex, nEdge;
    bool directed;
    bool* visited;
    int* parent;
    std::vector<int>* adjList;

   public:
    Graph();
    Graph(int, int, bool);
    ~Graph();

    void resetVisited();
    void addEdge(int, int);
    void showGraph();
    void dfs(int);  // recursion
    void dfsLinear(int);

    void bfs(int);

    void bfs(int, int);
    void dfs(int, int);
};