// void solve(vector<int> &ans, int n, int k, int num) {
//   if (num == n) {
//     ans.push_back(num);
//     return;
//   }
//   ans.push_back(num);
//   num > 0 ? solve(ans, n, k, num - k) : solve(ans, n, k, num + k);
// }
// vector<int> printSeries(int n, int k) {
//   // Write your code here
//   vector<int> ans;

//   ans.push_back(n);
//   solve(ans, n, k, n - k);

//   return ans;
// }

#include <stdbool.h>
#include <stdio.h>
#define MX 100

int front, rear, queue[MX];

void enqueue(int val) { queue[(rear++)] = val; }
int dequeue() { return queue[(front++)]; }
bool isQempty() { return front == rear; }

int main() {
  int n;
  char src, dest;
  scanf("%d %c %c", &n, &src, &dest);
  int source = src - 'A', destination = dest - 'A';

  int adj_mat[n][n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &adj_mat[i][j]);
    }
  }
  int status[n], origin[n];
  for (int i = 0; i < n; i++) {
    status[i] = 1;
    origin[i] = -1;
  }

  front = rear = 0;

  enqueue(source);
  status[source] = 2;

  while (!isQempty()) {
    int temp = dequeue();
    status[temp] = 3;

    if (temp == destination) {
      break;
    }

    for (int i = 0; i < n; i++) {
      if (adj_mat[temp][i] == 1 && status[i] == 1) {
        enqueue(i);
        status[i] = 2;
        origin[i] = temp;
      }
    }
  }

  if (status[destination] != 3) {
    printf("-1\n");
  } else {
    int path[MX], path_i = 0;
    for (int i = destination; i != -1; i = origin[i]) {
      path[path_i++] = i;
    }
    for (int i = path_i - 1; i >= 0; i--) {
      printf("%c ", path[i] + 'A');
    }
    printf("\n");
  }

  return 0;
}