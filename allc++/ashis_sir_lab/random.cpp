#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
int main() {
  srand(time(0));

  int num_numbers = 700000010;

  for (int i = 0; i < num_numbers; ++i) {
    int randomNumber = (rand() % num_numbers) + 10;

    cout << randomNumber << " ";
  }

  return 0;
}