#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);

private:
    void dfs(vector<int>& candidates, int target, int sum, int idx);

    vector<int> path;
    vector<vector<int>> res;
};

vector<vector<int>> Solution::combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end()); // 要剪枝的话你得盯一下数组中的顺序
    dfs(candidates, target, 0, 0);
    return res;
}

void Solution::dfs(vector<int>& candidates, int target, int sum, int idx) {
    if (target == sum) {
        res.push_back(path);
        return ;
    }

    int n = candidates.size();
    for (int i = idx; i < n && sum + candidates[i] <= target; i ++) {
        path.push_back(candidates[i]);
        dfs(candidates, target, sum + candidates[i], i);
        path.pop_back();
    }
}

int main(void) {
    vector<int> arr;
    int x = 0;
    while (cin >> x) {
        arr.push_back(x);
        if (cin.get() == '\n') {
            break;
        }
    }
    cin >> x;

    Solution s;
    vector<vector<int>> res = s.combinationSum(arr, x);
    for (auto vec : res) {
        for (auto i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}