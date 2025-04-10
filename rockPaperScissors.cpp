#include "rockPaperScissors.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

// Function to set console text color
void setrpcColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Function to play sound
void playrpcBeep(int freq, int duration) {
    Beep(freq, duration);
}

// Rock-Paper-Scissors Game
void rockPaperScissors() {
    srand(time(0));
    string choices[] = {"Rock 🪨", "Paper 📜", "Scissors ✂️"};
    int userChoice, computerChoice;
    char playAgain;

    do {
        system("cls"); // Clear screen for a fresh round
        setrpcColor(11); // Light blue
        cout << "\n🎮 Welcome to Rock-Paper-Scissors! 🎲\n";
        cout << "1️⃣ Rock 🪨\n2️⃣ Paper 📜\n3️⃣ Scissors ✂️\n";
        cout << "👉 Choose (1-3): ";
        cin >> userChoice;

        if (userChoice < 1 || userChoice > 3) {
            setrpcColor(12); // Red
            cout << "❌ Invalid choice! Please enter 1, 2, or 3.\n";
            playrpcBeep(200, 300); // Error sound
            continue;
        }

        computerChoice = rand() % 3 + 1;
        setrpcColor(14); // Yellow
        cout << "\n🧑 You chose: " << choices[userChoice - 1] << endl;
        cout << "💻 Computer chose: " << choices[computerChoice - 1] << endl;

        // Determine winner
        if (userChoice == computerChoice) {
            setrpcColor(14); // Yellow
            cout << "😐 It's a tie!\n";
            playrpcBeep(500, 200);
        } else if ((userChoice == 1 && computerChoice == 3) || 
                   (userChoice == 2 && computerChoice == 1) || 
                   (userChoice == 3 && computerChoice == 2)) {
            setrpcColor(10); // Green
            cout << "🎉 You win! 🏆\n";
            playrpcBeep(800, 200); // Win sound
        } else {
            setrpcColor(12); // Red
            cout << "😢 Computer wins! Try again.\n";
            playrpcBeep(300, 200); // Lose sound
        }

        setrpcColor(11); // Light blue
        cout << "\n🔄 Play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    setrpcColor(7); // Reset color
    cout << "\n👋 Thanks for playing!\n";
}
