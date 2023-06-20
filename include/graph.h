#pragma once

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
const int INF = 1e9 + 7;
class Graph {
   private:
    int nVertex, nEdge;
    bool directed;
    bool* visited;
    int* parent;
    std::vector<int>* adjList;
    std::vector<std::pair<int, int> >* adjWList;  // have weight
   public:
    Graph();
    Graph(int, int, bool);
    ~Graph();

    void resetVisited();
    void addEdge(int, int);
    void addEdge(int, int, int);
    void showAdjList();
    void showAdjWList();
    void dfs(int);  // recursion
    void dfsLinear(int);

    void bfs(int);

    void bfs(int, int);
    void dfs(int, int);
    void dijkstra(int, int);
    void kruskal();
};