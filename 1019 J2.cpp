#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        long long profit;
        scanf("%lld", &profit);
        
        long long bonus = 0;
        
        if (profit > 100000) {
            bonus += (profit - 100000) * 1 / 100;
            profit = 100000;
        }
        if (profit > 60000) {
            bonus += (profit - 60000) * 15 / 1000;  // 1.5% = 15/1000
            profit = 60000;
        }
        if (profit > 40000) {
            bonus += (profit - 40000) * 3 / 100;
            profit = 40000;
        }
        if (profit > 20000) {
            bonus += (profit - 20000) * 5 / 100;
            profit = 20000;
        }
        if (profit > 10000) {
            bonus += (profit - 10000) * 75 / 1000;  // 7.5% = 75/1000
            profit = 10000;
        }
        bonus += profit * 10 / 100;
        
        printf("%lld\n", bonus);
    }
    
    return 0;
}
