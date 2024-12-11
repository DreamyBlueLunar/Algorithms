#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
    int w = 0, n = 0;
    std::cin >> w >> n;

    std::vector<int> souvenirs(n, 0);
    for (int i = 0; i < n; i ++) {
        std::cin >> souvenirs[i];
    }

    std::sort(souvenirs.begin(), souvenirs.end());

    int i = 0, j = n - 1;
    int groups = 0;
    while (i < j) {
        if (souvenirs[i] + souvenirs[j] <= w) {
            groups ++;
            i ++;
            j --;
        } else {
            j --;
        }
    }

    int res = n - groups;

    std::cout << res << std::endl;

    return 0;
}
