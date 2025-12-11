#include <stdio.h>
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int result = 0;
    int base = 1;
    while (a > 0 || b > 0) {
        int A = a % 10;
        int B = b % 10;
        int sum = (A + B) % 10;
        result += sum * base;
        base *= 10;
        a /= 10;
        b /= 10;}
    printf("%d\n", result);
    return 0;
}

