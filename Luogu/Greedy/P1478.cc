/* P1478.cc */

#include <iostream>
#include <vector>
#include <algorithm>

bool cmp(const std::pair<int, int>& a, const std::pair<int, int>& b);

int main(void) {
    std::vector<std::pair<int, int>> apples;
    int n = 0, s = 0;
    int a = 0, b = 0;
    int x = 0, y = 0;
    int cnt = 0;

    std::cin >> n >> s >> a >> b;
    int height = a + b;

    for (int i = 0; i < n; i ++) {
        std::cin >> x >> y;
        if (x <= height) {
            apples.push_back({x, y});
        }
    }

    std::sort(apples.begin(), apples.end(), cmp);
   
    for (int i = 0; i < apples.size() && s > 0; i ++) {
        if (s - apples[i].second >= 0) {
            cnt ++;
            s -= apples[i].second;
        }
    }  

    std::cout << cnt << std::endl;

    return 0;
}

bool cmp(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}