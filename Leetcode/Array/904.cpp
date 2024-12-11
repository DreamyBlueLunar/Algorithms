#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits);
};

int Solution::totalFruit(vector<int>& fruits) { // 这样都行啊？
    if (0 == fruits.size()) {
        return 0;
    }
    if (1 == fruits.size()) {
        return 1;
    }

    int i = 0, j = 0;    
    int res = 2;
    int basket_1 = fruits[0], basket_2 = fruits[1];

    for (j = 2; j < fruits.size(); j ++) {
        if (fruits[j] != basket_1 && fruits[j] != basket_2) {
            i = j - 1;
            while (i >= 1 && fruits[i - 1] == fruits[i]) {
                i --;
            }
            basket_1 = fruits[i];
            basket_2 = fruits[j];
        }
        res = max(res, j - i + 1);
    }

    return res;
}

int main(void) {
    int x = 0;
    vector<int> nums = vector<int>();
    while(cin >> x) {
        nums.push_back(x);
        if (cin.get() == '\n') {
            break;
        }
    }
    Solution s;
    int res = s.totalFruit(nums);

    cout << res << endl;

    return 0;
}