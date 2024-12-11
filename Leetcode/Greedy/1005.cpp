#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k);
};

struct cmp {
    bool operator()(int a, int b) {
        return a > b;
    }
};


// 反转当前最小的数，如果这个数是负数，显然反转之后对总和的增量是最大的；
// 如果这个数是正数，显然对总和的损失是最小的；
// 如果是0，显然不会影响总和
// 逻辑上来说，这个算法应该是对的
int Solution::largestSumAfterKNegations(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, cmp> pq;
    int sum = 0, temp = 0;
    for (auto num : nums) {
        pq.push(num);
    }

    while (k --) {
        temp = pq.top();
        pq.pop();
        pq.push(-temp);
    }

    while (!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }

    return sum;
}

int main(void) {
    vector<int> arr;
    int x = 0;
    while (cin >> x) {
        arr.push_back(x);
        if ('\n' == cin.get()) {
            break;
        }
    }
    cin >> x;

    Solution sol;
    int res = sol.largestSumAfterKNegations(arr, x);
    cout << res << endl;
    
    return 0;
}