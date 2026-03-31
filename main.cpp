#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Check if a player has won
bool hasWon(const vector<string>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

int main() {
    vector<string> board(3);
    for (int i = 0; i < 3; i++) {
        cin >> board[i];
    }

    // Count the pieces
    int xCount = 0, oCount = 0, emptyCount = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'x') xCount++;
            else if (board[i][j] == 'o') oCount++;
            else emptyCount++;
        }
    }

    bool xWon = hasWon(board, 'x');
    bool oWon = hasWon(board, 'o');

    // Check for invalid states

    // x must go first, so xCount should be equal to oCount or oCount + 1
    if (xCount < oCount || xCount > oCount + 1) {
        cout << "invalid" << endl;
        return 0;
    }

    // Both can't win
    if (xWon && oWon) {
        cout << "invalid" << endl;
        return 0;
    }

    // If x won, the game should have stopped, so x should have played last
    // This means xCount == oCount + 1
    if (xWon && xCount != oCount + 1) {
        cout << "invalid" << endl;
        return 0;
    }

    // If o won, the game should have stopped, so o should have played last
    // This means xCount == oCount
    if (oWon && xCount != oCount) {
        cout << "invalid" << endl;
        return 0;
    }

    // Determine the game state
    if (xWon) {
        cout << "win" << endl;
    } else if (oWon) {
        cout << "lose" << endl;
    } else if (emptyCount == 0) {
        cout << "tie" << endl;
    } else {
        cout << "ongoing" << endl;
    }

    return 0;
}
