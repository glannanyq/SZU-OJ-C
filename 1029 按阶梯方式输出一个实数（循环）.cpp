#include <stdio.h>

int main() {
    int n;
    float num;
    
    scanf("%d %f", &n, &num);
    
    for (int i = 1; i <= n; i++) {
        printf("%.2f", num);
        for (int j = 2; j <= i; j++) {
            printf("%6.2f", num);
        }
        printf("\n");
    }

}
