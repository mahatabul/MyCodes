#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> DP(100, vector<int>(100, INT16_MAX));
int matrix_chain(vector<int> &p, int i, int j) {
  if (DP[i][j] < INT16_MAX) {
    return DP[i][j];
  }
  if (i == j) {
    return 0;
  }
  for (int k = i; k < j; k++) {
    int q = matrix_chain(p, i, k) + matrix_chain(p, k + 1, j) +
            p[i - 1] * p[k] * p[j];
    DP[i][j] = min(q, DP[i][j]);
  }
  return DP[i][j];
}

int MatrixChainOrder(const vector<int> &dims) {
  int n = dims.size() - 1;
  vector<vector<int>> cost(n + 1, vector<int>(n + 1, 0));
  vector<vector<int>> split(n + 1, vector<int>(n + 1, 0));

  for (int len = 2; len <= n; len++) { 
    for (int i = 1; i <= n - len + 1; i++) {
      int j = i + len - 1;
      cost[i][j] = INT_MAX;
      for (int k = i; k < j; k++) {
        int q = cost[i][k] + cost[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
        if (q < cost[i][j]) {
          cost[i][j] = q;
          split[i][j] = k;
        }
      }
    }
  }
  return cost[1][n];
}

int main() {
  vector<int> dims = {40, 20, 30, 10, 30};
  int res = MatrixChainOrder(dims);
  int res2 = matrix_chain(dims, 1, dims.size() - 1);
  cout << "Minimum number of multiplications: " << res << " " << res2 << endl;
  return 0;
}
