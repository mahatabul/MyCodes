#include <bits/stdc++.h>
using namespace std;

// weight, node
typedef pair<int, int> P;

vector<int> Dijkstra(int V, int start, vector<vector<int>> adj[])
{
    priority_queue<P, vector<P>, greater<P>> pq;

    vector<int> distance(V, 1e9);
    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto [dis, node] = pq.top();
        pq.pop();

        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int weight = it[1];

            if (dis + weight < distance[adjNode])
            {
                distance[adjNode] = dis + weight;
                pq.push({distance[adjNode], adjNode});
            }
        }
    }
    return distance;
}

int main()
{
    int V = 4;
    vector<vector<int>> adj[V];

    // 0 -> 1 (1)
    adj[0].push_back({1, 1});
    adj[1].push_back({0, 1});

    // 0 -> 2 (4)
    adj[0].push_back({2, 4});
    adj[2].push_back({0, 4});

    // 1 -> 2 (2)
    adj[1].push_back({2, 2});
    adj[2].push_back({1, 2});

    // 1 -> 3 (5)
    adj[1].push_back({3, 5});
    adj[3].push_back({1, 5});

    // 2 -> 3 (1)
    adj[2].push_back({3, 1});
    adj[3].push_back({2, 1});

    vector<int> dist = Dijkstra(V, 0, adj);

    for (int i = 0; i < V; i++)
        cout << "0 -> " << i << " = " << dist[i] << endl;
}
