#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using ll = long long;

#define SIZE 200000010
#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);

void swap(ll *x, ll *y) {
  ll temp = *x;
  *x = *y;
  *y = temp;
}

void heapify(vector<ll> &arr, ll n, ll i) {
  ll largest = i;
  ll left = i * 2 + 1;
  ll right = i * 2 + 2;

  if (left < n and arr[left] > arr[largest]) {
    largest = left;
  }
  if (right < n and arr[right] > arr[largest]) {
    largest = right;
  }

  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest);
  }
}
void heapsort(vector<ll> &arr, ll n) {

  for (ll i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }

  for (ll i = n - 1; i > 0; i--) {
    swap(&arr[0], &arr[i]);
    heapify(arr, i, 0);
  }
}

void randomgen(vector<ll> &arr) {
  srand(time(0));

  ll num_numbers = SIZE;

  for (auto i = 0; i < num_numbers; ++i) {
    ll randomNumber = (rand() % num_numbers) + 10;

    arr.push_back(randomNumber);
  }
}

int main() {
    fastio;
  vector<ll> arr;

  randomgen(arr);
  ll size = SIZE;

  const auto begin = std::chrono::high_resolution_clock::now();

  heapsort(arr, size);
  const auto end = std::chrono::high_resolution_clock::now();

  auto duration = chrono::duration_cast<chrono::seconds>(end - begin);

  //   cout << "\nSorted Array:  Size = " << size <<"\n";

  //   for (ll i = 0; i < size; i++) {
  //     cout << arr[i] << " ";
  //   }
  //   cout << "\n";

  cout << "Size: " << size << " Time:" << duration.count() << " s" << endl;

  return 0;
}
