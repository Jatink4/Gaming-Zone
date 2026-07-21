#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>   // For time()
#include <cstdlib> // For rand()

using namespace std;
using namespace std::chrono;

#define N 9

void setsudokuColor(int color) {
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

bool isValid(vector<vector<int>>& board, int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num) return false;
        if (board[(row/3)*3 + i/3][(col/3)*3 + i%3] == num) return false;
    }
    return true;
}

void printSudoku(const vector<vector<int>>& board) {
    setsudokuColor(11);
    cout << "-------------------------\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j % 3 == 0) cout << "| ";
            if (board[i][j] == 0) {
                setsudokuColor(7);
                cout << "_ ";
            } else {
                setsudokuColor(10);
                cout << board[i][j] << " ";
            }
            setsudokuColor(11);
        }
        cout << "|\n";
        if ((i + 1) % 3 == 0) cout << "-------------------------\n";
    }
    setsudokuColor(7);
}

bool isSudokuComplete(vector<vector<int>>& board) {
    for (int row = 0; row < N; row++)
        for (int col = 0; col < N; col++)
            if (board[row][col] == 0 || !isValid(board, row, col, board[row][col]))
                return false;
    return true;
}

vector<vector<int>> getRandomSudoku() {
    vector<vector<vector<int>>> puzzles = {
        {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
        },
        {
            {0, 2, 0, 6, 0, 8, 0, 0, 0},
            {5, 8, 0, 0, 0, 9, 7, 0, 0},
            {0, 0, 0, 0, 4, 0, 0, 0, 0},
            {3, 7, 0, 0, 0, 0, 5, 0, 0},
            {6, 0, 0, 0, 0, 0, 0, 0, 4},
            {0, 0, 8, 0, 0, 0, 0, 1, 3},
            {0, 0, 0, 0, 2, 0, 0, 0, 0},
            {0, 0, 9, 8, 0, 0, 0, 3, 6},
            {0, 0, 0, 3, 0, 6, 0, 9, 0}
        },
        {
            {0, 0, 0, 0, 0, 7, 0, 9, 0},
            {1, 0, 0, 0, 0, 0, 0, 0, 2},
            {0, 0, 2, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 5, 0, 0, 0, 0, 0},
            {0, 4, 0, 1, 0, 2, 0, 5, 0},
            {0, 0, 0, 0, 0, 6, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 6, 0, 0},
            {2, 0, 0, 0, 0, 0, 0, 0, 9},
            {0, 3, 0, 7, 0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 2, 6, 0, 7, 0, 1},
            {6, 8, 0, 0, 7, 0, 0, 9, 0},
            {1, 9, 0, 0, 0, 4, 5, 0, 0},
            {8, 2, 0, 1, 0, 0, 0, 4, 0},
            {0, 0, 4, 6, 0, 2, 9, 0, 0},
            {0, 5, 0, 0, 0, 3, 0, 2, 8},
            {0, 0, 9, 3, 0, 0, 0, 7, 4},
            {0, 4, 0, 0, 5, 0, 0, 3, 6},
            {7, 0, 3, 0, 1, 8, 0, 0, 0}
        },
        {
            {0, 0, 5, 3, 0, 0, 0, 0, 0},
            {8, 0, 0, 0, 0, 0, 0, 2, 0},
            {0, 7, 0, 0, 1, 0, 5, 0, 0},
            {4, 0, 0, 0, 0, 5, 3, 0, 0},
            {0, 1, 0, 0, 7, 0, 0, 0, 6},
            {0, 0, 3, 2, 0, 0, 0, 8, 0},
            {0, 6, 0, 5, 0, 0, 0, 0, 9},
            {0, 0, 4, 0, 0, 0, 0, 3, 0},
            {0, 0, 0, 0, 0, 9, 7, 0, 0}
        }
    };

    srand(time(0));
    int index = rand() % puzzles.size();
    return puzzles[index];
}

void playSudoku() {
    vector<vector<int>> board = getRandomSudoku();

    cout << "\n🧩 Fill the Sudoku Puzzle (Enter 0 to skip filling a cell):\n";
    printSudoku(board);

    auto start = high_resolution_clock::now();

    int wrongAttempts = 0;
    const int maxAttempts = 5;

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                int input;
                do {
                    setsudokuColor(14);
                    cout << "Enter number (1-9) at [" << row+1 << "," << col+1 << "]: ";
                    cin >> input;
                    if (input >= 1 && input <= 9 && isValid(board, row, col, input)) {
                        board[row][col] = input;
                        break;
                    } else if (input == 0) {
                        break;
                    } else {
                        setsudokuColor(12);
                        cout << "❌ Invalid number or conflicts. Try again!\n";
                        wrongAttempts++;
                        if (wrongAttempts >= maxAttempts) {
                            setsudokuColor(12);
                            cout << "\n🚫 You have used all 5 wrong attempts. Game Over.\n";
                            setsudokuColor(7);
                            return;
                        }
                        setsudokuColor(7);
                        cout << "Remaining chances: " << (maxAttempts - wrongAttempts) << "\n";
                    }
                } while (true);
                printSudoku(board);
            }
        }
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end - start).count();

    if (isSudokuComplete(board)) {
        setsudokuColor(10);
        cout << "\n✅ Sudoku Solved Successfully in " << duration << " seconds!\n";
    } else {
        setsudokuColor(12);
        cout << "\n❌ Incorrect or Incomplete Solution.\n";
    }

    printSudoku(board);
    setsudokuColor(7);
}
