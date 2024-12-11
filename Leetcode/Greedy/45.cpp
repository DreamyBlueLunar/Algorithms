#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums);
};

int Solution::jump(vector<int>& nums) {
    int res = 0, cur_dist = 0, next_dist = 0;
    if (1 == nums.size()) {
        goto done;
    }

    for (int i = 0; i < nums.size(); i ++) {
        next_dist = max(i + nums[i], next_dist);

        if (i == cur_dist) {
            res ++;
            cur_dist = next_dist;
            if (next_dist >= nums.size() - 1) {
                goto done;
            }
        }
    }
    
done:
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
    cout << sol.jump(arr) << endl;

    return 0;
}