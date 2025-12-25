#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

void printReachableDFS(int start, int V, const vector<vector<int>> &adj)
{
    vector<bool> visited(V, false);
    stack<int> s;

    s.push(start);
    visited[start] = true;
    cout << "Reachable nodes (DFS): ";

    while (!s.empty())
    {
        int curr = s.top();
        s.pop();

        cout << curr << " ";

        for (int neighbor : adj[curr])
        {
            if (!visited[neighbor])
            {
                s.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    cout << endl;
}

// void dfsHelper(int node, vector<bool> &visited, vector<int> &ls, const vector<vector<int>> &adj)
// {
//     visited[node] = true;
//     ls.push_back(node);
//     for (auto it : adj[node])
//     {
//         if (!visited[it])
//         {
//             dfsHelper(it, visited, ls, adj);
//         }
//     }
// }
// vector<int> dfs(int start, int V, const vector<vector<int>> &adj)
// {
//     vector<bool> visited(V, false);
//     vector<int> ls;
//     dfsHelper(start, visited, ls, adj);
//     return ls;
// }
int main()
{
    int V = 6; // Number of vertices
    vector<vector<int>> adj(V);

    // Building a directed graph
    adj[0] = {1, 2};
    adj[1] = {3};
    adj[2] = {3, 4};
    adj[3] = {5};
    adj[4] = {5};
    // 5 has no outgoing edges

    int startNode = 0;
    printReachableDFS(startNode, V, adj);
    

    return 0;
}