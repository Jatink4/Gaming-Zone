#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// ANSI Escape Codes for Colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define BOLD    "\033[1m"

// Function Declarations
void ticTacToe();
void rockPaperScissors();
void numberGuessingGame();
void snakeEatingFood();
void hangman();
void playSudoku();

void showMenu() {
    cout << BOLD CYAN "\n🎮 ==== WELCOME TO THE GAMING ZONE ==== 🎮\n\n" RESET;
    cout << GREEN "🔢 1. Tic-Tac-Toe ❌⭕\n" RESET;
    cout << YELLOW "🪨 2. Rock-Paper-Scissors ✊✋✌️\n" RESET;
    cout << BLUE "🔢 3. Number Guessing Game 🎲\n" RESET;
    cout << GREEN "🐍 4. Snake Eating Food 🍎\n" RESET;
    cout << RED "🎭 5. Hangman 🏆\n" RESET;
    cout << CYAN "🧩 6. Play Sudoku 🔢\n" RESET;
    cout << RED "❌ 7. Exit 🚪\n" RESET;
    cout << YELLOW "\nEnter your choice: " RESET;
}

int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;
        cout << "\n";

        switch (choice) {
            case 1: ticTacToe(); break;
            case 2: rockPaperScissors(); break;
            case 3: numberGuessingGame(); break;
            case 4: snakeEatingFood(); break;
            case 5: hangman(); break;
           
            case 6: playSudoku(); break;
            case 7: cout << GREEN "🚪 Exiting the Gaming Zone... See you soon! 🎮\n" RESET; break;
            default: cout << RED "⚠️ Invalid choice! Please try again. ⚠️\n" RESET;
                     cout << "\a"; // Beep sound 🔊
        }

    } while (choice != 7);

    return 0;
}

// ======================== Tic-Tac-Toe ========================
#include "ticTacToe.h"
// ==================== Rock-Paper-Scissors ====================
#include "rockPaperScissors.h"
// ==================== Number Guessing Game ====================
#include "numberGuess.h"
// ======================== Snake Eating Food ========================
#include "snakeGame.h"
// ======================== Hangman ========================
#include "hangman.h"
// ======================== Sudoku ========================
#include "sudoku.h"
