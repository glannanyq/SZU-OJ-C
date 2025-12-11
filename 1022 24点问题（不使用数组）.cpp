#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int a, b, c, d, e;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
        
        int count = 0;
        
        // 遍历所有运算组合（2^4=16种）
        for (int i = 0; i < 16; i++) {
            int sum = a;

            // 仍然0加，1减
            if (i & 1) sum -= b;
            else sum += b;
            
            if (i & 2) sum -= c;  
            else sum += c;
            
            if (i & 4) sum -= d;
            else sum += d;
            
            if (i & 8) sum -= e;
            else sum += e;
            
            if (sum == 24) {
                count++;
            }
        }
        
        printf("%d\n", count);
    }
    
    return 0;
}
