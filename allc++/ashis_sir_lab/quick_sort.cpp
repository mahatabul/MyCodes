#include "bits/stdc++.h"
#include <chrono>

using namespace std;

int pp(vector<int> &arr, int low, int high) {
  int pivot = arr[high];

  int i = low;
  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      swap(arr[i], arr[j]);
      i++;
    }
  }

  swap(arr[i], arr[high]);

  return i;
}

void quickSort(vector<int> &arr, int low, int high) {
  if (low < high) {

    int partitionIndex;
    partitionIndex = pp(arr, low, high);

    quickSort(arr, low, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, high);
  }
}

int main() {
  vector<int> arr;
  int i;
  while (cin >> i) {
    arr.push_back(i);
  }

  cout << "Original array: ";
  for (int x : arr) {
    cout << x << " ";
  }
  cout << endl;

  int n = arr.size();
  const auto begin = std::chrono::high_resolution_clock::now();
  quickSort(arr, 0, n - 1);
  const auto end = std::chrono::high_resolution_clock::now();

  auto duration = chrono::duration_cast<chrono::milliseconds>(end-begin);

  cout << "Sorted array: ";
  for (int x : arr) {
    cout << x << " ";
  }
  cout << endl;

  cout<<"Size: "<<arr.size()<<" Time:"<<duration.count()<<" milliseconds"<<endl;

  return 0;
}
