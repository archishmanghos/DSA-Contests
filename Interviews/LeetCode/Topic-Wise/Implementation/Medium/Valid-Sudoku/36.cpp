#include <bits/stdc++.h>
using namespace std;

class SudokuChecker {
   private:
    vector<vector<char>> board;

    bool rowsOk() {
        for (int row = 0; row < 9; row++) {
            set<char> rowChecker;
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    continue;
                }

                if (rowChecker.find(board[row][col]) != rowChecker.end()) {
                    return false;
                }

                rowChecker.insert(board[row][col]);
            }
        }

        return true;
    }

    bool columnsOk() {
        for (int col = 0; col < 9; col++) {
            set<char> colChecker;
            for (int row = 0; row < 9; row++) {
                if (board[row][col] == '.') {
                    continue;
                }

                if (colChecker.find(board[row][col]) != colChecker.end()) {
                    return false;
                }

                colChecker.insert(board[row][col]);
            }
        }

        return true;
    }

    bool eachSquareOk() {
        for (int row = 0; row < 7; row += 3) {
            for (int col = 0; col < 7; col += 3) {
                set<char> squareChecker;
                for (int subRow = row; subRow < row + 3; subRow++) {
                    for (int subCol = col; subCol < col + 3; subCol++) {
                        if (board[subRow][subCol] == '.') {
                            continue;
                        }

                        if (squareChecker.find(board[subRow][subCol]) != squareChecker.end()) {
                            return false;
                        }

                        squareChecker.insert(board[subRow][subCol]);
                    }
                }
            }
        }

        return true;
    }

   public:
    SudokuChecker(vector<vector<char>> board) {
        this->board = board;
    }

    bool checkValidSudoku() {
        return columnsOk() and rowsOk() and eachSquareOk();
    }
};

class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        SudokuChecker* sc = new SudokuChecker(board);
        return sc->checkValidSudoku();
    }
};