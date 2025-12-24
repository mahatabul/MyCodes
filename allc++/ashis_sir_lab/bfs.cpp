#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Graph {
    // Adjacency list: node -> list of neighbors
    unordered_map<int, vector<int>> adj;

public:
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        // Ensure v exists in the map even if it has no outgoing edges
        if (adj.find(v) == adj.end()) {
            adj[v] = {};
        }
    }

    // 1. Find all reachable nodes using BFS
    void printReachable(int startNode) {
        unordered_map<int, bool> visited;
        queue<int> q;

        q.push(startNode);
        visited[startNode] = true;

        cout << "Nodes reachable from " << startNode << ": ";
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // 2. Find shortest path between two nodes
    void findShortestPath(int start, int target) {
        unordered_map<int, int> parent; // To reconstruct the path
        unordered_map<int, bool> visited;
        queue<int> q;

        q.push(start);
        visited[start] = true;
        parent[start] = -1; // Root node has no parent

        bool found = false;
        while (!q.empty()) {
            int current = q.front();
            q.pop();

            if (current == target) {
                found = true;
                break;
            }

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    parent[neighbor] = current;
                    q.push(neighbor);
                }
            }
        }

        if (found) {
            vector<int> path;
            for (int v = target; v != -1; v = parent[v]) {
                path.push_back(v);
            }
            reverse(path.begin(), path.end());

            cout << "Shortest path from " << start << " to " << target << ": ";
            for (int i = 0; i < path.size(); ++i) {
                cout << path[i] << (i == path.size() - 1 ? "" : " -> ");
            }
            cout << endl;
        } else {
            cout << "No path exists between " << start << " and " << target << endl;
        }
    }
};

int main() {
    Graph g;

    // Example Graph: 0 -> 1, 0 -> 2, 1 -> 3, 2 -> 3, 3 -> 4
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    int start = 0;
    int target = 4;

    g.printReachable(start);
    g.findShortestPath(start, target);

    return 0;
}