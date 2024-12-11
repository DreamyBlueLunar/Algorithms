#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s);

private:
    void dfs(string s, int idx, int cnt);
 
    vector<int> index;
    vector<string> res;
};

vector<string> Solution::restoreIpAddresses(string s) {
    index.push_back(0);
    dfs(s, 0, 0);
    return res;
}

void Solution::dfs(string s, int idx, int cnt) {
    if (3 == cnt) {
        index.push_back(s.size());
        for (int i = 1; i < index.size(); i ++) {
            string str = s.substr(index[i - 1], index[i] - index[i - 1]);
            if ('0' == str[0] && str.size() > 1) {
                index.pop_back();
                return ;
            }
            int num = 0;
            for (int j = 0; j < str.size(); j ++) {
                if (str[j] < '0' || str[j] > '9') {
                    index.pop_back();
                    return ;
                }
                num = num * 10 + (str[j] - '0');
            }   
            if (num > 255) {
                index.pop_back();
                return ;
            }
        }

        index.pop_back();
        for (int i = index.size() - 1; i >= 1; i --) {
            s.insert(index[i], ".");
        }
        res.push_back(s);
        return ;
    }

    for (int i = idx; i < s.size() - 1; i ++) {
        index.push_back(i + 1);
        dfs(s, i + 1, cnt + 1);
        index.pop_back();
    }
}

int main(void) {
    string s;
    cin >> s;
    Solution sol;
    vector<string> res = sol.restoreIpAddresses(s);
    for (auto i : res) {
        cout << i << endl;
    }

    return 0;
}