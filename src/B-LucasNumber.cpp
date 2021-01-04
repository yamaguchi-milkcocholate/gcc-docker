#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int64_t L_t_1 = 1;
  int64_t L_t_2 = 2;
  int64_t L_t;

  if (N == 0) {
      cout << 2 << endl;
      return 0;
  }
  if (N == 1) {
      cout << 1 << endl;
      return 0;
  }

  for (int i=2; i<=N; i++) {
    int64_t tmp = L_t_1 + L_t_2;
    L_t_2 = L_t_1;
    L_t_1 = tmp;
    L_t = tmp;
  }
  cout << L_t << endl;
}