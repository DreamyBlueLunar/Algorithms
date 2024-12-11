#include <iostream>
#include <vector>

#define MAX(a, b) (a > b ? a : b)

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices);
};

int Solution::maxProfit(vector<int>& prices) {
    vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (int i = 1; i < prices.size(); i ++) {
        dp[i][0] = MAX(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = MAX(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }

    return dp[prices.size() - 1][0];
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