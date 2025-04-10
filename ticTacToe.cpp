#include "ticTacToe.h"
#include <iostream>
using namespace std;

// ANSI Escape Codes for Colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

// Global Variables
char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char currentMarker;
int currentPlayer;

// Function to draw the game board with colors
void drawBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << (board[i][0] == 'X' ? RED "❌" RESET : (board[i][0] == 'O' ? BLUE "⭕" RESET : YELLOW + string(1, board[i][0]) + RESET)) << " | "
             << (board[i][1] == 'X' ? RED "❌" RESET : (board[i][1] == 'O' ? BLUE "⭕" RESET : YELLOW + string(1, board[i][1]) + RESET)) << " | "
             << (board[i][2] == 'X' ? RED "❌" RESET : (board[i][2] == 'O' ? BLUE "⭕" RESET : YELLOW + string(1, board[i][2]) + RESET)) << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Function to place a marker on the board
bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (slot < 1 || slot > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << RED "⚠️ Invalid move! Try again. ⚠️\n" RESET;
        cout << "\a"; // Beep sound 🔊
        return false;
    }

    board[row][col] = currentMarker;
    return true;
}

// Function to check for a winner
int winner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return currentPlayer;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return currentPlayer;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return currentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return currentPlayer;
    
    return 0;
}

// Function to reset the board before a new game
void resetBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
}

// Main function to play the game
void ticTacToe() {
    resetBoard();
    currentPlayer = 1;
    currentMarker = 'X';

    int playerWon = 0;
    for (int i = 0; i < 9 && playerWon == 0; i++) {
        drawBoard();
        cout << CYAN "🎮 Player " << currentPlayer << " (" << (currentMarker == 'X' ? "❌" : "⭕") << ") - Enter a slot (1-9): " RESET;
        
        int slot;
        cin >> slot;
        
        if (!placeMarker(slot)) {
            i--; // Retry the move if invalid
            continue;
        }

        playerWon = winner();
        if (playerWon == 0) {
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
            currentMarker = (currentMarker == 'X') ? 'O' : 'X';
        }
    }

    drawBoard();
    if (playerWon) cout << GREEN "🎉🎊 Player " << playerWon << " wins! 🎉🎊\n" RESET;
    else cout << YELLOW "🤝 It's a tie! Well played! 🤝\n" RESET;
}
