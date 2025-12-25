#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

// 1. BFS to find the shortest path between two nodes
void findShortestPath(int start, int target, int V, const vector<vector<int>> &adj)
{
    vector<int> parent(V, -1);
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    bool found = false;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (curr == target)
        {
            found = true;
            break;
        }

        for (int neighbor : adj[curr])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                parent[neighbor] = curr;
                q.push(neighbor);
            }
        }
    }

    if (found)
    {
        vector<int> path;
        for (int v = target; v != -1; v = parent[v])
            path.push_back(v);
        reverse(path.begin(), path.end());

        cout << "Shortest Path (BFS): ";
        for (int i = 0; i < path.size(); i++)
            cout << path[i] << (i == path.size() - 1 ? "" : " -> ");
        cout << endl;
    }
    else
    {
        cout << "No path exists between " << start << " and " << target << endl;
    }
}

void printReachableBFS(int start, int V, const vector<vector<int>> &adj)
{

    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);
    cout << "Reachable nodes (BFS): ";
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for (int neighbor : adj[curr])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    int V = 7; // Number of vertices
    vector<vector<int>> adj(V);

    // Building a directed graph
    adj[0] = {1, 2};
    adj[1] = {3};
    adj[2] = {3, 4};
    adj[3] = {5};
    adj[4] = {6};
    adj[6] = {5};

    int startNode = 0;
    int targetNode = 5;

    // findShortestPath(startNode, targetNode, V, adj);
    printReachableBFS(startNode, V, adj);

    return 0;
}