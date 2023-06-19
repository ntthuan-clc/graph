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

void Graph::resetVisited() {
    for (int i = 0; i <= this->nVertex; ++i) {
        this->visited[i] = false;
    }
}
void Graph::dfsLinear(int root) {
    this->visited[root] = true;
    std::stack<int> stk;
    stk.push(root);

    while (!stk.empty()) {
        int currVisit = stk.top();
        stk.pop();
        std::cout << currVisit << " ";

        for (auto neighbor : this->adjList[currVisit]) {
            if (!visited[neighbor]) {
                stk.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

void Graph::bfs(int root) {
    this->visited[root] = true;
    std::queue<int> que;
    que.push(root);

    while (!que.empty()) {
        int currVisit = que.front();
        que.pop();
        std::cout << currVisit << " ";

        for (auto neighbor : this->adjList[currVisit]) {
            if (!this->visited[neighbor]) {
                que.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

void Graph::bfs(int src, int dest) {
    this->visited[src] = true;

    std::queue<int> que;
    que.push(src);

    while (!que.empty()) {
        int currVisit = que.front();
        que.pop();

        if (currVisit == dest) {
            break;
        }

        for (auto neighbor : this->adjList[currVisit]) {
            if (!this->visited[neighbor]) {
                que.push(neighbor);
                this->visited[neighbor] = true;
                this->parent[neighbor] = currVisit;
            }
        }
    }

    if (!this->visited[dest]) {
        std::cout << "Cannot find !!!";
        return;
    }

    while (dest != src) {
        std::cout << dest << "->";
        dest = this->parent[dest];
    }
    std::cout << src;
}

void Graph::dfs(int src, int dest) {
    this->visited[src] = true;
    std::stack<int> stk;
    stk.push(src);

    while (!stk.empty()) {
        int currVisit = stk.top();
        stk.pop();

        if (currVisit == dest) {
            break;
        }
        for (auto neighbor : this->adjList[currVisit]) {
            if (!this->visited[neighbor]) {
                stk.push(neighbor);
                this->visited[neighbor] = true;
                this->parent[neighbor] = currVisit;
            }
        }
    }

    if (!this->visited[dest]) {
        std::cout << "Cannot find !!!";
        return;
    }

    while (dest != src) {
        std::cout << dest << "->";
        dest = this->parent[dest];
    }
    std::cout << src;
}
