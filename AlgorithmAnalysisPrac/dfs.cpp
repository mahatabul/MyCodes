#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph {
    // Adjacency list: node -> list of neighbors
    unordered_map<int, vector<int>> adj;

    // Helper function for recursion
    void dfsHelper(int current, unordered_set<int>& visited) {
        // Mark the current node as visited and print it
        visited.insert(current);
        cout << current << " ";

        // Recur for all the vertices adjacent to this vertex
        for (int neighbor : adj[current]) {
            if (visited.find(neighbor) == visited.end()) {
                dfsHelper(neighbor, visited);
            }
        }
    }

public:
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        // Ensure v exists in the map
        if (adj.find(v) == adj.end()) {
            adj[v] = {};
        }
    }

    // Print all nodes reachable from startNode
    void printReachableDFS(int startNode) {
        unordered_set<int> visited;
        
        cout << "Nodes reachable from " << startNode << " (using DFS): ";
        // Check if the start node actually exists in our graph
        if (adj.find(startNode) != adj.end() || !adj.empty()) {
            dfsHelper(startNode, visited);
        }
        cout << endl;
    }
};

int main() {
    Graph g;

    // Example Graph:
    // 0 -> 1, 0 -> 2
    // 1 -> 3
    // 2 -> 4
    // 3 -> 0 (cycle)
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 0); 

    int start = 0;
    g.printReachableDFS(start);

    return 0;
}