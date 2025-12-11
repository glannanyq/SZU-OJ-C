#include <stdio.h>

int main() 
{
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int n;
        scanf("%d", &n);
        
        // 打印上半部分（包括中间一行）
        int spaces = 0;
        for (int i = n; i >= 1; i -= 2) {
            // 打印空格
            for (int j = 0; j < spaces; j++) {
                printf(" ");
            }
            // 打印星号
            for (int j = 0; j < i; j++) {
                printf("*");
            }
            printf("\n");
            spaces++;
        }
        
        // 打印下半部分（中间一行已打印过）
        spaces -= 2; // 回到倒数第二层的空格数
        for (int i = 3; i <= n; i += 2) {
            // 打印空格
            for (int j = 0; j < spaces; j++) {
                printf(" ");
            }
            // 打印星号
            for (int j = 0; j < i; j++) {
                printf("*");
            }
            printf("\n");
            spaces--;
        }
        
        // 测试数据之间用换行分割
        if (T > 0) {
            printf("\n");
        }
    }
    
    return 0;
}
