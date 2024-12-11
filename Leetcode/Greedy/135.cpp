#include <iostream>
#include <vector>

#define MAX(a, b) (a > b ? a : b)

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings);
};

// 两次贪心
// 先考虑和右边的孩子相比，再和左边的孩子比 => 得到全局的解
int Solution::candy(vector<int>& ratings) {
    vector<int> candies(ratings.size(), 1);
    int sum = 0;
    for (int i = 1; i < ratings.size(); i ++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }
    for (int i = ratings.size() - 2; i >= 0; i --) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = MAX(candies[i], candies[i + 1] + 1);
        }
    }

    for (auto i : candies) {
        sum += i;
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

    Solution sol;
    int res = sol.candy(arr);
    cout << res << endl;

    return 0;
}