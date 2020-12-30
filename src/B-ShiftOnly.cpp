#include<bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  
  vector<int> A(N);
  for (int i=0; i<N; i++) {
    cin >> A.at(i);
  }
  
  int cnt = 0;
  bool is_roop = true;
  while (is_roop) {
    for (int i=0; i<N; i++) {
      if (A.at(i) % 2 == 0) {
        A.at(i) = A.at(i) / 2;
      }
      else {
        is_roop = false;
      }
    }
    if (is_roop) cnt++;
  }
  cout << cnt << endl;
}