#include<bits/stdc++.h>
using namespace std;

bool is_connected(vector<vector<char>> board);
void check_island(vector<vector<char>> board, vector<vector<bool>> &checked, int x, int y);

int main() {
    vector<vector<char>> board(10, vector<char>(10));
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            cin >> board.at(i).at(j);
        }
    }

    is_connected(board);

    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            if (board.at(i).at(j) == 'x') {
                board.at(i).at(j) = 'o';
                if (is_connected(board)) {
                    cout << "YES" << endl;
                    return 0;
                }
                board.at(i).at(j) = 'x';
            }
            else {
                continue;
            }
        }
    }

    cout << "NO" << endl;
}

bool is_connected(vector<vector<char>> board) {
    vector<vector<bool>> checked(10, vector<bool>(10, false));

    bool is_found = false;
    int x, y;
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            if (board.at(i).at(j) == 'o') {
                is_found = true;
                x = i;
                y = j;
                break;
            }
        }
        if (is_found) break;
    }

    check_island(board, checked, x, y);

    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            if (board.at(i).at(j) == 'o' && !checked.at(i).at(j)) return false;
        }
    }
    return true;
}

void check_island(vector<vector<char>> board, vector<vector<bool>> &checked, int x, int y) {
    if (x<0 || x>=10 || y<0 || y>=10) return;
    if (board.at(x).at(y) == 'x') return;
    if (checked.at(x).at(y)) return;

    checked.at(x).at(y) = true;
    check_island(board, checked, x-1, y);
    check_island(board, checked, x+1, y);
    check_island(board, checked, x, y-1);
    check_island(board, checked, x, y+1);
}

