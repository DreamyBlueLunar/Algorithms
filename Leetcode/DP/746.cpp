#include <iostream>
#include <vector>

#define MIN(a, b) (a < b ? a : b)

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost);
};

int Solution::minCostClimbingStairs(vector<int>& cost) {
    int dp_2 = 0;
    int dp_1 = 0;
    int dp_i = 0;
    for (int i = 2; i <= cost.size(); i ++) {
        dp_i = MIN(dp_1 + cost[i - 1], dp_2 + cost[i - 2]);
        dp_2 = dp_1;
        dp_1 = dp_i;
    }

    return dp_i;
}

int main(void) {
    vector<int> cost;
    int x;
    while (cin >> x) {
        cost.push_back(x);
        if ('\n' == cin.get()) {
            break;
        }
    }

    Solution sol;
    int ans = sol.minCostClimbingStairs(cost);
    cout << ans << endl;

    return 0;
}