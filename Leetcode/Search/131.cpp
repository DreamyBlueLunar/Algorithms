#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
     vector<vector<string>> partition(string s);

private:
     vector<vector<string>> res;
     vector<string> path;

     void dfs(string s, int idx);
     bool isPalindrome(const string& str, int begin, int end); // 这个可以优化一下，可以用dp
};

bool Solution::isPalindrome(const string& str, int begin, int end) {
     for (int i = begin, j = end; i < j; i ++, j --) {
          if (str[i] != str[j]) {
               return false;
          }
     }

     return true;
}

void Solution::dfs(string s, int idx) {
     if (idx == s.size()) {
          res.push_back(path);
          return ;
     }

     for (int i = idx; i < s.size(); i ++) {
          if (isPalindrome(s, idx, i)) {
               path.push_back(s.substr(idx, i - idx + 1));
               dfs(s, i + 1);
               path.pop_back();
          }
     }
}

vector<vector<string>> Solution::partition(string s) {
     res.clear();
     path.clear();
     dfs(s, 0);
     return res;
}

int main(void) {
     string s;
     cin >> s;
     Solution sol;
     vector<vector<string>> res = sol.partition(s);
     for (auto vec : res) {
          for (auto ch : vec) {
               cout << ch << " ";
          }
          cout << endl;
     }

     return 0;
}