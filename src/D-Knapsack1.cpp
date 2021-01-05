#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;

    vector<int> w(N);
    vector<int> v(N);

    for (int i=0; i<N; i++) {
        cin >> w.at(i) >> v.at(i);
    }

    vector<vector<int64_t>> dp(110, vector<int64_t>(100100, 0));

    for (int i=0; i<N; i++) {
        for (int j=0; j<=W; j++) {
            // 選ぶ
            if (j - w.at(i) >= 0) {
                dp.at(i + 1).at(j) = max(dp.at(i + 1).at(j), dp.at(i).at(j - w.at(i)) + v.at(i));
            }

            // 選ばない
            dp.at(i + 1).at(j) = max(dp.at(i + 1).at(j), dp.at(i).at(j));
        }
    }

    cout << dp.at(N).at(W) << endl;
}