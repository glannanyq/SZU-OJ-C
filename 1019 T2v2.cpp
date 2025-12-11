#include <stdio.h>

// 判断素数
int isPrime(int num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// 计算阶乘
long long factorial(int n) {
    long long res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

// 打印菜单
void printMenu() {
    printf("1 计算n!\n");
    printf("2 输出素数\n");
    printf("3 判定闰年\n");
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int op;
        scanf("%d", &op);
        printMenu();  // 每组测试先输出菜单
        
        switch (op) {
            case 1: {
                int n;
                scanf("%d", &n);
                printf("%d! = %lld\n", n, factorial(n));
                break;
            }
            case 2: {
                int a, b;
                scanf("%d %d", &a, &b);
                int first = 1;
                for (int i = a; i <= b; i++) {
                    if (isPrime(i)) {
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
                if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                    printf("%d是闰年\n", year);
                } else {
                    printf("%d非闰年\n", year);
                }
                break;
            }
            default:
                printf("INPUT ERROR!\n");
                while (getchar() != '\n'); // 清理输入缓冲区
                break;
        }
    }
    return 0;
}
