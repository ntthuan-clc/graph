#include "../include/graph.h"

#include <algorithm>

#include "../include/dsu.h"

void Graph::addEdge(int u, int v) {
    this->adjList[u].push_back(v);

    if (!this->directed) {
        this->adjList[v].push_back(u);
    }
}

void Graph::addEdge(int u, int v, int w) {
    this->adjWList[u].push_back(std::make_pair(w, v));
    if (!this->directed) {
        this->adjWList[v].push_back(std::make_pair(w, u));
    }
}

void Graph::showAdjList() {
    for (int i = 1; i <= this->nVertex; ++i) {
        std::cout << "Adjacency list of " << i << ": ";
        for (auto v : this->adjList[i]) {
            std::cout << v << " ";
        }

        std::cout << "\n";
    }
}

void Graph::showAdjWList() {
    for (int i = 1; i <= this->nVertex; ++i) {
        std::cout << "Adjacency list of (with weight) " << i << ": ";
        for (auto t : this->adjWList[i]) {
            std::cout << t.first << " " << t.second << "\n";
        }
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

void Graph::dijkstra(int src, int dest) {
    int* cost = new int[this->nVertex + 1];
    for (int i = 0; i <= this->nVertex; ++i) {
        cost[i] = INF;
    }

    cost[src] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >,
                        std::greater<std::pair<int, int> > >  // greater mean
                                                              // sort allow
                                                              // asending
        pQueue;

    pQueue.push(std::make_pair(0, src));
    while (!pQueue.empty()) {
        int currVertex = pQueue.top().second;
        int costToCurrVertex = pQueue.top().first;
        pQueue.pop();

        if (currVertex == dest) {
            break;
        }

        for (auto child : this->adjWList[currVertex]) {
            int neighbor = child.second;
            int costToNeighbor = child.first;

            int totalCostToNeighbor = costToCurrVertex + costToNeighbor;
            if (cost[neighbor] > totalCostToNeighbor) {
                cost[neighbor] = totalCostToNeighbor;
                pQueue.push(std::make_pair(cost[neighbor], neighbor));
                parent[neighbor] = currVertex;
            }
        }
    }
    std::cout << "total cost: " << cost[dest] << "\n";

    while (dest != src) {
        std::cout << dest << "->";
        dest = this->parent[dest];
    }

    std::cout << src;
}

void Graph::kruskal() {
    std::vector<std::pair<int, std::pair<int, int> > > edges;
    for (int i = 1; i <= this->nVertex; ++i) {
        for (auto t : this->adjWList[i]) {
            edges.push_back(
                std::make_pair(t.first, std::make_pair(i, t.second)));
        }
    }

    sort(edges.begin(), edges.end());
    // for (auto edge : edges) {
    //     std::cout << edge.first << " "
    //               << "(" << edge.second.first << " , " << edge.second.second
    //               << ")\n";
    // }
    // // std::cout << edges.size();
    // // return;
    int cost = 0;
    DSU dsu(this->nVertex);
    for (auto edge : edges) {
        int u = edge.second.first;
        int v = edge.second.second;

        int setU = dsu.find(u);
        int setV = dsu.find(v);

        if (setU != setV) {
            std::cout << u << " " << v << "\n";
            cost += edge.first;
            dsu.merge(u, v);
        }
    }
    std::cout << "Cost: " << cost;
}