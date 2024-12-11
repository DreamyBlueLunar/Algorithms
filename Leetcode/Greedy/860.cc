#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills);
};

// 这个题的贪心策略还是很明显的
// 显然找零的时候应该先给面额较大的钱，因为多凑几张5块总能凑到10块或者15块，而10块的面额却没有办法拆成5块
// 换言之，5块对找零的作用最大，10块次之，所以应该尽量多留5块，其次10块
bool Solution::lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0, twenty = 0;
    for (int i = 0; i < bills.size(); i ++) {
        switch(bills[i]) {
            case 5: {
                five ++;
                break;
            }
            case 10: {
                if (0 == five) {
                    return false;
                }
                ten ++;
                five --;
                break;
            }
            case 20: {
                if (five > 0 && ten > 0) {
                    ten --;
                    five --;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
                break;
            }
        }
    }

    return true;
}