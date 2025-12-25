#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<bool> &visited, const vector<vector<int>> &adj)
{
    visited[node] = true;

    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, visited, adj);
        }
    }
}

bool connected(int start, int V, vector<vector<int>> &adj)
{
    vector<bool> visited(V, false);

    // Start DFS from vertex 0
    dfs(start, visited, adj);

    // Check if all vertices are visited
   
    for (bool v : visited)
    {
        if (!v)
        {
            return false;
            break;
        }
    }
    return true;
}

int main()
{
    int V = 5; // number of vertices
    vector<vector<int>> adj(V);

    // Undirected graph
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0};
    adj[3] = {1, 4};
    adj[4] = {3};
    bool c = connected(1, V, adj);

    if (c)
        cout << "Graph is Connected" << endl;
    else
        cout << "Graph is Not Connected" << endl;

    return 0;
}
