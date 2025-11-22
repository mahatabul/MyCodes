// #include <stdio.h>
// #define MAX_VERTICES 100
// #define READY 1
// #define WAITING 2
// #define PROCESSED 3

// int main() {
//   int numVertices = 5;
//   int graph[MAX_VERTICES][MAX_VERTICES] = {0};
//   int status[MAX_VERTICES];

//   graph[0][1] = graph[1][2] = graph[1][4] = 1;
//   graph[3][0] = graph[3][4] = 1;
//   // graph[2][5] = 1;

//   printf("\nDFS Traversal:\n");
//   for (int i = 0; i < numVertices; i++)
//     status[i] = READY;

//   int stack[MAX_VERTICES], top = -1;
//   stack[++top] = 0;

//   while (top >= 0) {
//     int currentVertex = stack[top--];

//     if (status[currentVertex] == READY) {
//       printf("%d ", currentVertex);
//       status[currentVertex] = PROCESSED;

//       for (int i = numVertices - 1; i >= 0; i--) {
//         if (graph[currentVertex][i] && status[i] == READY) {
//           stack[++top] = i;
//         }
//       }
//     }
//   }
//   printf("\n");
//   return 0;
// }




#include <stdio.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int path[MAX_VERTICES];
int visited[MAX_VERTICES];
int numVertices;

void dfs(int current, int pathLen) {
    visited[current] = 1;
    path[pathLen] = current;
    pathLen++;

    int hasUnvisitedChild = 0;
    for (int i = 0; i < numVertices; i++) {
        if (graph[current][i] && !visited[i]) {
            hasUnvisitedChild = 1;
            dfs(i, pathLen);
        }
    }

    if (!hasUnvisitedChild) {
        // Leaf node reached; print the current path
        for (int i = 0; i < pathLen; i++)
            printf("%d ", path[i]);
        printf("\n");
    }

    visited[current] = 0;  // Backtrack
}

int main() {
    numVertices = 5;

    // Initialize the graph
    for (int i = 0; i < numVertices; i++)
        for (int j = 0; j < numVertices; j++)
            graph[i][j] = 0;

    // Define edges
    graph[0][1] = 1;
    graph[1][2] = 1;
    graph[1][4] = 1;
    graph[3][0] = 1;
    graph[3][4] = 1;

    int startNode = 0;

    printf("Paths from node %d:\n", startNode);
    dfs(startNode, 0);

    return 0;
}
