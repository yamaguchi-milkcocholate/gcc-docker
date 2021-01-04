#include<bits/stdc++.h>
using namespace std;

void add_cell_to_search(int x, int y, queue<pair<int, int>> &search_queue, vector<vector<int>> &distance, vector<vector<char>> board, int dis);

int main() {
    int R, C, SX, SY, GX, GY;
    cin >> R >> C;
    cin >> SX >> SY;
    cin >> GX >> GY;

    SX--;SY--;GX--;GY--;

    vector<vector<char>> board(R, vector<char>(C));
    for (int row=0; row<R; row++) {
        for (int col=0; col<C; col++) {
            cin >> board.at(row).at(col);
        }
    }
    // 未調査の地点は-1
    vector<vector<int>> distance(R, vector<int>(C, -1));

    queue<pair<int, int>> search_queue;
    search_queue.push(make_pair(SX, SY));
    distance.at(SX).at(SY) = 0;

    while(!search_queue.empty()) {
        int x, y;
        tie(x, y) = search_queue.front();
        int dis = distance.at(x).at(y);
        search_queue.pop();

        if (x == GX && y == GY) {
            cout << dis << endl;
            return 0;
        }

        add_cell_to_search(x+1, y, search_queue, distance, board, dis + 1);
        add_cell_to_search(x-1, y, search_queue, distance, board, dis + 1);
        add_cell_to_search(x, y+1, search_queue, distance, board, dis + 1);
        add_cell_to_search(x, y-1, search_queue, distance, board, dis + 1);
    }
}


void add_cell_to_search(int x, int y, queue<pair<int, int>> &search_queue, vector<vector<int>> &distance, vector<vector<char>> board, int dis) {
    int R, C;
    R = board.size();
    C = board.at(0).size();

    if (x < 0 || R <= x || y < 0 || C <= y) return;
    if (distance.at(x).at(y) != -1) return;
    if (board.at(x).at(y) == '#') return;

    search_queue.push(make_pair(x, y));
    distance.at(x).at(y) = dis;
}