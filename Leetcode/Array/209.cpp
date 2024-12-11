#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums);
};

int Solution::minSubArrayLen(int target, vector<int>& nums) {
    int i = 0, j = 0;
    int res = 0x7fffffff;
    long long sum = 0;
    for (j = 0; j < nums.size(); j ++) {
        sum += nums[j];
        while (sum >= target) {
            res = min(res, j - i + 1);
            sum -= nums[i];
            i ++;
        }
    }

    return res == 0x7fffffff ? 0 : res;
}

int main(void) {
    int x = 0;
    vector<int> nums = vector<int>();
    while(cin >> x) {
        nums.push_back(x);
        if (cin.get() == '\n') {
            break;
        }
    }
    cin >> x;
    Solution s;
    int ans = s.minSubArrayLen(x, nums);

    cout << ans << endl;

    return 0;
}