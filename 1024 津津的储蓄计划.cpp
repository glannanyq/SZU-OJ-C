#include<stdio.h>
int main()
{
    int n; // 每月预算
    int m = 0; // 手头现金，初始为0
    int deposit = 0; // 存款总额
    int i;
    for (i = 1; i <= 12; i++) {
        scanf("%d", &n);
        m += 300; // 月初妈妈给300
        if (m < n) {
            printf("-%d\n", i);
            return 0;
        }
        m -= n; // 减去本月预算
        if (m >= 100) {
            int save = (m / 100) * 100;
            deposit += save;
            m -= save;
        }
    }
    int total = m + deposit * 1.2;
    printf("%d\n", total);
    return 0;
}
