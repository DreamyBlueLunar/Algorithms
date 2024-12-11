#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s);
};

int Solution::findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int cnt = 0, j = 0, i = 0;
    while (i < g.size() && j < s.size()) {
        if (g[i] <= s[j]) {
            cnt ++;
            i ++;
            j ++;
        } else {
            j ++;
        }
    }

    return cnt;
}

int main(void) {
    vector<int> g, s;
    int x;

    while (cin >> x) {
        g.push_back(x);
        if ('\n' == cin.get()) {
            break;
        }
    }
    
    while (cin >> x) {
        s.push_back(x);
        if ('\n' == cin.get()) {
            break;
        }
    }

    Solution sol;
    int ans = sol.findContentChildren(g, s);
    cout << ans << endl;

    return 0;
}