#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums);
};

// 这套解法多少有点动态规划的味道在
int Solution::jump(vector<int>& nums) {
    vector<int> cnt(nums.size(), 0);
    int cover = 0;
    for (int i = 0; cover < nums.size() && i <= cover; i ++) {
        cover = max(cover, i + nums[i]);
        for (int j = i + 1; j <= cover && j < cnt.size(); j ++) {
            cnt[j] = cnt[j] == 0 ? cnt[i] + 1 : cnt[j];
        }
    }

    return cnt[nums.size() - 1];
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
    cout << sol.jump(arr) << endl;

    return 0;
}