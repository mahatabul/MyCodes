#include <stdio.h>

#define MAX_VERTICES 26  // A-Z
#define READY 1
#define WAITING 2
#define PROCESSED 3

// Convert character to index (e.g., 'A' -> 0)
int charToIndex(char c) {
    return c - 'A';
}

// Convert index to character (e.g., 0 -> 'A')
char indexToChar(int i) {
    return 'A' + i;
}

int main() {
    int number_of_vertices = 6;
    char src_char = 'A';
    char dest_char = 'F';

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    int status[MAX_VERTICES];
    int parent[MAX_VERTICES];

    // Build graph using char labels:
    // A->B,C | B->D,E | C->F
    graph[charToIndex('A')][charToIndex('B')] = 1;
    graph[charToIndex('A')][charToIndex('C')] = 1;
    graph[charToIndex('B')][charToIndex('D')] = 1;
    graph[charToIndex('B')][charToIndex('E')] = 1;
    graph[charToIndex('C')][charToIndex('F')] = 1;

    for (int i = 0; i < number_of_vertices; i++) {
        status[i] = READY;
        parent[i] = -1;
    }

    int src = charToIndex(src_char);
    int dest = charToIndex(dest_char);

    // BFS setup
    int queue[MAX_VERTICES], front = 0, rear = 0;
    queue[rear++] = src;
    status[src] = WAITING;

    int found = 0;

    // BFS loop
    while (front != rear) {
        int cur_node = queue[front++];
        status[cur_node] = PROCESSED;

        if (cur_node == dest) {
            found = 1;
            break;
        }

        for (int i = 0; i < number_of_vertices; i++) {
            if (graph[cur_node][i] && status[i] == READY) {
                queue[rear++] = i;
                status[i] = WAITING;
                parent[i] = cur_node;
            }
        }
    }

    // Reconstruct path
    if (found) {
        printf("Shortest path from %c to %c: ", src_char, dest_char);
        int path[MAX_VERTICES];
        int path_len = 0;
        for (int v = dest; v != -1; v = parent[v]) {
            path[path_len++] = v;
        }
        for (int i = path_len - 1; i >= 0; i--) {
            printf("%c ", indexToChar(path[i]));
        }
        printf("\n");
    } else {
        printf("No path found from %c to %c\n", src_char, dest_char);
    }

    return 0;
}
