#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

const long long LEN = 110;

struct bunch {
    double m, v;
    double v_div_m;
};
std::vector<bunch> coins; 

bool cmp(const bunch& a, const bunch& b);

int main(void) {
    int n, t;
    double m, v;
    
    coins.clear();
    std::cin >> n >> t;

    for (int i = 0; i < n; i ++) {
        std::cin >> m >> v;
        coins.push_back({m, v, v / m});
    }

    std::sort(coins.begin(), coins.end(), cmp);

    double sum = 0.0;
    for (int i = 0; i < n && t > 0; i ++) { // 显然这个东西多多少少是带点风险的
        double weight = (t - coins[i].m >= 0) ? coins[i].m : t;
        sum += coins[i].v_div_m * weight;
        t -= coins[i].m;
    }

    std::cout << std::fixed << std::setprecision(2) << sum << std::endl;

    return 0;
}

bool cmp(const bunch& a, const bunch& b) {
    return a.v_div_m > b.v_div_m;
}