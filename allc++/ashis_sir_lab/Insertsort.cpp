#include <bits/stdc++.h>
#include <chrono>
#include <iostream>
using namespace std;

int main() {
  vector<int> arr;


  int x;
  while (cin>>x) {
    arr.push_back(x);
  
  }
  int size = arr.size();
  
  const auto begin = std::chrono::high_resolution_clock::now();
  

  for (int i = 1; i < size; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }

 const auto end = std::chrono::high_resolution_clock::now();

  auto duration = chrono::duration_cast<chrono::nanoseconds>(end-begin);

  cout << "\nSorted Array:  Size = " << size <<"\n";

  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";

  cout<<"Size: "<<size<<" Time:"<<duration.count()<<" nanoseconds"<<endl;

  return 0;
}