#include <iostream>
#include <vector>

#define MAX(a, b) (a > b ? a : b)

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums);
};

int Solution::maxSubArray(vector<int>& nums) { // 不是，这个题也能贪？我明儿遇到直接dp处理了
    int res = -0x7fffffff;
    int sum = 0;
    for (int i = 0; i < nums.size(); i ++) {
        sum += nums[i];
        res = MAX(sum, res);
        if (sum < 0) {
            sum = 0;
        }
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
    Solution s;
    int ans = s.maxSubArray(arr);
    cout << ans << endl;
    return 0;
}