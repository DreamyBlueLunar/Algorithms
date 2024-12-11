#include <vector>
#include <iostream>

#define MAX(a, b) (a > b ? a : b)

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums);
};

bool Solution::canPartition(vector<int>& nums) {
    int sum = 0;
    for (auto i : nums) {
        sum += i;
    }
    if (1 == sum % 2) {
        return false;
    }
    int target = sum / 2;

    vector<int> dp(target + 10, 0);
    for (int i = nums[0]; i <= target; i ++) {
        dp[i] = nums[0];
    }
    for (int i = 1; i < nums.size(); i ++) {
        for (int j = target; j >= nums[i]; j --) {
            dp[j] = MAX(dp[j], dp[j - nums[i]] + nums[i]);
        }
    }

    if (target == dp[target]) {
        return true;
    }
    return false;
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
    cout << sol.canPartition(nums) << endl;

    return 0;
}