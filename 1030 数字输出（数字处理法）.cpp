#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
  
    int temp = n;
    int digits = 0;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }
    printf("%d\n", digits);

    temp = n;
    int divisor = 1;

    for (int i = 1; i < digits; i++) {
        divisor *= 10;
    }

    for (int i = 0; i < digits; i++) {
        int digit = temp / divisor;
        printf("%d", digit);
        
        if (i < digits - 1) {
            printf(" ");
        }
        
        temp %= divisor;
        divisor /= 10;
    }
    printf("\n");

    temp = n;
    while (temp > 0) {
        printf("%d", temp % 10);
        temp /= 10;
    }
    printf("\n");
    
    return 0;
}
