#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target);
};

vector<vector<int>> Solution::fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    int nums_len = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums_len; i ++) {
        if (nums[i] > target && nums[i] >= 0) {
            break;
        }
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        for (int j = i + 1; j < nums_len; j ++) {
            if (nums[i] + nums[j] > target && nums[j] >= 0) {
                break;
            }
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }

            int left = j + 1;
            int right = nums_len - 1;
            while (left < right) {
                if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target) {
                    right --;
                } else if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target) {
                    left ++;
                } else {
                        res.push_back(
                            vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;

                        right--;
                        left++;
                }
            }
        }
    }

    return res;
}

int main(void) {



    return 0;
}