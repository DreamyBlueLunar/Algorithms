#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target);

private:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int>& candidates, int idx, int sum, int target);
};

void Solution::dfs(vector<int>& candidates, int idx, int sum, int target) {
    if (sum == target) {
        res.push_back(path);
        return ;
    }

    for (int i = idx; i < candidates.size() && sum + candidates[i] <= target; i ++) {
        if (i > idx && candidates[i] == candidates[i - 1]) { // 除此之外，还可以定义一个used数组做这步去重操作
            continue;
        }
        path.push_back(candidates[i]);
        dfs(candidates, i + 1, sum + candidates[i], target);
        path.pop_back();
    }
}

vector<vector<int>> Solution::combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    dfs(candidates, 0, 0, target);
    return res;
}

int main(void) {
    vector<int> arr;
    int x;
    while (cin >> x) {
        arr.push_back(x);
        if ('\n' == cin.get()) {
            break;
        }
    }
    cin >> x;

    Solution sol;
    vector<vector<int>> res = sol.combinationSum2(arr, x);
    for (auto vec : res) {
        for (auto i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}