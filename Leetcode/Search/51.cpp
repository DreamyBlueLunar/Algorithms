#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n);

private:
    vector<vector<string>> res;

    bool is_valid(vector<string>& board, int row, int clu);
    void dfs(vector<string>& board, int row);
};

bool Solution::is_valid(vector<string>& board, int row, int clu) {
    for (int i = 0; i < row; i ++) {
        if (board[i][clu] == 'Q') {
            return false;
        }
    }

    for (int i = row - 1, j = clu + 1; i >= 0 && j < board.size(); i --, j ++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    for (int i = row - 1, j = clu - 1; i >= 0 && j >= 0; i --, j --) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

void Solution::dfs(vector<string>& board, int row) {
    if (row == board.size()) {
        res.push_back(board);
        return ;
    }

    for (int clu = 0; clu < board.size(); clu ++) {
        if (is_valid(board, row, clu)) {
            board[row][clu] = 'Q';
            dfs(board, row + 1);
            board[row][clu] = '.';
        }
    }
}

vector<vector<string>> Solution::solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    res.clear();
    dfs(board, 0);
    return res;
}

int main(void) {
    int n = 0;
    cin >> n;
    Solution sol;
    vector<vector<string>> res = sol.solveNQueens(n);
    for (auto vec : res) {
        for (auto str : vec) {
            for (auto ch : str) {
                cout << ch << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}