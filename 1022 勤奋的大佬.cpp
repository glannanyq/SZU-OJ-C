#include <stdio.h>

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return a / gcd(a, b) * b;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long x, y, n;
        scanf("%lld %lld %lld", &x, &y, &n);
        
        if (x == 0 || y == 0) {
            printf("0\n");
            continue;
        }
        
        long long L = lcm(x, y);
        if (L == 0) {
            printf("0\n");
            continue;
        }
        
        long long bad_days = (n - 1) / L;
        long long total_stairs = bad_days * 36;
        printf("%lld\n", total_stairs);
    }
    return 0;
}
