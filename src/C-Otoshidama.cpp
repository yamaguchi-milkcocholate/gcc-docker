#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, Y;
    cin >> N >> Y;

    int MAN = 10000;
    int GOSEN = 5000;
    int SEN = 1000;

    for (int man=0; man<=(Y/MAN); man++) {
        int remain1 = Y - MAN * man;
        if (man > N) continue;

        for (int gosen=0; gosen<=(remain1/GOSEN); gosen++) {
            int remain2 = remain1 - GOSEN * gosen;
            int sen = N - man - gosen;
            if (remain2 - SEN * sen == 0 && sen >= 0) {
                cout << man << " " << gosen << " " << sen << endl;
                return 0;
            } 
            else continue;
        }
    }

    cout << -1 << " " << -1 << " " << -1 << endl;
}