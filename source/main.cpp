#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#include "../include/graph.h"

int main() {
    Graph g(9, 15, 0);
    g.addEdge(1, 2, 10);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 15);
    g.addEdge(2, 5, 10);
    g.addEdge(2, 6, 12);
    g.addEdge(3, 5, 15);
    g.addEdge(3, 6, 7);
    g.addEdge(4, 7, 9);
    g.addEdge(4, 8, 13);
    g.addEdge(5, 7, 12);
    g.addEdge(5, 8, 8);
    g.addEdge(6, 7, 22);
    g.addEdge(6, 8, 15);
    g.addEdge(7, 9, 9);
    g.addEdge(8, 9, 5);

    g.kruskal();

    return 0;
}