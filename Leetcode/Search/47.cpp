// 完美，一次过
// 怎么办，不会写代码不会写代码不会写代码不会写代码不会写代码不会写代码不会写代码
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums);

private:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int>& nums, vector<bool>& used);
};

void Solution::dfs(vector<int>& nums, vector<bool>& used) {
    if (path.size() == nums.size()) {
        res.push_back(path);
        return ;
    }

    for (int i = 0; i < nums.size(); i ++) {
        if (true == used[i] || (i > 0 && nums[i] == nums[i - 1] && false == used[i - 1])) { // 去重逻辑，同层且相等的数就可以略过了
            continue;
        }
        used[i] = true;
        path.push_back(nums[i]);
        dfs(nums, used);
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> Solution::permuteUnique(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    res.clear();
    path.clear();
    vector<bool> used(nums.size() + 10, false);
    dfs(nums, used);
    return res;
}

int main(void) {
    vector<int> nums;
    int x;
    while (std::cin >> x) {
        nums.push_back(x);
        if ('\n' == std::cin.get()) {
            break;
        }
    }
    Solution sol;
    vector<vector<int>> res = sol.permuteUnique(nums);
    for (auto vec : res) {
        for (auto i : vec) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
