#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills);
};

bool Solution::lemonadeChange(vector<int>& bills) {
    vector<int> cnt = vector<int>(25, 0);
    for (int i = 0; i < bills.size(); i ++) {
        cnt[bills[i]] ++;
        if (bills[i] > 5) {
            int delta = bills[i] - 5;
            while (delta) {
                int cnt = delta / 20;
                
                delta %= 20;
            }
        }
    }

    return true;
}

int main(void) {

}