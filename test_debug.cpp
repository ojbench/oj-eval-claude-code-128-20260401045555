#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool hasWon(const vector<string>& board, char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            cout << "Row " << i << " wins for " << player << endl;
            return true;
        }
    }
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            cout << "Col " << j << " wins for " << player << endl;
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        cout << "Main diag wins for " << player << endl;
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        cout << "Anti diag wins for " << player << endl;
        return true;
    }
    return false;
}

int main() {
    vector<string> board(3);
    for (int i = 0; i < 3; i++) {
        cin >> board[i];
    }
    
    int xCount = 0, oCount = 0, emptyCount = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'x') xCount++;
            else if (board[i][j] == 'o') oCount++;
            else emptyCount++;
        }
    }
    
    cout << "xCount: " << xCount << ", oCount: " << oCount << ", emptyCount: " << emptyCount << endl;
    
    bool xWon = hasWon(board, 'x');
    bool oWon = hasWon(board, 'o');
    
    cout << "xWon: " << xWon << ", oWon: " << oWon << endl;
    
    return 0;
}
