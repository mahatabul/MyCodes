#include <bits/stdc++.h>
#include <cstdlib>
#include <vector>

using namespace std;
using ll = long long;

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);

int fib(int n) {
  if (n <= 1) {
    return n;
  }
  int ans;
  if (n & 1) {
    ans = fib(n - 1) + fib(n - 2) + fib(n - 3);

  } else {
    ans = fib(n - 1) + fib(n - 2);
  }

  return ans;
}

bool gen(int zen, int child) {

  if (zen <= 0) {
    return 0;
  }

  bool parent = gen(zen - 1, child / 2);
  if (child % 2 == 0) {
    return parent;
  }

  return !parent;
}

string kthChildNthGeneration(int n, long long k) {
  if (n == 1 or k == 1) {
    return "Male";
  }
  long long int parent_k = (k + 1) / 2;
  string parent = kthChildNthGeneration(n - 1, parent_k);
  if (parent == "Male") {
    return (k & 1) ? "Male" : "Female";
  } else {
    return (k & 1) ? "Female" : "Male";
  }
}
void towerofHanoisolve(vector<vector<int>> &ans, int n, int src, int aux,
                       int des) {
  if (n <= 0) {
    return;
  }
  vector<int> a;
  towerofHanoisolve(ans, n - 1, src, des, aux);
  ans.push_back({src, des});

  towerofHanoisolve(ans, n - 1, aux, src, des);
}

vector<vector<int>> towerOfHanoi(int n) {
  //    Write your code here.
  vector<vector<int>> ans;
  towerofHanoisolve(ans, n, 1, 2, 3);
  return ans;
}

int nthTermOfGP(int N, int A, int R) {
  // Write your code here.

  if (N <= 1) {
    return A % 1000000007;
  }

  long long t = nthTermOfGP(N - 1, A, R);

  return ((R % 1000000007) * t) % 1000000007;
}

void solve(vector<int> &ans, int n, int k, int num, bool add) {
  if (!add) {

    ans.push_back(num);

    num > 0 ? solve(ans, n, k, num - k, false)
            : solve(ans, n, k, num + k, true);

    // if (num > 0) {

    //   solve(ans, n, k, num - k, false);
    // } else {

    //   solve(ans, n, k, num + k, true);
    // }
  } else {

    if (num < n) {
      ans.push_back(num);

      solve(ans, n, k, num + k, true);
    }

    if (num == n)
      ans.push_back(num);
  }
}

vector<int> printSeries(int n, int k) {
  vector<int> ans;
  ans.push_back(n);
  solve(ans, n, k, n - k, false);
  return ans;
}
int main() {

  if (gen(3 - 1, 4 - 1)) {
    cout << "Female";

  } else {
    cout << "Male";
  }
  cout << "\n";
  return 0;
}