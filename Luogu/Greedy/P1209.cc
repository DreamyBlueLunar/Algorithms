#include <iostream>
#include <vector>
#include <algorithm>

struct milk {
    int p_, a_;

    milk() : p_(0), a_(0) {}
    ~milk() {}
};

bool cmp(const milk& a, const milk& b);

int main(void) {
    int n = 0, m = 0;
    int sum = 0;
    std::cin >> n >> m;

    std::vector<milk> arr(m, milk());

    for (int i = 0; i < m; i ++) {
        std::cin >> arr[i].p_ >> arr[i].a_;
    }

    std::sort(arr.begin(), arr.end(), cmp);

    for (int i = 0; i < m && n > 0; i ++) {
        if (n - arr[i].a_ >= 0) {
            sum += arr[i].a_ * arr[i].p_;
        } else {
            sum += arr[i].p_ * n;
        }
        n -= arr[i].a_;
    }

    std::cout << sum << std::endl;

    return 0;
}

bool cmp(const milk& a, const milk& b) {
    return a.p_ < b.p_;
}