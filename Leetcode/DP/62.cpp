#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n);
};

int Solution::uniquePaths(int m, int n) {
    vector<vector<int>> dp(m + 10, vector<int>(n + 10, 0));
    
    for (int i = 1; i <= n; i ++) { // 两条边线上的所有位置都是1
        dp[1][i] = 1;
    }
    for (int i = 1; i <= m; i ++) { // 两条边线上的所有位置都是1
        dp[i][1] = 1;
    }

    for (int i = 2; i <= m; i ++) {
        for (int j = 2; j <= n; j ++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m][n];
}

int main(void) {
    int m, n;
    cin >> m >> n;
    Solution sol;
    int ans = sol.uniquePaths(m, n);
    cout << ans << endl;
    return 0;
}