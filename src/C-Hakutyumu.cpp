#include<bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    vector<string> T = {
        "dream",
        "dreamer",
        "erase",
        "eraser",
    };
    string remain_S = S;

    while(true) {
        if (remain_S.size() == 0) {
            cout << "YES" << endl;
            return 0;
        }
        bool is_match = false;
        for (string t: T) {
            if (remain_S.size() < t.size()) continue;
            if (t == remain_S.substr(remain_S.size() - t.size())) {
                remain_S = remain_S.substr(0, remain_S.size() - t.size());
                is_match = true;
                break;
            }
        }
        if (!is_match) {
            cout << "NO" << endl;
            return 0;
        }
    }
}