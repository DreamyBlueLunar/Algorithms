#include <iostream>
#include <vector>

#define DP 1

#define MAX(a, b) (a > b ? a : b)

using namespace std;

class Solution {
private:
    const static int N = 1e5 + 10;
    int f[N];
public:
    int findLengthOfLCIS(vector<int>& nums);
};

int Solution::findLengthOfLCIS(vector<int>& nums) {
#if DP
    int n = nums.size();
    if (n == 0) return 0;
    
    int res = 1, k = 0;
    for (int i = 0; i < n; i++) {
        f[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1])  {
            f[i] = f[i - 1] + 1;
        }
        if (f[i] > res) {
            res = f[i];
        }
    }

    return res;
#else
    int i = 0, j = 0, cnt = 0;
    for (j = 1; j < nums.size(); j ++) {
        if (nums[j] <= nums[j - 1]) {
            cnt = MAX(cnt, j - i);
            i = j;
        }
    }
    cnt = MAX(cnt, j - i);

    return cnt;
#endif
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
    int ans = sol.findLengthOfLCIS(arr);
    cout << ans << endl;

    return 0;
}
