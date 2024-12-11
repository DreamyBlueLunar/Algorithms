#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board);

private:
    bool dfs(vector<vector<char>>& board);
    bool is_valid(vector<vector<char>>& board, int i, int j, char val);
};

void Solution::solveSudoku(vector<vector<char>>& board) {
    dfs(board);
}

bool Solution::is_valid(vector<vector<char>>& board, int row, int col, char val) {
    for (int i = 0; i < 9; i++) { // 判断行里是否重复
        if (board[row][i] == val) {
            return false;
        }
    }
    for (int j = 0; j < 9; j++) { // 判断列里是否重复
        if (board[j][col] == val) {
            return false;
        }
    }
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) { // 判断9方格里是否重复
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == val ) {
                return false;
            }
        }
    }
    return true;
}

// 对棋盘上每一个点位都要做搜索
bool Solution::dfs(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); i ++) {
        for (int j = 0; j < board[0].size(); j ++) {
            if ('.' == board[i][j]) {
                for (char ch = '1'; ch <= '9'; ch ++) {
                    if (is_valid(board, i, j, ch)) {
                        board[i][j] = ch;    
                        if (true == dfs(board)) {
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