#include "bits/stdc++.h"

using namespace std;

int main() {
  fstream file("map.txt", ios_base::out);

  if (!file.is_open()) {
    cout << "error";
  }
  int arr[12];

  for(int i=0;i<12;i++){
    file << 0 << " ";
  }
//   for (int i = 0; i < 52; i++) {
//     for (int j = 0; j < 52; j++) {
//       if (i >= 19 and i <= 23) {
//         arr[i][j] = 4;

//       }

//       else {
//         arr[i][j] = 5;
//       }
//     }
//   }
//   for (int i = 1; i <= 52; i++) {
//     for (int j = 1; j <= 52; j++) {
//       file << arr[i-1][j-1] << " ";
//     }
//     file << endl;
//   }
  file.close();
  cout<<"done";
  return 0;
}