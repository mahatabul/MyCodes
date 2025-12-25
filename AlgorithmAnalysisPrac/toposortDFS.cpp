#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfsTopo(int node, vector<bool> &visited, stack<int> &st, const vector<vector<int>> &adj)
{
    visited[node] = true;

    for (int nbr : adj[node])
        if (!visited[nbr])
            dfsTopo(nbr, visited, st, adj);

    // push after visiting all neighbors
    st.push(node);
}

vector<int> topoSortDFS(int V, const vector<vector<int>> &adj)
{
    vector<bool> visited(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfsTopo(i, visited, st, adj);

    vector<int> topoOrder;
    while (!st.empty())
    {
        topoOrder.push_back(st.top());
        st.pop();
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

    // DFS Topological Sort
    vector<int> dfsOrder = topoSortDFS(V, adj);
    cout << "Topological Sort (DFS): ";
    for (int x : dfsOrder)
        cout << x << " ";
    cout << endl;

    return 0;
}
