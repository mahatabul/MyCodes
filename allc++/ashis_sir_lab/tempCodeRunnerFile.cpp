
int main() {

  int number_of_vertices = 6;
  int startNode=1;

  int graph[MAX_VERTICES][MAX_VERTICES] = {0};
  int status[MAX_VERTICES];

  graph[0][1] = graph[0][2] = 1;
  graph[1][3] = graph[1][4] = 1;
  graph[2][5] = 1;

  for (int i = 0; i < number_of_vertices; i++) {
    status[i] = READY;
  }

  int queue[MAX_VERTICES], front = 0, rear = 0;
