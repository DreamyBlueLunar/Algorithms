#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val);
};

int Solution::removeElement(vector<int>& nums, int val) {
    int i = 0, j = 0;
    for (i = 0, j = 0; j < nums.size(); j ++) {
        if (val != nums[j]) {
            nums[i] = nums[j];
            i ++;
        }
    }

    return i;
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
    int cnt = s.removeElement(nums, x);
    cout << cnt << endl;
    for (int i = 0; i < cnt; i ++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}