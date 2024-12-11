/* P1090.cc */

#include <iostream>
#include <queue>
#include <vector>

struct cmp {
    bool operator()(const int& a, const int& b) {
        return a > b;
    }
};

int main(void) {
    std::priority_queue<int, std::vector<int>, cmp> pq;        
    int n = 0, x = 0;
    int sum = 0;
    std::cin >> n;

    for (int i = 0; i < n; i ++) {
        std::cin >> x;
        pq.push(x);
    }

    while (pq.size() > 1) {
        int bunch_1 = pq.top();
        pq.pop();
        int bunch_2 = pq.top();
        pq.pop();
        sum += bunch_1 + bunch_2;
        pq.push(bunch_1 + bunch_2);
    }

    std::cout << sum << std::endl;

    return 0;
}