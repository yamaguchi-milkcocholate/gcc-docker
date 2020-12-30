#include<bits/stdc++.h>
using namespace std;


int calc_points(vector<string> blue, vector<string> red, string target) {
    int point = 0;
    for (string s: blue) {
        if (target == s) point++;
    }
    for (string s: red) {
        if (target == s) point--;
    }
    return point;
}

int main() {
    int N;
    cin >> N;

    vector<string> blue(N);
    for (int i=0; i<N; i++) {
        cin >> blue.at(i);
    }

    int M;
    cin >> M;
    
    vector<string> red(M);
    for (int i=0; i<M; i++) {
        cin >> red.at(i);
    }

    int best = 0;

    for (string s: blue) {
        best = max(best, calc_points(blue, red, s));
    }
    cout << best << endl;
}