#include <bits/stdc++.h>
#include <chrono>
#include <iostream>

using namespace std;

void merge(vector<int> &arr, int start, int mid, int end) {

  int n1 = mid - start + 1;
  int n2 = end - mid;

  int left[n1], right[n2];

  for (int i = 0; i < n1; i++)
    left[i] = arr[start + i];

  for (int i = 0; i < n2; i++)
    right[i] = arr[mid + 1 + i];

  int i = 0, j = 0, k = start;

  while (i < n1 && j < n2) {
    if (left[i] < right[j]) {
      arr[k] = left[i];
      i++;
    } else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = left[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = right[j];
    j++;
    k++;
  }
}
void mergeSort(vector<int> &arr, int start, int end) {
  if (start < end) {
    int mid = (start + end) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, start, mid, end);
  }
}

int main() {
  vector<int> arr;

  int x;
  while (cin >> x) {
    arr.push_back(x);
  }
  int size = arr.size();

  const auto begin = std::chrono::high_resolution_clock::now();

  printf("\n");
  mergeSort(arr, 0, size - 1);

   const auto end = std::chrono::high_resolution_clock::now();

  auto duration = chrono::duration_cast<chrono::milliseconds>(end-begin);

  cout << "\nSorted Array:  Size = " << size <<"\n";

  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";

  cout<<"Size: "<<size<<" Time:"<<duration.count()<<" ms"<<endl;


  return 0;
}