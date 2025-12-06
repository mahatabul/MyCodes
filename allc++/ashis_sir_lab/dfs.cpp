#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
  int V;                   // Number of vertices
  vector<vector<int>> adj; // Adjacency list

public:
  Graph(int vertices) : V(vertices), adj(vertices) {}

  void addEdge(int u, int v) { adj[u].push_back(v); }

  void DFS(int start) {
    vector<bool> visited(V, false);
    stack<int> st;

    st.push(start);
    visited[start] = true;

    cout << "Nodes reachable from node " << start << ": ";

    while (!st.empty()) {
      int current = st.top();
      st.pop();

      cout << current << " ";

      for (int neighbor : adj[current]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          st.push(neighbor);
        }
      }
    }
    cout << endl;
  }
};

int main() {
  Graph g(6);

  // Adding edges to create a directed graph
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(2, 4);
  g.addEdge(3, 5);
  g.addEdge(4, 5);

  int startNode;
  cout << "Enter starting node: ";
  cin >> startNode;

  g.DFS(startNode);

  return 0;
}