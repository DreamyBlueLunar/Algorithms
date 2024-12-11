#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
    int n = 0;
    long long sum = 0;

    std::cin >> n;

    std::vector<int> input(n, 0);
    std::vector<int> stones(2 * n, 0);
    for (int i = 0; i < n; i ++) {
        std::cin >> input[i];
    }

    std::sort(input.begin(), input.end());

    for (int i = 0, j = n - 1; i < n && j >= 0; i ++, j --) {
        stones[2 * i] = input[j];
        stones[2 * i + 1] = input[i];
    }

    sum += (long long)stones[0] * stones[0];
    for (int i = 1; i < n; i ++) {
        sum += (long long)((stones[i - 1] - stones[i]) *
                (stones[i - 1] - stones[i]));
    }

    std::cout << sum << std::endl;

    return 0;
}