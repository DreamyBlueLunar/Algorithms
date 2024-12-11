#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums);

private:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int>& nums, int idx);
};

void Solution::dfs(vector<int>& nums, int idx) {
    res.push_back(path);
    for (int i = idx; i < nums.size(); i ++) {
        path.push_back(nums[i]);
        dfs(nums, i + 1);
        path.pop_back();
    }
}

vector<vector<int>> Solution::subsets(vector<int>& nums) {
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
    vector<vector<int>> res = sol.subsets(nums);
    for (auto arr : res) {
        for (auto i : arr) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
