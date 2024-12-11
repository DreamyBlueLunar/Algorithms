#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t);
};

string minWindow(string s, string t) {
    int len = 0x7fffffff;
    int cnt = t.size();
    vector<int> numOfLetters = vector<int>(200, 0);
    vector<char> lettersOfT = vector<char>(200, false);
    int i = 0, j = 0, begin = 0, end = 0;
    for (int k = 0; k < t.size(); k ++) {
        numOfLetters[t[k]] ++;
        lettersOfT[t[k]] = true;
    }

    // t ∈ s[i:j]  => i ++
    // t !∈ s[i:j] => j ++
    for (j = 0; j < s.size(); j ++) {
        if (0 == cnt) {
            if (len > j - i + 1) {
                len = j - i + 1;
                begin = i;
                end = j;
            }
            cnt ++;
            numOfLetters[s[i]] ++;
            while (!numOfLetters[s[++i]]);
        }

    }

    return s.substr(begin, end);
}

int main(void) {


    return 0;
}