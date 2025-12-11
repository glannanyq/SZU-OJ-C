//   1/k = 1/x + 1/y
//   => 1/x = 1/k - 1/y
//   => 1/x = (y - k) / (k * y)
//   => x = (k * y) / (y - k)


#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    while (n--) {
        int k;
        scanf("%d", &k);
        
        // 遍历 y 从 k+1 到 2*k
        for (int y = k + 1; y <= 2 * k; y++) {
            // 计算 x = (k * y) / (y - k)
            // 需要满足：(k * y) 能被 (y - k) 整除
            if ((k * y) % (y - k) == 0) {
                int x = (k * y) / (y - k);
                
                printf("1/%d=1/%d+1/%d\n", k, x, y);
            }
        }
        printf("\n");
    }
    
    return 0;
}
