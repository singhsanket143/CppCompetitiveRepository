#include<bits/stdc++.h>

class Solution {
public:
    
    bool isSafe(std::vector<std::vector<char> > &b, int i, int j, int num) {
        for(int row = 0; row < 9; row++) {
            if(b[row][j]-'0' == num) return false;
        }
        for(int col = 0; col < 9; col++) {
            if(b[i][col]-'0' == num) return false;
        }
        int r = (i/3)*3;
        int c = (j/3)*3;
        for(int row = r; row < (r)+3; row++) {
            for(int col = c; col < c+3; col++) {
                if(b[row][col] - '0' == num) return false;
            }
        }
        return true;
    }
    
    bool sudoku(std::vector<std::vector<char> > &b, int row, int col) {
        if(col == 9) {
            return sudoku(b, row+1, 0);
        }
        if(row == 9) {
            return true;
        } 
        if(b[row][col] == '.') {
            for(int num = 1; num <= 9; num++) {
                if(isSafe(b, row, col, num)) {
                    b[row][col] = '0'+num;
                    bool res = sudoku(b, row, col+1);
                    if(res) return true;
                    b[row][col] = '.';
                }
            }
            return false;
        }
        else return sudoku(b, row, col+1);
    }
    void solveSudoku(std::vector<std::vector<char>>& board) {
        bool res = sudoku(board, 0, 0);
    }
};















