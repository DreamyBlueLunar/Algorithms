#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums);
};

int Solution::wiggleMaxLength(vector<int>& nums) {
    if (nums.size() <= 1) {
        return nums.size();
    }

    int cur_diff = 0, pre_diff = 0;
    int res = 1;
    for (int i = 0; i < nums.size() - 1; i ++) {
        cur_diff = nums[i + 1] - nums[i];
        if ((cur_diff < 0 && pre_diff >= 0) || (cur_diff > 0 && pre_diff <= 0)) {
            res ++;
            pre_diff = cur_diff;
        }
    }

    return res;
}