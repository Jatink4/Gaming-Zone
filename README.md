# 🎮 Gaming Zone - All-in-One Console Game Hub (C++)

Welcome to **Gaming Zone**, your one-stop console-based entertainment hub built with **C++**. This project includes a colorful terminal-based menu system and integrates six mini-games to test your logic, reflexes, and luck!

---

## 🕹️ Games Included

1. **❌⭕ Tic-Tac-Toe**  
   Classic 2-player grid game. Get 3 in a row to win!

2. **✊✋✌️ Rock-Paper-Scissors**  
   Challenge the computer and see who wins the best of rounds!

3. **🎲 Number Guessing Game**  
   Guess the correct number in as few tries as possible.

4. **🐍 Snake Eating Food**  
   Move the snake, eat the apples, and don’t hit the wall!

5. **🎭 Hangman**  
   Guess the hidden word one letter at a time—before the stickman is complete.

6. **🧩 Sudoku Game**  
   Solve a Sudoku puzzle manually and race against time.

---

## 🖥️ Features

- Uses **ANSI escape codes** for colored and styled terminal output 🎨
- Uses standard C++ and runs on most systems with a C++ compiler
- Clean, user-friendly terminal UI
- Menu-driven navigation system
- Modular code using `.h` header files for each game

---

## 🛠️ Getting Started

### 🧳 Prerequisites

- C++ Compiler (G++/MinGW/Visual Studio)
- Terminal that supports ANSI colors (Windows Terminal, Git Bash, Linux terminal)

---

### 🔧 Compilation

Make sure all the `.cpp` and `.h` files are in the same directory. Then compile with:

```bash
g++ main.cpp -o GamingZone

///////////////////////////////////////////////////

🧾 Run on Windows (with symbols/emojis)

For Windows users, you can use the included run_games.bat file to run the game with Unicode (UTF-8) support so emojis and special characters render correctly.
🖱️ Just double-click run_games.bat

@echo off
chcp 65001 >nul
cls 
"GamingZone.exe"
pause
