#include<bits/stdc++.h>
using namespace std;

int main() {
    string num_str;
    cin >> num_str;

    vector<int> num = {
        num_str.at(0) - '0',
        num_str.at(1) - '0',
        num_str.at(2) - '0',
        num_str.at(3) - '0',
    };

    for (int i=0; i<(1 << 3); i++) {
        bitset<3> op(i);

        int sum = num.at(0);
        for (int j=0; j<3; j++) {
            if (op.test(j)) sum += num.at(j + 1);
            else sum -= num.at(j + 1);
        }
        if (sum == 7) {
            stringstream ss;
            ss << num.at(0);
            for (int j=0; j<3; j++) {
                if (op.test(j)) ss << '+' << num.at(j + 1);
                else ss << '-' << num.at(j + 1);
            }
            cout << ss.str() << "=7" << endl;
            return 0;
        }
    }
}