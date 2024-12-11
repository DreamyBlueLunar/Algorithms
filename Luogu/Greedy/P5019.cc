#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
    int n = 0, sum = 0;
    std::cin >> n;
   
    std::vector<int> road(n, 0);
    for (int i = 0; i < n; i ++) {
        std::cin >> road[i];
    }

    sum += road[0];
    for (int i = 1; i < n; i ++) {
        if (road[i] > road[i - 1]) {
            sum += (road[i] - road[i - 1]);
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
