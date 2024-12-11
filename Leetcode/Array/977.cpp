#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums);
};

vector<int> Solution::sortedSquares(vector<int>& nums) {
    vector<int> res = vector<int>();
    int i = 0, j = nums.size() - 1;
    while (i <= j) {
        int sqLeft = nums[i] * nums[i];
        int sqRight = nums[j] * nums[j];

        if (sqLeft >= sqRight) {
            res.push_back(sqLeft);
            i ++;
        } else {
            res.push_back(sqRight);
            j --;
        }
    }

    reverse(res.begin(), res.end());

    return res;
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
    Solution s;
    vector<int> res = s.sortedSquares(nums);

    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}