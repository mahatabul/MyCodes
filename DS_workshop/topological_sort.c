#include <stdio.h>
#define MAX_VERTICES 100
#define READY 1
#define PROCESSED 2

int numVertices = 6;
int graph[MAX_VERTICES][MAX_VERTICES] = {0};
int status[MAX_VERTICES];
int stack[MAX_VERTICES];
int top = -1;

// Push node onto stack (for final ordering)
void push(int node) {
    stack[++top] = node;
}

// DFS utility function for topological sort
void dfs(int node) {
    status[node] = PROCESSED;

    for (int i = 0; i < numVertices; i++) {
        if (graph[node][i] && status[i] == READY) {
            dfs(i);
        }
    }

    push(node);  // After visiting all neighbors, push to stack
}

int main() {
    // Example DAG:
    // A (0) -> B (1), C (2)
    // B -> D (3), E (4)
    // C -> F (5)

    graph[0][1] = 1; // A -> B
    graph[0][2] = 1; // A -> C
    graph[1][3] = 1; // B -> D
    graph[1][4] = 1; // B -> E
    graph[2][5] = 1; // C -> F

    for (int i = 0; i < numVertices; i++) {
        status[i] = READY;
    }

    for (int i = 0; i < numVertices; i++) {
        if (status[i] == READY) {
            dfs(i);
        }
    }

    printf("Topological Sort:\n");
    while (top >= 0) {
        printf("%c ", 'A' + stack[top--]);  // Convert index to char (e.g., 0 -> A)
    }
    printf("\n");

    return 0;
}
