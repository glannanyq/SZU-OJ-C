#include <stdio.h>

int gcd(int a, int b) 
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int x, y;
        long long n;
        scanf("%d %d %lld", &x, &y, &n);
        int a = x + 1;
        int b = y + 1;
        int g = gcd(a, b);
        long long L = (long long)a * b / g;
        long long cou = n / L;
        long long res = cou * 36;
        printf("%lld\n", res);
    }

}
