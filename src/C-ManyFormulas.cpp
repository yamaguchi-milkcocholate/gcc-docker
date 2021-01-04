#include<bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    int64_t sum = 0;
    for (int tmp=0; tmp < (1 << (S.size() - 1)); tmp++) {
        int64_t sub_sum = 0;
        bitset<10> plus(tmp);

        int64_t p_num = 0;
        for (int i=0; i<S.size(); i++) {
            p_num *= 10;
            p_num += (S.at(i) - '0');
            if (plus.test(i)) {
                sub_sum += p_num;
                p_num = 0;
            }
        }
        sub_sum += p_num;
        sum += sub_sum;
    }

    cout << sum << endl;
}