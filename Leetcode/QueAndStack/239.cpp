#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k);
};

// 单调队列
// 要求滑动窗口中的最大值，那就要保证队头元素是当前最大的，也就是要维护一个单调不增的队列
vector<int> Solution::maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> q = vector<int>(n, 0);           // q里面放的是下标
    vector<int> ans = vector<int>();

    int h = 0, t = -1;
    for (int i = 0; i < n; i ++) {
        while (h <= t && nums[q[t]] < nums[i]) { // 让比即将入队的元素差的元素从队尾出队，这些就是被丢掉的元素
            -- t;
        }
        q[++ t] = i;                             // 入队
        if (q[h] < i - k + 1) {                  // 如果发现当前队头元素已经不在滑动窗口内了，就从队头出队
            ++ h;
        }
        if (i >= k - 1) {                        // 每次从队头拿出当前要的最大值
            ans.push_back(nums[q[h]]);
        }
    }

    return ans;
}

int main(void) {
    vector<int> arr = vector<int>();
    int num, k;
    while (cin >> num) {
        arr.push_back(num);
        if (cin.get() == '\n') {
            break;
        }
    }
    cin >> k;

    Solution s;
    vector<int> res = s.maxSlidingWindow(arr, k);
    for (auto it : res) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}