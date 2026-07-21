# 🎮 Gaming Zone - Console Game Hub with Browser Access

Gaming Zone is a C++ collection of six mini-games with a colorful terminal interface. It now also supports browser access through a web terminal, so you can launch it in a browser tab.

---

## 🕹️ Games Included

1. **❌⭕ Tic-Tac-Toe**  
   Classic 2-player grid game. Get 3 in a row to win.

2. **✊✋✌️ Rock-Paper-Scissors**  
   Challenge the computer and see who wins the best of rounds.

3. **🎲 Number Guessing Game**  
   Guess the correct number in as few tries as possible.

4. **🐍 Snake Eating Food**  
   Move the snake, eat the apples, and avoid the walls.

5. **🎭 Hangman**  
   Guess the hidden word one letter at a time before the stickman is complete.

6. **🧩 Sudoku Game**  
   Solve a Sudoku puzzle manually and race against time.

---

## ✨ Features

- Colorful terminal-based UI with ANSI escape codes
- Modular C++ game structure with separate header/source files
- Browser access through a local web terminal
- Works well in Linux, macOS, and Windows terminal environments

---

## 🛠️ Run Locally

### 1) Install prerequisites

On Ubuntu/Debian:

```bash
sudo apt update
sudo apt install -y build-essential ttyd
```

On Windows, use WSL or a terminal with a C++ compiler installed.

### 2) Compile the project

```bash
g++ main.cpp ticTacToe.cpp rockPaperScissors.cpp numberGuessingGame.cpp snakeEatingFood.cpp hangman.cpp sudoku.cpp -o GamingZone
```

### 3) Start the game in the terminal

```bash
./GamingZone
```

### 4) Open it in a browser

Run the browser terminal server:

```bash
ttyd -p 7681 bash -lc 'cd /path/to/Gaming-Zone && ./GamingZone'
```

Then open:

```text
http://127.0.0.1:7681/
```

---

## 🌐 Host a Web Page on Netlify

This project is a terminal-based C++ app, so Netlify cannot run the compiled binary directly. The easiest way to publish a web presence is to host a simple static landing page and link to your browser terminal.

### What to do

1. Keep the project files in a GitHub repository.
2. Add a simple static page such as [index.html](index.html).
3. In Netlify, create a new site from GitHub or use Netlify Drop.
4. Set the publish directory to the project root.
5. Deploy the site.

### Netlify steps

- Go to https://app.netlify.com/
- Click "Add new site" -> "Import an existing project"
- Choose your GitHub repository
- Leave the build command empty and set the publish directory to `.`
- Click "Deploy site"

### Important note

If you want a fully interactive web game instead of a terminal view, the games will need to be rewritten in HTML/CSS/JavaScript. The current C++ version is best suited for local play or browser-based terminal access.

---

## 📦 Files

- [main.cpp](main.cpp) – Main menu and game launcher
- [ticTacToe.cpp](ticTacToe.cpp) and [ticTacToe.h](ticTacToe.h)
- [rockPaperScissors.cpp](rockPaperScissors.cpp) and [rockPaperScissors.h](rockPaperScissors.h)
- [numberGuessingGame.cpp](numberGuessingGame.cpp) and [numberGuess.h](numberGuess.h)
- [snakeEatingFood.cpp](snakeEatingFood.cpp) and [snakeGame.h](snakeGame.h)
- [hangman.cpp](hangman.cpp) and [hangman.h](hangman.h)
- [sudoku.cpp](sudoku.cpp) and [sudoku.h](sudoku.h)
- [index.html](index.html) – Simple landing page for Netlify hosting
