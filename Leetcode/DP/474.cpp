#include <iostream>
#include <vector>

#define MAX(a, b) (a > b ? a : b)

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n);
};

int Solution::findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 10, vector<int> (n + 10, 0));
    for (auto str : strs) {
        int cnt_0 = 0, cnt_1 = 0;
        for (auto ch : str) {
            if ('0' == ch) {
                cnt_0 ++;
            } else {
                cnt_1 ++;
            }
        }

        for (int i = m; i >= cnt_0; i --) {
            for (int j = n; j >= cnt_1; j --) { // 在要这个str和不要这个str之间选更优解
                dp[i][j] = MAX(dp[i][j], dp[i - cnt_0][j - cnt_1] + 1);
            }
        }
    }

    return dp[m][n];
}

int main(void) {
    string str;
    vector<string> strs;
    int m, n;
    while (cin >> str) {
        strs.push_back(str);
        if ('\n' == cin.get()) {
            break;
        }
    }
    cin >> m >> n;

    Solution sol;
    cout << sol.findMaxForm(strs, m, n) << endl;

    return 0;
}