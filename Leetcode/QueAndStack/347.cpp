#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k);

private:
    struct cmp {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
            return a.second < b.second;
        }
    };
};

vector<int> Solution::topKFrequent(vector<int>& nums, int k) {
    vector<int> res;
    unordered_map<int, int> m;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    for (auto it : nums) {
        m[it] ++;
    }

    for (auto it = m.begin(); it != m.end(); it ++) {
        pq.push(*it);
    }

    for (int i = 1; i <= k; i ++) {
       res.push_back(pq.top().first);
       pq.pop();
    }

    return res;
}

int main(void) {
    vector<int> arr;
    int x;

    while (cin >> x) {
        arr.push_back(x);
        if (cin.get() == '\n') {
            break;
        }
    }
    cin >> x;

    Solution s;
    vector<int> ans = s.topKFrequent(arr, x);
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << endl;
    
    return 0;
}