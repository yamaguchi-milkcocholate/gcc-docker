#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> cards(N);
    for (int i=0; i<N; i++) {
        cin >> cards.at(i);
    }

    sort(cards.rbegin(), cards.rend());

    int alice = 0;
    int bob = 0;

    for (int i=0; i<N; i++) {
        if (i % 2 == 0) alice += cards.at(i);
        else bob += cards.at(i);
    }
    cout << alice - bob << endl;
}