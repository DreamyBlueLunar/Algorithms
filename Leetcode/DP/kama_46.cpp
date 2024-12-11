/*
 * 0-1背包问题
 */

#include <iostream>
#include <vector>

#define MAX(a, b) (a > b ? a : b)
#define MODIFIED 1

using namespace std;

const int N = 5050;
vector<int> weight(N, 0);
vector<int> value(N, 0);
#if MODIFIED
    vector<int> dp(N, 0);
#else
    vector<vector<int>> dp(N, vector<int>(N, 0));
#endif

int main(void) {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i ++) {
        cin >> weight[i];
    }
    for (int i = 1; i <= m; i ++) {
        cin >> value[i];
    }

#if MODIFIED
    for (int j = weight[1]; j <= n; j ++) {
        dp[j] = value[1];
    }

    for (int i = 2; i <= m; i ++) {
        for (int j = n; j >= weight[i]; j --) {
            dp[j] = MAX(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    cout << dp[n] << endl;
#else
    for (int j = weight[1]; j <= n; j ++) {
        dp[1][j] = value[1];
    }

    for (int i = 2; i <= m; i ++) {
        for (int j = 0; j <= n; j ++) {
            if (j < weight[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = MAX(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }

    cout << dp[m][n] << endl;
#endif

    return 0;
}