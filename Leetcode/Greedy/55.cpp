#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums);
};

// 每次都跳到最大的范围，每移动一步，就更新能覆盖的最大范围，从而得到全局的跳跃范围，和数组size做比较
bool Solution::canJump(vector<int>& nums) {
    int cover = 0;
    if (nums.size() == 1) {
        return true;
    }
    for (int i = 0; i <= cover; i++) { 
        cover = max(i + nums[i], cover);
        if (cover >= nums.size() - 1) {
            return true;
        }
    }
    return false;
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
    cout << sol.canJump(arr) << endl;

    return 0;
}