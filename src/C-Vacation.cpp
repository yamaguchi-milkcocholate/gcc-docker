#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> happiness(N, vector<int>(3));
    for (int n=0; n<N; n++) {
        cin >> happiness.at(n).at(0) >> happiness.at(n).at(1) >> happiness.at(n).at(2);
    }

    vector<vector<int64_t>> taro_hap(N, vector<int64_t>(3, 0));
    for (int i=0; i<3; i++) {
        taro_hap.at(0).at(i) = happiness.at(0).at(i);
    }

    for (int i=1; i<N; i++) {
        taro_hap.at(i).at(0) = max(taro_hap.at(i - 1).at(1) + happiness.at(i).at(0), taro_hap.at(i - 1).at(2) + happiness.at(i).at(0));
        taro_hap.at(i).at(1) = max(taro_hap.at(i - 1).at(0) + happiness.at(i).at(1), taro_hap.at(i - 1).at(2) + happiness.at(i).at(1));
        taro_hap.at(i).at(2) = max(taro_hap.at(i - 1).at(0) + happiness.at(i).at(2), taro_hap.at(i - 1).at(1) + happiness.at(i).at(2));
    }

    int64_t ans = max({taro_hap.at(N-1).at(0), taro_hap.at(N-1).at(1), taro_hap.at(N-1).at(2)});
    cout << ans << endl;
}