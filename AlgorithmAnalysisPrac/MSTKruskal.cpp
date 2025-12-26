#include <bits/stdc++.h>
using namespace std;

// Disjoint Set (Union-Find) with Union by Size + Path Compression
class DSU {
public:
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findSet(int v) {
        if (parent[v] == v)
            return v;
        return parent[v] = findSet(parent[v]); // path compression
    }

    bool unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);

        if (a == b)
            return false; // already in same set

        // Union by size
        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

int main() {
    int V = 5;

    // Convert adjacency list into an edge list
    // (u, v, w)
    vector<tuple<int, int, int>> edges;
    edges.push_back({2, 0, 1});
    edges.push_back({3, 0, 3});
    edges.push_back({1, 1, 2});
    edges.push_back({4, 1, 4});
    edges.push_back({5, 2, 4});
    edges.push_back({6, 3, 4});

    // Sort edges by weight
    sort(edges.begin(), edges.end(),
         [](auto &a, auto &b) {
             return get<0>(a) < get<0>(b);
         });

    DSU dsu(V);

    vector<pair<int, int>> mstEdges;
    int totalCost = 0;

    for (auto &e : edges) {
        int w, u, v;
        tie(w, u, v) = e;

        // Check if adding this edge forms a cycle
        if (dsu.unionSet(u, v)) {
            mstEdges.push_back({u, v});
            totalCost += w;
        }
    }

    cout << "Edges in MST:" << endl;
    for (auto &p : mstEdges) {
        cout << p.first << " - " << p.second << endl;
    }

    cout << "Total cost of MST = " << totalCost << endl;
    return 0;
}
