#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n);

private:
    void dfs(int k, int n, int idx, int sum);

    vector<int> path;
    vector<vector<int>> res;
};

vector<vector<int>> Solution::combinationSum3(int k, int n) {
    dfs(k, n, 1, 0);
    return res;
}

void Solution::dfs(int k, int n, int idx, int sum) {
    if (path.size() == k) {
        if (sum == n) {
            res.push_back(path);
        }
        return ;
    }

    for (int i = idx; i <= 9 && sum + i <= n; i ++) {
        path.push_back(i);
        dfs(k, n, i + 1, sum + i);
        path.pop_back();
    }
}

int main(void) {
    int n, k;
    cin >> k >> n;
    Solution s;
    vector<vector<int>> ans = s.combinationSum3(k, n);
    for (auto vec : ans) {
        for (auto i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}