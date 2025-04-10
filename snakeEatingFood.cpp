#include "snakeGame.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

using namespace std;

void setCursorPosition(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hOut, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hOut, &cursorInfo);
}

bool gameOver;
const int width = 20;
const int height = 17;
int x, y, foodX, foodY, score;
vector<pair<int, int>> snake;
char dir;

// Function to set console text color
void setsnakeColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Function to play sound effects
void playsnakeBeep(int freq, int duration) {
    Beep(freq, duration);
}

// Setup the game
void snakesetup() {
    gameOver = false;
    dir = 'd';
    x = width / 2;
    y = height / 2;
    foodX = rand() % width;
    foodY = rand() % height;
    score = 0;
    snake.clear();
    snake.push_back({x, y});
    hideCursor();

}

// Draw the game board
void snakedraw() {
    setCursorPosition(0, 0);

    setsnakeColor(14); // Yellow for walls
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) cout << "#";

            bool printed = false;
            
            if (i == foodY && j == foodX) { 
                setsnakeColor(10); // Green for food
                cout << "F"; 
                printed = true; 
            }
            for (auto segment : snake) {
                if (segment.first == j && segment.second == i) { 
                    setsnakeColor(11); // Cyan for snake
                    cout << "O"; 
                    printed = true; 
                }
            }
            if (!printed) cout << " ";

            if (j == width - 1) cout << "#";
        }
        cout << endl;
    }

    setsnakeColor(14); // Yellow for walls
    for (int i = 0; i < width + 2; i++) cout << "#";
    
    setsnakeColor(7); // Reset to default color
    cout << "\nScore: " << score << endl;
}

// Get user input
void snakeinput() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'w': if (dir != 's') dir = 'w'; break;
            case 's': if (dir != 'w') dir = 's'; break;
            case 'a': if (dir != 'd') dir = 'a'; break;
            case 'd': if (dir != 'a') dir = 'd'; break;
            case 'x': gameOver = true; break;
        }
    }
}

// Snake movement logic
void snakelogic() {
    pair<int, int> prev = snake[0];
    pair<int, int> prev2;
    
    // Move head
    snake[0].first += (dir == 'a' ? -1 : (dir == 'd' ? 1 : 0));
    snake[0].second += (dir == 'w' ? -1 : (dir == 's' ? 1 : 0));

    // Move body
    for (size_t i = 1; i < snake.size(); i++) {
        prev2 = snake[i];
        snake[i] = prev;
        prev = prev2;
    }

    // Check if snake eats food
    if (snake[0].first == foodX && snake[0].second == foodY) {
        score += 10;
        foodX = rand() % width;
        foodY = rand() % height;
        snake.push_back(prev);
        playsnakeBeep(1000, 100); // Eating food sound
    }

    // Collision detection
    if (snake[0].first >= width || snake[0].first < 0 || 
        snake[0].second >= height || snake[0].second < 0) {
        gameOver = true;
        playsnakeBeep(300, 300); // Game Over sound
    }

    for (size_t i = 1; i < snake.size(); i++) {
        if (snake[i] == snake[0]) {
            gameOver = true;
            playsnakeBeep(300, 300); // Game Over sound
        }
    }
}

// Game loop
void snakeEatingFood() {
    snakesetup();
    while (!gameOver) {
        snakedraw();
        snakeinput();
        snakelogic();
        Sleep(1000);
    }

    setsnakeColor(12); // Red for Game Over
    cout << "💀 Game Over! Your score was: " << score << endl;
    setsnakeColor(7); // Reset color
}