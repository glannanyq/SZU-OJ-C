#include <stdio.h>
#include <string.h>

int main() {
    int m, n, t;
  
    while (scanf("%d %d %d", &m, &n, &t) == 3) {
        int dp[10005];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        
        for (int i = 1; i <= t; i++) {
            if (i >= m && dp[i - m] != -1) {
                if (dp[i - m] + 1 > dp[i]) {
                    dp[i] = dp[i - m] + 1;
                }
            }
            if (i >= n && dp[i - n] != -1) {
                if (dp[i - n] + 1 > dp[i]) {
                    dp[i] = dp[i - n] + 1;
                }
            }
        }
        
        int bestHam = 0, bestTime = 0;
        for (int i = 0; i <= t; i++) {
            if (dp[i] != -1) {
                if (dp[i] > bestHam || (dp[i] == bestHam && i > bestTime)) {
                    bestHam = dp[i];
                    bestTime = i;
                }
            }
        }
        
        printf("%d %d\n", bestHam, t - bestTime);
    }
    return 0;
}
