/* P1106.cc */

#include <iostream>
#include <string>

// 数据水得逆天
int main() {
    std::string n;
    int s, i;
    std::cin >> n >> s;
    while (s) { // 删除下坡数
        for (i = 0; n[i] <= n[i + 1];) {
            i++;
        }
        n.erase(i, 1);
        s--;
    }
    while (n[0] == '0' && n.size() > 1) {
        n.erase(0, 1);
    }
    std::cout << n;
    return 0;
}