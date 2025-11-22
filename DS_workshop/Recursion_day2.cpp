#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);

vector<int> arr = {1, 2, 3};

void printSubsequences(vector<int> &arr, vector<int> &temp, int index) {
  if (index == arr.size()) {
    cout << "{ ";
    // Base case: print the current subsequence
    if (!temp.empty()) {
      for (int num : temp) {
        cout << num << " ";
      }
      cout << "}" << endl;
    } else
      cout << "}" << endl;
    return;
  }

  // Include the current element
  temp.push_back(arr[index]);
  printSubsequences(arr, temp, index + 1);

  // Exclude the current element
  temp.pop_back();
  printSubsequences(arr, temp, index + 1);
}

void func(int i, vector<int> &v) {

  if (i == arr.size()) {
    for (auto it : v) {
      cout << it << " ";
    }
    cout << "\n";

    return;
  }

  func(i + 1, v);
  v.push_back(arr[i]);
  func(i + 1, v);
  v.pop_back();
}

void fsum(vector<int> a, vector<int> &t, int idx, int sum, int ans) {
  if (sum == ans or ans == 0) {

    cout << "Answer found " << endl;
    for (auto it : t) {
      cout << it << " ";
    }
    return;
  }
  if (idx == a.size()) {

    return;
  }

  sum += a[idx];
  t.push_back(a[idx]);

  fsum(a, t, idx + 1, sum, ans);
  sum -= a[idx];
  t.pop_back();
  fsum(a, t, idx + 1, sum, ans);
}

int mboard[1001][1001];
map<ll, ll> r, c, rr, l;

bool possible(int x, int y) {
  if (r[x])
    return false;
  if (c[y]) {
    return false;
  }
  if (l[x + y]) {
    return false;
  }
  if (rr[x - y]) {

    return false;
  }

  return true;
}

int n = 4;
bool nqueen(int x, int y) {
  if (y == n) {
    return false;
  }
  if (x == n) {

    return true;
  }
  if (possible(x, y)) {

    mboard[x][y] = 1;
    r[x] = 1;
    c[y] = 1;
    l[x + y] = 1;
    rr[x - y] = 1;

    if (nqueen(x + 1, 0)) {

      return true;
    }
    mboard[x][y] = 0;
    r[x] = 0;
    c[y] = 0;
    l[x + y] = 0;
    rr[x - y] = 0;

    return nqueen(x, y + 1);
  }
  return nqueen(x, y + 1);
}

vector<vector<char>> dial = {
    {}, 
    {}, 
    {'a', 'b', 'c'},     // 2
    {'d', 'e', 'f'},     // 3
    {'g', 'h', 'i'},     // 4
    {'j', 'k', 'l'},     // 5
    {'m', 'n', 'o'},     // 6
    {'p', 'q', 'r', 's'},// 7
    {'t', 'u', 'v'},     // 8
    {'w', 'x', 'y', 'z'} // 9
};

string input = "25";

void s(int index, string &output) {
    if (index == input.size()) {
        cout << output << endl;
        return;
    }

    int digit = input[index] - '0';
    if (digit < 2 || digit > 9) return; // skip unsupported digits

    for (char ch : dial[digit]) {
        output.push_back(ch);
        s(index + 1, output);
        output.pop_back();
    }
}

int main() {
  fastio;

  //   int arr[n][n];

  //   for (int i = 0; i < n; i++) {
  //     for (int j = 0; j < n; j++) {
  //       arr[i][j] = nqueen(i, j) ? 1 : 0;
  //     }
  //   }

  //   for (int i = 0; i < n; i++) {
  //     for (int j = 0; j < n; j++) {
  //       cout << arr[i][j] << " ";
  //     }
  //     cout << "\n";
  //   }

  //   nqueen(0, 0);

  //   for (int i = 0; i < n; i++) {

  //     for (int j = 0; j < n; j++) {
  //       cout << mboard[i][j] << " ";
  //     }
  //     cout << "\n";
  //   }
  string ans="";
  cin>>input;
  s(0,ans);
  cout << "\n";

  return 0;
}