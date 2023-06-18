#include "../include/graph.h"

int main() {
    Graph g(9, 15, 0);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 5);
    g.addEdge(3, 6);
    g.addEdge(4, 7);
    g.addEdge(4, 8);
    g.addEdge(5, 7);
    g.addEdge(5, 8);
    g.addEdge(6, 7);
    g.addEdge(6, 8);
    g.addEdge(7, 8);
    g.addEdge(8, 9);

    g.dfs(1);
    return 0;
}