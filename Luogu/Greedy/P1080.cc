/* 还差个高精度 */

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX(a, b) (a > b ? a : b)

namespace greedy_1080 {

struct minister {
    int a_ = 0;
    int b_ = 0;
};

bool cmp(const minister& a, const minister& b);

}

int main(void) {
    int n = 0;
    int a = 0, b = 0;
    
    std::cin >> n;
    std::cin >> a >> b;
    std::vector<greedy_1080::minister> records(n, greedy_1080::minister());
    for (int i = 0; i < n; i ++) {
        std::cin >> records[i].a_ >> records[i].b_;
    }

    std::sort(records.begin(), records.end(), greedy_1080::cmp);

    long long product = a;
    long long res = product / records[0].b_;
    for (int i = 1; i < n; i ++) {
        product *= records[i - 1].a_;    
        res = MAX(res, product / records[i].b_);
    }

    std::cout << res << std::endl;

    return 0;
}

bool greedy_1080::cmp(const greedy_1080::minister& a, const greedy_1080::minister& b) {
    return a.a_ * a.b_ < b.a_ * b.b_;
}