#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph
{
private:
    int size;
    vector<vector<int>> adj;

public:
    Graph(int s)
    {
        this->size = s;
        adj.resize(s);
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void topSort(int v, vector<int> &visited, vector<vector<int>> &adj, stack<int> &st)
    {
        visited[v] = 1;
        for (int it : adj[v])
        {
             if (!visited[it])
            {
                topSort(it, visited, adj, st);
            }
        }
        st.push(v);
    }
    vector<int> DFS()
    {
        vector<int> visited(size, 0);
        stack<int> st;

        for (int i = 0; i < size; i++)
        {
            if (!visited[i])
            {
                topSort(i, visited, adj, st);
            }
        }
        vector<int> result;
        while (!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
    void printGraph()
    {
        cout << "\nGraph Adjacency List:" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << i << " -> ";
            for (int v : adj[i])
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g1(6);
    g1.addEdge(5, 2);
    g1.addEdge(5, 0);
    g1.addEdge(4, 0);
    g1.addEdge(4, 1);
    g1.addEdge(2, 3);
    g1.addEdge(3, 1);

    g1.printGraph();

    vector<int> result = g1.DFS();
    cout << "Result using DFS:\n";
    for (int v : result)
    {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}