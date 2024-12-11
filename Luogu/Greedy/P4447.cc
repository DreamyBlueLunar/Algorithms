#include <iostream>
#include <map>

#define MIN(a, b) (a < b ? a : b)

int main(void) {
    int n = 0, x = 0;
    long long res = 0x7fffffffffffffff;

    std::map<int, int> members;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        members[x] ++;
    }

    while (!members.empty()) {
        std::map<int, int>::iterator i = members.begin();
        std::map<int, int>::iterator j = ++ members.begin();
        i->second --;
        long long size = 1;

        while (j != members.end() && j->first == i->first + 1 && j->second > i->second) {
            size ++;
            j->second --;
            i ++;
            j ++;
        }

        i = members.begin();
        while (i != members.end() && i->second==0) {
            members.erase((i ++)->first);
        }

        res = MIN(res, size);
    }

    std::cout << res << std::endl;

    return 0;
}