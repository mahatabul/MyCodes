#include "bits/stdc++.h"

using namespace std;



int solve(int idx, int prices[], int n) {
  // if (prices[idx]) {
  // }
  if (idx == 0) {

    return prices[idx] * n;
  }
  int not_take = solve(idx - 1, prices, n);
  int take = INT_MIN;
  int rod_Len = idx + 1;
  if (rod_Len <= n) {
    take = prices[idx] + solve(idx, prices, n - rod_Len);
  }

  return max(take, not_take);
}
int main() {

  const int n = 4;
  int prices[n] = {1, 0, 3, 2};

  cout << "Max Profit: " << solve(n - 1, prices, n);

  return 0;
}