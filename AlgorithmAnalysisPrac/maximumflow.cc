#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int n; // number of vertices
int capacity[MAX][MAX];
int flowPassed[MAX][MAX];
vector<int> adj[MAX];

bool dfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    stack<int> st;
    st.push(s);
    parent[s] = s;

    while(!st.empty()) {
        int u = st.top(); st.pop();
        for(int v : adj[u]) {
            if(parent[v] == -1 && capacity[u][v] - flowPassed[u][v] > 0) {
                parent[v] = u;
                if(v == t) return true;
                st.push(v);
            }
        }
    }
    return false;
}

int fordFulkerson(int s, int t) {
    int maxFlow = 0;
    vector<int> parent(n);

    while(dfs(s, t, parent)) {
        int pathFlow = INT_MAX;

        // Find minimum residual capacity in the path
        for(int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, capacity[u][v] - flowPassed[u][v]);
        }

        // Update flow along the path
        for(int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            flowPassed[u][v] += pathFlow;
            flowPassed[v][u] -= pathFlow; // reverse flow
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    // Example graph
    n = 6;
    int s = 0, t = 5;

    // Adding edges and capacities
    auto addEdge = [&](int u, int v, int cap) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v] = cap;
    };

    addEdge(0, 1, 16);
    addEdge(0, 2, 13);
    addEdge(1, 2, 10);
    addEdge(1, 3, 12);
    addEdge(2, 1, 4);
    addEdge(2, 4, 14);
    addEdge(3, 2, 9);
    addEdge(3, 5, 20);
    addEdge(4, 3, 7);
    addEdge(4, 5, 4);

    cout << "Maximum Flow: " << fordFulkerson(s, t) << endl;
    return 0;
}
