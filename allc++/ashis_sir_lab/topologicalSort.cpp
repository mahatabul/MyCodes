#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Add directed edge from u to v
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Utility function for DFS-based topological sort
    void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& Stack) {
        visited[v] = true;

        // Recur for all adjacent vertices
        for (int u : adj[v]) {
            if (!visited[u]) {
                topologicalSortUtil(u, visited, Stack);
            }
        }

        // Push current vertex to stack after visiting all adjacent vertices
        Stack.push(v);
    }

    // DFS-based Topological Sort
    vector<int> topologicalSortDFS() {
        stack<int> Stack;
        vector<bool> visited(V, false);

        // Call recursive helper for all vertices
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, Stack);
            }
        }

        // Extract elements from stack to get topological order
        vector<int> result;
        while (!Stack.empty()) {
            result.push_back(Stack.top());
            Stack.pop();
        }
        return result;
    }

    // BFS-based Topological Sort (Kahn's Algorithm)
    vector<int> topologicalSortBFS() {
        // Calculate in-degree of all vertices
        vector<int> inDegree(V, 0);
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                inDegree[v]++;
            }
        }

        // Queue for vertices with in-degree 0
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;
        int count = 0; // Count of visited vertices

        // Process vertices in topological order
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);

            // Decrease in-degree of adjacent vertices
            for (int v : adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
            count++;
        }

        // Check if there was a cycle (not all vertices processed)
        if (count != V) {
            cout << "Graph contains a cycle! Topological sort not possible." << endl;
            return {};
        }

        return result;
    }

    // Print the adjacency list
    void printGraph() {
        cout << "\nGraph Adjacency List:" << endl;
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int v : adj[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

void printResult(const vector<int>& result, const string& method) {
    cout << "\nTopological Sort using " << method << ": ";
    for (int v : result) {
        cout << v << " ";
    }
    cout << endl;
}

int main() {
    // Example 1: Simple DAG
    cout << "========== Example 1 ==========" << endl;
    Graph g1(6);
    g1.addEdge(5, 2);
    g1.addEdge(5, 0);
    g1.addEdge(4, 0);
    g1.addEdge(4, 1);
    g1.addEdge(2, 3);
    g1.addEdge(3, 1);

    g1.printGraph();
    
    vector<int> result1_dfs = g1.topologicalSortDFS();
    printResult(result1_dfs, "DFS");
    
    // vector<int> result1_bfs = g1.topologicalSortBFS();
    // printResult(result1_bfs, "BFS (Kahn's Algorithm)");

    // // Example 2: Another DAG
    // cout << "\n========== Example 2 ==========" << endl;
    // Graph g2(4);
    // g2.addEdge(0, 1);
    // g2.addEdge(0, 2);
    // g2.addEdge(1, 3);
    // g2.addEdge(2, 3);

    // g2.printGraph();
    
    // vector<int> result2_dfs = g2.topologicalSortDFS();
    // printResult(result2_dfs, "DFS");
    
    // vector<int> result2_bfs = g2.topologicalSortBFS();
    // printResult(result2_bfs, "BFS (Kahn's Algorithm)");

    // // Example 3: Graph with a cycle (will be detected by BFS)
    // cout << "\n========== Example 3 (Cycle) ==========" << endl;
    // Graph g3(3);
    // g3.addEdge(0, 1);
    // g3.addEdge(1, 2);
    // g3.addEdge(2, 0);

    // g3.printGraph();
    // cout << "\nAttempting topological sort on cyclic graph:" << endl;
    // vector<int> result3_bfs = g3.topologicalSortBFS();

    return 0;
}