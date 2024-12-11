/* P3817.cc */

#include <iostream>
#include <vector>

int main(void) {
    long long n = 0, x = 0, candy = 0, sum = 0;
    std::cin >> n >> x;

    std::vector<long long> candies(n, 0);

    std::cin >> candies[0];
    if (x < candies[0]) {
        sum += (candies[0] - x);
        candies[0] = x;
    }

    for (long long i = 1; i < n; i ++) {
        std::cin >> candies[i];
        if (x < candies[i] + candies[i - 1]) {
            candy = x - candies[i - 1];
            sum += (candies[i] - candy);
            candies[i] = candy;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}