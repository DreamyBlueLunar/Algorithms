#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums);

private:
    vector<int> path;
    vector<vector<int>> res;

    void dfs(vector<int>& nums, int idx);
};

void Solution::dfs(vector<int>& nums, int idx) {
    if (1 < path.size()) {
        res.push_back(path);
    }

    vector<bool> map(300, false);
    for (int i = idx; i < nums.size(); i ++) {
        if (!path.empty() && path.back() > nums[i] || true == map[nums[i] + 150]) {
            continue;
        }
        map[nums[i] + 150] = true;
        path.push_back(nums[i]);
        dfs(nums, i + 1);
        path.pop_back();
    }
}

vector<vector<int>> Solution::findSubsequences(vector<int>& nums) {
    path.clear();
    res.clear();
    dfs(nums, 0);

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

    Solution sol;
    vector<vector<int>> res = sol.findSubsequences(arr);
    for (auto vec : res) {
        for (auto i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}