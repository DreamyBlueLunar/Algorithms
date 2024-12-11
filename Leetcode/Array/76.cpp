#include <cstring>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 就这样吧，虽然不是O(n^2)，但是常数有点大了

class Solution {
private:
    vector<int> s_cnt = vector<int>(128, 0);
    vector<int> t_cnt = vector<int>(128, 0);

    bool check();

public:
    string minWindow(string s, string t);
};

bool Solution::check() {
    for (int i = 'A'; i <= 'Z'; i ++) {
        if (s_cnt[i] < t_cnt[i]) {
            return false;
        }
    }
    for (int i = 'a'; i <= 'z'; i ++) {
        if (s_cnt[i] < t_cnt[i]) {
            return false;
        }
    }
    return true;
}

string Solution::minWindow(string s, string t) {
    int i = 0, left = -1, right = s.size();
    for (char ch : t) {
        t_cnt[ch] ++;
    }

    for (int j = 0; j < s.size(); j ++) {
        s_cnt[s[j]] ++;
    
        while (check()) {
            if(right - left > j - i){
                left = i;
                right = j;
            }
            s_cnt[s[i ++]] --;
        }
    }

    return left < 0 ? "" : s.substr(left, right - left + 1);
}


int main(void) {
    string s, t;
    cin >> s >> t;

    Solution sol;
    string res = sol.minWindow(s, t);

    cout << res << endl;

    return 0;
}