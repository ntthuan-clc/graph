#include "../include/graph.h"

Graph::Graph() {
    this->nVertex = 0;
    this->nEdge = 0;
    this->directed = false;

    this->visited = new bool[nVertex + 1];
    for (int i = 0; i <= nVertex; ++i) {
        this->visited[i] = false;
    }

    this->parent = new int[nVertex + 1];
    for (int i = 0; i <= nVertex; ++i) {
        this->parent[i] = 0;
    }

    this->adjList = new std::vector<int>[nVertex + 1];
}

Graph::Graph(int nVertex, int nEdge, bool directed) {
    this->nVertex = nVertex;
    this->nEdge = nEdge;
    this->directed = directed;

    this->visited = new bool[nVertex + 1];
    for (int i = 0; i <= nVertex; ++i) {
        this->visited[i] = false;
    }

    this->parent = new int[nVertex + 1];
    for (int i = 0; i <= nVertex; ++i) {
        this->parent[i] = 0;
    }

    this->adjList = new std::vector<int>[nVertex + 1];
}

Graph::~Graph() {
    delete[] this->adjList;
    this->adjList = nullptr;

    delete[] this->visited;
    this->visited = nullptr;

    delete[] this->parent;
    this->parent = nullptr;
}