#include "../include/graph.h"

void Graph::addEdge(int u, int v) {
    this->adjList[u].push_back(v);

    if (!this->directed) {
        this->adjList[v].push_back(u);
    }
}

void Graph::showGraph() {
    for (int i = 1; i <= this->nVertex; ++i) {
        std::cout << "Adjacency list of " << i << ": ";
        for (auto v : this->adjList[i]) {
            std::cout << v << " ";
        }

        std::cout << "\n";
    }
}

void Graph::dfs(int root) {
    this->visited[root] = true;
    std::cout << root << " ";
    for (auto neighbor : this->adjList[root]) {
        if (!this->visited[neighbor]) {
            this->dfs(neighbor);
        }
    }
}
