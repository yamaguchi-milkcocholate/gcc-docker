#include<bits/stdc++.h>
using namespace std;


int main() {
  int N, A, B;
  
  cin >> N >> A >> B;
  
  int cnt = 0;
  for (int n=1; n<=N; n++) {
      int sum = 0;
      int nn = n;
      for (int i=0; i<5; i++) {
          sum += (nn % 10);
          nn /= 10;
      }
      if (A<= sum && sum <= B) cnt += n;
  }
  
  cout << cnt << endl;
}