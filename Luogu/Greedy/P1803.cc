#include <iostream>
#include <vector>
#include <algorithm>

struct contest {
    int begin_, end_;

    contest() : begin_(0), end_(0) {}
    ~contest() {}
};

bool cmp(const contest& a, const contest& b);

int main(void) {
    int n = 0, cnt = 1;
    std::cin >> n;
    std::vector<contest> contests(n, contest());

    for (int i = 0; i < n; i ++) {
        std::cin >> contests[i].begin_ >> contests[i].end_;
    }

    std::sort(contests.begin(), contests.end(), cmp);

    for (int i = 0, j = 1; i < n && j < n; j ++) { // 双指针法yyds
        if (contests[j].begin_ >= contests[i].end_) {
            cnt ++;
            i = j;
        }
    }

    std::cout << cnt << std::endl;

    return 0;
}

bool cmp(const contest& a, const contest& b) {
    if (a.end_ == b.end_) {
        return a.begin_ < b.begin_;
    }
    return a.end_ < b.end_;
}