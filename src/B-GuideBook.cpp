#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<tuple<string, int, int>> res(N);
  for (int i=0; i<N; i++) {
    string name;
    int score;
    cin >> name >> score;
    res.at(i) = make_tuple(name, -1 * score, i+1);
  }
  
  sort(res.begin(), res.end());
  
  for (auto res_i: res) {
    cout << get<2>(res_i) << endl;
  }
}