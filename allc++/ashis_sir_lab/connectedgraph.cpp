#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V; 
    vector<vector<int>> adj; 

public:
    Graph(int vertices) : V(vertices), adj(vertices) {}
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    
    void DFS(int start, vector<bool>& visited) {
        stack<int> st;
        st.push(start);
        visited[start] = true;
        
        while (!st.empty()) {
            int current = st.top();
            st.pop();
            
            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    st.push(neighbor);
                }
            }
        }
    }
    
    bool isConnected() {
        if (V == 0) return true;
        
        vector<bool> visited(V, false);
        
        DFS(0, visited);
        
       
        for (bool v : visited) {
            if (!v) return false;
        }
        return true;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    
    Graph g(V);
    
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    
    if (g.isConnected()) {
        cout << "The graph is connected." << endl;
    } else {
        cout << "The graph is not connected." << endl;
    }
    
    return 0;
}