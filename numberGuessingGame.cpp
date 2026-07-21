#include "numberGuess.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to set console text color
void setnumberColor(int color) {
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
#else
    switch (color) {
        case 10: cout << "\033[32m"; break;
        case 11: cout << "\033[36m"; break;
        case 12: cout << "\033[31m"; break;
        case 14: cout << "\033[33m"; break;
        default: cout << "\033[0m"; break;
    }
#endif
}

// Function to play beep sounds
void playnumberBeep(int freq, int duration) {
#ifdef _WIN32
    Beep(freq, duration);
#else
    (void)freq; (void)duration;
    cout << '\a';
#endif
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
