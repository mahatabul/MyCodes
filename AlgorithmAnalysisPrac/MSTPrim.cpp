#include <bits/stdc++.h>
using namespace std;

// weight,node,parent
typedef tuple<int, int, int> T;
// node,weight
typedef pair<int, int> P;

tuple<vector<vector<P>>, int> primMST(int start, int V, vector<vector<P>> &adj)
{
    vector<bool> vis(V, false);

    priority_queue<T, vector<T>, greater<T>> pq;
    vector<vector<P>> ans(V);
    int tcost = 0;

    pq.push({0, start, -1});
    while (!pq.empty())
    {
        auto [weight, node, parent] = pq.top();
        pq.pop();

        if (vis[node])
        {
            continue;
        }
        vis[node] = true;
        tcost += weight;
        if (parent != -1)
        {
            ans[parent].push_back({node, weight});
            ans[node].push_back({parent, weight});
        }

        for (auto it : adj[node])
        {
            int n = it.first;
            int w = it.second;
            if (!vis[n])
            {
                pq.push({w, n, node});
            }
        }
    }
    return {ans, tcost};
}

int main()
{
    int V = 5;
    vector<vector<P>> adj(V);

    // Undirected weighted graph
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 3});
    adj[3].push_back({0, 3});

    adj[1].push_back({2, 1});
    adj[2].push_back({1, 1});

    adj[1].push_back({4, 4});
    adj[4].push_back({1, 4});

    adj[2].push_back({4, 5});
    adj[4].push_back({2, 5});

    adj[3].push_back({4, 6});
    adj[4].push_back({3, 6});

    auto [ans, cost] = primMST(0, V, adj);

    cout << "Cost = " << cost << endl;
    cout << "Edges in MST:\n";

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            int v = ans[i][j].first;
            int w = ans[i][j].second;

            if (i < v) // print each edge once
            {
                cout << i << " -> " << v
                     << " Weight: " << w << endl;
            }
        }
    }

    return 0;
}