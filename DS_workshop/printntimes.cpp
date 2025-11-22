#include <bits/stdc++.h>
#include <memory>

using namespace std;

void printNtimes(int s, int N) {
  if (s >= N) {
    return;
  }

  cout << "I love Recursion\n";
  printNtimes(++s, N);
}
int main() {

  int n;
  cin >> n;

  printNtimes(0, n);
  return 0;
}
