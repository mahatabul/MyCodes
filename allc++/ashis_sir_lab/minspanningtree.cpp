// Prims Algorithm

#include <bits/stdc++.h>
using namespace std;

#define N 4

int main()
{
    int graph[N][N] = {0};
    memset(graph, 0, sizeof(graph));

    graph[0][1] = graph[1][0] = 2;
    graph[0][2] = graph[2][0] = 4;
    graph[2][3] = graph[3][2] = 1;
    graph[1][3] = graph[3][1] = 3;

    int visited[N][N];
    memset(visited, -1, sizeof(visited));

    int start = 0;
    vector<int> tree;

    tree.push_back(start);

    int j = 1;
    int cur = start;
    while (j < N)
    {

        int minpath = INT_MAX;
        int minNode = INT_MAX;

        for (int i = 0; i < N; i++)
        {
            if (i != cur && graph[cur][i] && minpath >= graph[cur][i] && visited[cur][i] == -1)
            {
                minpath = graph[cur][i];
                minNode = i;
            }
        }

        if (minNode == INT_MAX)
            break;

        tree.push_back(minNode);
        visited[cur][minNode] = 1;
        visited[minNode][cur] = 1;
        cur = minNode;

        j++;
    }
    j = 0;
    int treesize = tree.size();
    for (auto it : tree)
    {
        cout << char(it + 'a');
        if (j < treesize - 1)
        {
            cout << "->";
        }
        j++;
    }
    return 0;
}
