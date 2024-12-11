#include <vector>
#include <iostream>

using namespace std;

#define MAX(a, b) (a > b ? a : b)

class Solution {
public:
    int maxProfit(vector<int>& prices);
};

// 贪心，收集所有的正利润，最后得到的一定是最大利润
int Solution::maxProfit(vector<int>& prices) {
    int res = 0;
    for (int i = 1; i < prices.size(); i ++) {
        res += MAX(prices[i] - prices[i - 1], 0);
    }
    return res;
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