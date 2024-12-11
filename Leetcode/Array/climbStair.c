// dfs -> mem_dfs -> dp -> 优化
// dp[i] -> 走到第i级台阶的方案数
// dp[i] = dp[i - 1] + dp[i - 2];
// 确定递推关系式（状态转移方程）
// 初始化

#include <stdio.h>

#define DFS     1
#define MEMDFS  0
#define DP      0

#define N (1000010)
int dp[N];
int f[N];

typedef int(*climbStairs)(int);

int dfs(int n) {
    if (1 == n) {
        return 1;
    }
    if (2 == n) {
        return 2;
    }

    return dfs(n - 1) + dfs(n - 2);
}

int mem_dfs(int n) {
    if (1 == n) {
        return 1;
    }
    if (2 == n) {
        return 2;
    }
    if (0 != f[n]) {
        return f[n];
    }
    
    f[n] = dfs(n - 1) + dfs(n - 2);
    return f[n];
}

int dynamic_programming(int n) {
    dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= n; i ++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main(void) {
    climbStairs solution;
#if DFS
        solution = dfs;
#elif MEMDFS
        solution = mem_dfs;
#elif DP
        solution = dynamic_programming;
#endif

    int n = 0;
    scanf("%d", &n);
    printf("%d\n", solution(n));

    return 0;
}