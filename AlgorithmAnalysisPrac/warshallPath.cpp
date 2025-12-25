#include <iostream>
using namespace std;

#define V 4

void warshall(int graph[V][V])
{
    int path[V][V];

    // Initialize path matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            path[i][j] = graph[i][j];

    // Warshall's Algorithm
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                path[i][j] = path[i][j] || (path[i][k] && path[k][j]);

    // Print path matrix
    cout << "Path Matrix:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            cout << path[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int graph[V][V] = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    warshall(graph);
    return 0;
}
