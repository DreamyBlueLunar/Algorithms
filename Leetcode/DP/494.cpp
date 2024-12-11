#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target);
};

int Solution::findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for (auto i : nums) {
        sum += i;
    }
    if (abs(target) > sum) {
        return 0;
    }
    sum += target;
    if (1 == sum % 2) {
        return 0;
    }
    sum /= 2;

    vector<int> dp(sum + 10, 0);
    dp[0] = 1;

    for (int i = 0; i < nums.size(); i ++) {
        for (int j = sum; j >= nums[i]; j --) {
            dp[j] += dp[j - nums[i]];
        }
    }

    return dp[sum];
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
    int ans = sol.findTargetSumWays(arr, x);
    cout << ans << endl;

    return 0;
}