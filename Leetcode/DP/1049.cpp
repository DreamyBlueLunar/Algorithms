#include <iostream>
#include <vector>

#define MAX(a, b) (a > b ? a : b)

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones);
};

int Solution::lastStoneWeightII(vector<int>& stones) {
    int sum = 0;
    for (auto i : stones) {
        sum += i;
    }
    int target = sum / 2;
    
    vector<int> dp(target + 10, 0);
    for (int i = stones[0]; i <= target; i ++) {
        dp[i] = stones[0];
    }

    for (int i = 1; i < stones.size(); i ++) {
        for (int j = target; j >= stones[i]; j --) {
            dp[j] = MAX(dp[j], dp[j - stones[i]] + stones[i]);
        }   
    }

    return sum - 2 * dp[target];
}

int main(void) {
    vector<int> stones;
    int x;
    while (cin >> x) {
        stones.push_back(x);
        if ('\n' == cin.get()) {
            break;
        }
    }

    Solution sol;
    int ans = sol.lastStoneWeightII(stones);
    cout << ans << endl;

    return 0;
}