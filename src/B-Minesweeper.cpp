#include<bits/stdc++.h>
using namespace std;


int count_mine(vector<string> S, int W, int H, int w, int h) {
    vector<vector<int>> points = {
        {h, w - 1},
        {h, w + 1},
        {h + 1, w},
        {h - 1, w},
        {h - 1, w - 1},
        {h - 1, w + 1},
        {h + 1, w - 1},
        {h + 1, w + 1}
    };
    int num_mines = 0;

    for (int i=0; i<points.size(); i++) {
        if (0 <= points[i][0] && points[i][0] < H && 0 <= points[i][1] && points[i][1] < W) {
            if (S[points[i][0]][points[i][1]] == '#')
                num_mines++;
        }
    }
    return num_mines;
}


int main() {
    int H, W;

    cin >> H >> W;
    vector<string> S(H);
    
    for (int i=0; i<H; i++) {
        cin >> S[i];
    }

    for (int h=0; h<H; h++) {
        for (int w=0; w<W; w++) {
            if (S[h][w] == '#')
                cout << '#';
            else {
                cout << count_mine(S, W, H, w, h);
            }
        }
        cout << endl;
    }
}
