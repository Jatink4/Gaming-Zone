#include "hangman.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;

string words[] = {"programming", "hangman", "datastructure", "algorithm", "backtracking", "gamingzone"};

// Function to set console text color
void sethangColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Function to play a beep sound
void playhangBeep(int freq, int duration) {
    Beep(freq, duration);
}

// Function to display Hangman stages
void displayHangman(int attempts) {
    string stages[] = {
        "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========\n",
        "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========\n",
        "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========\n",
        "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========\n",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========\n",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========\n",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========\n"
    };
    cout << stages[6 - attempts] << endl;
}

// Hangman Game Function
void hangman() {
    srand(time(0));
    string word = words[rand() % 7];  // Randomly select a word
    string guessed(word.length(), '_'); // Underscores for hidden letters
    int attempts = 7;
    char guess;
    vector<char> incorrectGuesses;
    
    while (attempts > 0 && guessed != word) {
        sethangColor(14); // Yellow color
        cout << "\nWord: ";
        for (char c : guessed) {
            cout << c << " ";
        }
        cout << "\n";
        sethangColor(12); // Red for incorrect guesses
        cout << "Incorrect Guesses: ";
        for (char c : incorrectGuesses) cout << c << " ";
        cout << "\n";

        displayHangman(attempts); // Show hangman stage

        sethangColor(11); // Light blue
        cout << "Attempts left: " << attempts << "\n";
        cout << "Enter a letter: ";
        cin >> guess;

        bool correct = false;
        for (size_t i = 0; i < word.length(); i++) {
            if (word[i] == guess) {
                guessed[i] = guess;
                correct = true;
            }
        }

        if (!correct) {
            incorrectGuesses.push_back(guess);
            attempts--;
            playhangBeep(300, 200); // Wrong guess sound
        } else {
            playhangBeep(600, 200); // Correct guess sound
        }
    }

    if (guessed == word) {
        sethangColor(10); // Green
        cout << "\n🎉 Congratulations! You guessed the word: " << word << "\n";
        playhangBeep(800, 300); // Victory sound
    } else {
        sethangColor(12); // Red
        cout << "\n💀 Game Over! The word was: " << word << "\n";
        playhangBeep(200, 500); // Game over sound
    }
    sethangColor(7); // Reset color
}
