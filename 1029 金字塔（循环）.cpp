#include <stdio.h>

int main() 
{
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        char ch;
        scanf("%d %c", &n, &ch);

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n - i; j++) {
                printf(" ");
            }
            for (int j = 0; j < 2 * i - 1; j++) {
                printf("%c", ch);
            }
            printf("\n");
        }

        if (t > 1) {
            printf("\n");
        }
    }
    
    return 0;
}
