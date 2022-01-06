#include <bits/stdc++.h>
using namespace std;

string FindBoardStatus(int size, char (*board)[100], int bluewin) {
    // TODO: Complete this function to find the status of the board.
    int blue = 0, red = 0;
    int redwin = 0;
    for (int column = 0; column < size; column++) {
        bool flag = true;
        for (int row = 0; row < size; row++) {
            if(board[row][column] == 'B') {
                blue++;
                flag = false;
            }
            else if(board[row][column] == '.') {
                flag = false;
            }
            else if(board[row][column] == 'R') {
                red++;
            }
        }
        if(flag) {
            redwin++;
        }
    }

    if(abs(red - blue) > 1 || redwin > 1 || bluewin > 1 || redwin && bluewin) {
        return "Impossible";
    }
    else if(bluewin) {
        return "Blue wins";
    }
    else if(redwin) {
        return "Red wins";
    }
    return "Nobody wins";
}

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        int n;
        cin >> n;
        char board[100][100];
        int bluewin = 0;
        for (int r = 0; r < n; ++r) {
            bool flag = true;
            for (int c = 0; c < n; ++c) {
                cin >> board[r][c];
                if(board[r][c] != 'B') {
                    flag = false;
                }
            }
            if(flag) { bluewin++; }
        }
        cout << "Case #" << tc << ": " << FindBoardStatus(n, board, bluewin) << endl;
    }
    return 0;
}
