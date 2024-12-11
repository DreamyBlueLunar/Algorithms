#include <iostream>
#include <vector>

#define MAX(a, b) (a > b ? a : b)

using namespace std;

class Solution {
public:
    int integerBreak(int n);
};

int Solution::integerBreak(int n) {
    vector<int> dp(n + 1);
    dp[2] = 1;
    for (int i = 3; i <= n ; i++) {
        for (int j = 1; j <= i / 2; j++) {
            dp[i] = MAX(dp[i], MAX((i - j) * j, dp[i - j] * j));
        }
    }

    return dp[n];
}

int main(void) {
    int n;
    cin >> n;
    Solution s;
    int ans = s.integerBreak(n);
    cout << ans << endl;
    return 0;
}