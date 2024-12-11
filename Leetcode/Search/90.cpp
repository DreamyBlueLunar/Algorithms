#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums);

private:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int>& nums, int idx);
};

void Solution::dfs(vector<int>& nums, int idx) {
    res.push_back(path);
    for (int i = idx; i < nums.size(); i ++) {
        if (i > idx && nums[i] == nums[i - 1]) {
            continue;
        }
        path.push_back(nums[i]);
        dfs(nums, i + 1);
        path.pop_back();
    }
}

vector<vector<int>> Solution::subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    res.clear();
    path.clear();
    dfs(nums, 0);
    return res;
}

int main(void) {
    int x;
    vector<int> nums;
    while (cin >> x) {
        nums.push_back(x);
        if ('\n' == cin.get()) {
            break;
        }
    }

    Solution sol;
    vector<vector<int>> res = sol.subsetsWithDup(nums);
    for (auto vec : res) {
        for (auto i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}