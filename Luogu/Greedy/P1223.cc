#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct node {
    int id_, t_;

    node() : id_(0), t_(0) {}
    ~node() {}
};

bool cmp(const node& a, const node& b);

int main(void) {
    int n = 0;
    std::cin >> n;
    std::vector<node> que(n, node());
    for (int i = 0; i < n; i ++) {
        std::cin >> que[i].t_;
        que[i].id_ = i + 1;
    }

    std::sort(que.begin(), que.end(), cmp);
    
    double sum = 0.0;
    for (int i = 0; i < n; i ++) {
        sum += (n - i - 1) * que[i].t_;
    }
    sum /= n;

    for (node elm : que) {
        std::cout << elm.id_ << " ";
    }
    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(2) << sum << std::endl;

    return 0;
}

bool cmp(const node& a, const node& b) {
    return a.t_ < b.t_;
}