#include <vector>
#include <iostream>

#define MAX(a, b) (a > b ? a : b)

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices);
};

// 动态规划
// dp[i][0]: 第i天不持有股票的最大收益
// dp[i][1]: 第i天持有股票的最大收益
// 显然有 dp[i][0] > dp[i][1] 恒成立
// 也可以推得，第i天不持有股票的最大收益，要么是前一天手里没有，第i天也不买；要么是前一天手里有股票，第i天卖出去
// 第i天持有股票的最大收益，要么是前一天手里没有，第i天买入；要么是前一天手里有，第i天保留
int Solution::maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 10, vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];

    for (int i = 1; i < n; i ++) {
        dp[i][0] = MAX(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = MAX(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }

    return dp[n - 1][0];
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
    int ans = sol.maxProfit(arr);

    cout << ans << endl;

    return 0;
}