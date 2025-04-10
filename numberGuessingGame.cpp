#include "numberGuess.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

// Function to set console text color
void setnumberColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Function to play beep sounds
void playnumberBeep(int freq, int duration) {
    Beep(freq, duration);
}

// Number Guessing Game
void numberGuessingGame() {
    srand(time(0));
    int numberToGuess = rand() % 100 + 1;
    int userGuess, attempts = 0;
    
    setnumberColor(11); // Light blue
    cout << "\n🎯 Welcome to the Number Guessing Game! 🎲\n";
    cout << "🔢 Guess a number between 1 and 100.\n";
    cout << "💡 Hints will guide you along the way!\n";
    
    do {
        setnumberColor(14); // Yellow
        cout << "\nEnter your guess: ";
        cin >> userGuess;
        attempts++;

        if (userGuess > numberToGuess) {
            setnumberColor(12); // Red
            if (userGuess - numberToGuess > 10) {
                cout << "📈 Too high! Try again.\n";
            } else {
                cout << "🔥 Close, but still high! Try a bit lower.\n";
            }
            playnumberBeep(400, 150); // High guess sound
        } 
        else if (userGuess < numberToGuess) {
            setnumberColor(12); // Red
            if (numberToGuess - userGuess > 10) {
                cout << "📉 Too low! Try again.\n";
            } else {
                cout << "🔥 Close, but still low! Try a bit higher.\n";
            }
            playnumberBeep(200, 150); // Low guess sound
        } 
        else {
            setnumberColor(10); // Green
            cout << "\n🎉 Congratulations! You guessed the correct number: " << numberToGuess << "\n";
            cout << "🏆 It took you " << attempts << " attempts.\n";
            playnumberBeep(700, 200); // Victory sound
        }

    } while (userGuess != numberToGuess);

    setnumberColor(7); // Reset color
}
