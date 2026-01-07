#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> T;

vector<int> bellmanFord(int V, int src, vector<T> &edges)
{
    const int INF = 1e9;
    vector<int> dist(V, INF);
    dist[src] = 0;

    // Relax edges V-1 times
    for (int i = 0; i < V - 1; i++)
    {
        for (auto [u, v, wt] : edges)
        {
            if (dist[u] != INF && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative cycle
    for (auto [u, v, wt] : edges)
    {
        if (dist[u] != INF && dist[u] + wt < dist[v])
        {
            return {-1}; // Negative cycle detected
        }
    }

    return dist;
}

int main()
{
    int V = 5;
    vector<T> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };

    vector<int> result = bellmanFord(V, 0, edges);
    
    if (result.size() == 1 && result[0] == -1)
    {
        cout << "Negative cycle detected!\n";
    }
    else
    {
        cout << "Shortest distances from source 0:\n";
        for (int i = 0; i < V; i++)
        {
            cout << "Node " << i << ": ";
            if (result[i] == 1e9)
                cout << "INF\n";
            else
                cout << result[i] << "\n";
        }
    }

    return 0;
}