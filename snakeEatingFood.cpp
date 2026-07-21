#include "snakeGame.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#endif

using namespace std;

void setCursorPosition(int x, int y) {
#ifdef _WIN32
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#else
    cout << "\033[" << (y + 1) << ";" << (x + 1) << "H";
#endif
}

void hideCursor() {
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hOut, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hOut, &cursorInfo);
#else
    cout << "\033[?25l";
#endif
}

bool gameOver;
const int width = 20;
const int height = 17;
int x, y, foodX, foodY, score;
vector<pair<int, int>> snake;
char dir;

// Function to set console text color
void setsnakeColor(int color) {
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

// Function to play sound effects
void playsnakeBeep(int freq, int duration) {
#ifdef _WIN32
    Beep(freq, duration);
#else
    (void)freq; (void)duration;
    cout << '\a';
#endif
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

#ifdef _WIN32
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
#else
void snakeinput() {
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
    char ch = getchar();
    if (ch != EOF) {
        switch (ch) {
            case 'w': if (dir != 's') dir = 'w'; break;
            case 's': if (dir != 'w') dir = 's'; break;
            case 'a': if (dir != 'd') dir = 'a'; break;
            case 'd': if (dir != 'a') dir = 'd'; break;
            case 'x': gameOver = true; break;
        }
    }
    fcntl(STDIN_FILENO, F_SETFL, flags);
}
#endif

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
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    setsnakeColor(12); // Red for Game Over
    cout << "💀 Game Over! Your score was: " << score << endl;
    setsnakeColor(7); // Reset color
}