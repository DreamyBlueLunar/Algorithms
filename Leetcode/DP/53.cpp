#include <iostream>
#include <vector>

#define MAX(a, b) (a > b ? a : b)

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums);
};

int Solution::maxSubArray(vector<int>& nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int ans = dp[0];

    for (int i = 1; i < nums.size(); i ++) {
        dp[i] = MAX(dp[i - 1] + nums[i], nums[i]);
        ans = MAX(ans, dp[i]);
    }

    return ans;
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
    Solution s;
    int ans = s.maxSubArray(arr);
    cout << ans << endl;
    return 0;
}