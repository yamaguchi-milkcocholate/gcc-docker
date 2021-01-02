#include<bits/stdc++.h>
using namespace std;

bool can_travel(int x, int y, int x_d, int y_d, int num_step);

int main() {
    int N;
    cin >> N;

    vector<int> t(N);
    vector<int> x(N);
    vector<int> y(N);

    for (int i=0; i<N; i++) {
        cin >> t.at(i) >> x.at(i) >> y.at(i);
    }
    
    int cur_x = 0;
    int cur_y = 0;
    int cur_t = 0;

    for (int i=0; i<N; i++) {
        if (!can_travel(cur_x, cur_y, x.at(i), y.at(i), t.at(i) - cur_t)) {
            cout << "No" << endl;
            return 0;
        }
        cur_x = x.at(i);
        cur_y = y.at(i);
        cur_t = t.at(i);
    }

    cout << "Yes" << endl;
}


bool can_travel(int x, int y, int x_d, int y_d, int num_step) {
    int dis = abs(x - x_d) + abs(y - y_d);
    if (dis % 2 == num_step % 2 && num_step >= dis) return true;
    else return false;
}