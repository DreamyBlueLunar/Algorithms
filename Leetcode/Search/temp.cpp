#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board);

private:

    bool dfs(vector<vector<char>>& board);
    bool is_valid(vector<vector<char>>& board, int i, int j, char num);
};

bool Solution::dfs(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j ++) {
            if ('.' == board[i][j]) {
                for (char num = '1'; num <= '9'; num ++) {
                    if (is_valid(board, i, j, num)) {
                        board[i][j] = num;
                        if (dfs(board)) {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }

    return true;
}

bool Solution::is_valid(vector<vector<char>>& board, int i, int j, char num) {
    int row = i - (i % 3);
    int clu = j - (j % 3);

    for (int k = 0; k < 3; k ++) {
        for (int l = 0; l < 3; l ++) {
            if (num == board[row + k][clu + l]) {
                return false;
            }
        }
    }

    for (int k = 0; k < 9; k ++) {
        if (num == board[k][j] || num == board[i][k]) {
            return false;
        }
    }

    return true;
}

void Solution::solveSudoku(vector<vector<char>>& board) {
    dfs(board);
}

