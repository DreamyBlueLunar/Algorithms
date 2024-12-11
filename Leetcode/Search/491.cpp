#include <iostream>
#include <vector>
#include <unordered_set>

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
    if (path.size() >= 2) {
        res.push_back(path);
    }
    
    unordered_set<int> uset; // 使用set对本层元素进行去重
    for (int i = idx; i < nums.size(); i++) {
        if ((!path.empty() && nums[i] < path.back())
                || uset.find(nums[i]) != uset.end()) {
                continue;
        }
        uset.insert(nums[i]); // 记录这个元素在本层用过了，本层后面不能再用了
        path.push_back(nums[i]);
        dfs(nums, i + 1);
        path.pop_back();
    }
}

vector<vector<int>> Solution::findSubsequences(vector<int>& nums) {
    res.clear();
    path.clear();
    dfs(nums, 0);
    return res;
}

int main(void) {
    vector<int> nums;
    int x;
    while (cin >> x) {
        nums.push_back(x);
        if ('\n' == cin.get()) {
            break;
        }
    }

    Solution sol;
    vector<vector<int>> res = sol.findSubsequences(nums);
    for (auto vec : res) {
        for (auto i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}