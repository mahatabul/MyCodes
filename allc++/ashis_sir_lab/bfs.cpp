#include <stdio.h>

#define MAX_VERTICES 10
#define READY 1
#define WAITING 2
#define PROCESSED 3

int main() {

  int number_of_vertices = 6;
  int startNode = 1;

  int graph[MAX_VERTICES][MAX_VERTICES] = {0};
  int status[MAX_VERTICES];

  graph[0][1] = graph[0][2] = 1;
  graph[1][3] = graph[1][4] = 1;
  graph[2][5] = 1;

  for (int i = 0; i < number_of_vertices; i++) {
    status[i] = READY;
  }

  int queue[MAX_VERTICES], front = 0, rear = 0;

  queue[rear++] = startNode;
  status[0] = WAITING;

  while (front != rear) {

    int cur_node = queue[front++];
    status[cur_node] = PROCESSED;

    printf("%d ", cur_node);

    for (int i = 0; i < number_of_vertices; i++) {

      if (graph[cur_node][i] && status[i] == READY) {
        queue[rear++] = i;
        status[i] = WAITING;
      }
    }
  }
  printf("\n");
  return 0;
}

