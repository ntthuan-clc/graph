#pragma once

#include <iostream>
#include <vector>

class Graph {
   private:
    int nVertex, nEdge;
    bool directed;
    bool* visited;
    std::vector<int>* adjList;

   public:
    Graph();
    Graph(int, int, bool);
    ~Graph();

    void addEdge(int, int);
    void showGraph();
    void dfs(int);
};