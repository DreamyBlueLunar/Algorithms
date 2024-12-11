#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k);
    void dfs(int n, int k, int idx);

private:
    vector<int> path;
    vector<vector<int>> res;
};

vector<vector<int>> Solution::combine(int n, int k) {
    dfs(n, k, 1);
    return res;
}

void Solution::dfs(int n, int k, int idx) {
    if (path.size() == k) {
        res.push_back(path);
        return ;
    }

    for (int i = idx; i <= n; i ++) {
        path.push_back(i);
        dfs(n, k, i + 1);
        path.pop_back();
    }
}

int main(void) {
    int n, k;
    cin >> n >> k;
    Solution s;
    vector<vector<int>> ans = s.combine(n, k);
    for (auto vec : ans) {
        for (auto i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}