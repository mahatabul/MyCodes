#include <bits/stdc++.h>
using namespace std;
// u, v , weight
typedef tuple<int, int, int> T;

vector<int> bellmanFord(int V, int src, vector<T> &edges)
{
    vector<int> dist(V, 1e9);
    dist[src] = 0;

    // Relax edges n-1 times
    for (int i = 0; i < V - 1; i++)
    {
        for (auto e : edges)
        {
            auto [u, v, wt] = e;
            if (dist[u] != 1e9 && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // nth check for negative cycle
    for (auto e : edges)
    {
        auto [u, v, wt] = e;
        if (dist[u] != 1e9 && dist[u] + wt < dist[v])
        {
            return {-1};
        }
    }

    return dist;
}

int main()
{
    int V = 5;
    vector<T> edges;

    edges.push_back({0, 1, -1});
    edges.push_back({0, 2, 4});
    edges.push_back({1, 2, 3});
    edges.push_back({1, 3, 2});
    edges.push_back({1, 4, 2});
    edges.push_back({3, 2, 5});
    edges.push_back({3, 1, 1});
    edges.push_back({4, 3, -3});

    bellmanFord(V, 0, edges);

    return 0;
}
