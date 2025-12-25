#include <bits/stdc++.h>
using namespace std;

vector<int> topoSortBFS(int V, const vector<vector<int>> &adj)
{
    vector<int> inDegree(V, 0);
    for (int u = 0; u < V; u++)
        for (int v : adj[u])
            inDegree[v]++;

    queue<int> q;
    for (int i = 0; i < V; i++)
        if (inDegree[i] == 0)
            q.push(i);

    vector<int> topoOrder;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        for (int v : adj[u])
        {
            inDegree[v]--;
            if (inDegree[v] == 0)
                q.push(v);
        }
    }

    return topoOrder;
}

int main()
{
    int V = 6;
    vector<vector<int>> adj(V);

    // DAG
    adj[5] = {2, 0};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};
    // 0,1 have no outgoing edges

    // BFS Topological Sort
    vector<int> bfsOrder = topoSortBFS(V, adj);
    cout << "Topological Sort (BFS): ";
    for (int x : bfsOrder)
        cout << x << " ";
    cout << endl;

    return 0;
}
