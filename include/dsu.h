class DSU {
   private:
    int *parent, *rank;
    int n;  // n vEdge

   public:
    DSU(int n) {
        this->n = n;
        this->parent = new int(n + 1);
        this->rank = new int[n + 1];

        for (int i = 0; i < this->n; ++i) {
            this->rank[i] = 0;
            this->parent[i] = i;
        }
    }

    int find(int vertex) {
        if (vertex != this->parent[vertex]) {
            this->parent[vertex] = this->find(parent[vertex]);
        }
        return this->parent[vertex];
    }

    void merge(int u, int v) {
        v = this->find(v);
        u = this->find(u);

        if (u != v) {
            if (this->rank[u] > this->rank[v]) {
                this->parent[v] = u;
            } else {
                this->parent[u] = v;
            }

            if (this->rank[u] == this->rank[v]) {
                rank[u] += 1;
            }
        }
    };
};
