#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost);
};

int Solution::canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int curSum = 0;
    int totalSum = 0;
    int start = 0;
    for (int i = 0; i < gas.size(); i++) {
        curSum += gas[i] - cost[i];
        totalSum += gas[i] - cost[i];
        if (curSum < 0) {   // 当前累加rest[i]和 curSum一旦小于0
            start = i + 1;  // 起始位置更新为i+1
            curSum = 0;     // curSum从0开始
        }
    }
    if (totalSum < 0) return -1; // 说明怎么走都不可能跑一圈了
    return start;
}

int main(void) {
    vector<int> gas, cost;
    int x;
    while (cin >> x) {
        gas.push_back(x);
        if ('\n' == cin.get()) {
            break;
        }
    }
    while (cin >> x) {
        cost.push_back(x);
        if ('\n' == cin.get()) {
            break;
        }
    }

    Solution sol;
    int idx = sol.canCompleteCircuit(gas, cost);
    cout << idx << endl;

    return 0;
}