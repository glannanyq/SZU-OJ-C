#include <stdio.h>
#include <math.h>

int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int is_sym(int n) {
    int original = n;
    int reversed = 0;
    
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    
    return original == reversed;
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int n;
        scanf("%d", &n);

        if (n < 100000 && is_prime(n) && is_sym(n)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    
    return 0;
}
