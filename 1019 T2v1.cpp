#include <stdio.h>
#include <math.h>

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        printf("1 计算n!\n2 输出素数\n3 判定闰年\n");
        
        int option;
        scanf("%d", &option);
        
        switch (option) {
            case 1: {
                int n, fact = 1;
                scanf("%d", &n);
                for (int i = 2; i <= n; i++) fact *= i;
                printf("%d\n", fact);
              	printf("\n");
                break;
            }
            case 2: {
                int m, n, first = 1;
                scanf("%d %d", &m, &n);
                for (int i = m; i <= n; i++) {
                    if (i < 2) continue;
                    int prime = 1;
                    for (int j = 2; j <= sqrt(i); j++) {
                        if (i % j == 0) { prime = 0; break; }
                    }
                    if (prime) {
                      	if (!first) printf(" ");
                        printf("%d", i);
                        first = 0;
                    }
                }
                printf("\n");
                break;
            }
            case 3: {
                int year;
                scanf("%d", &year);
                printf((year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 
                       "%d是闰年\n" : "%d非闰年\n", year);
              	printf("\n");
                break;
            }
            default:
                printf("INPUT ERROR!\n");
            	printf("\n");
                break;
        }
    }
    
    return 0;
}
