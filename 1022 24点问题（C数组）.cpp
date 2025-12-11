#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int a[5];
        for (int i = 0; i < 5; i++) {
            scanf("%d", &a[i]);
        }
        
        int count = 0;
        for (int mask = 0; mask < 16; mask++) {
            int sum = a[0];
            for (int i = 0; i < 4; i++) {
                if (mask & (1 << i)) {
                    sum -= a[i + 1];
                } else {
                    sum += a[i + 1];
                }
            }
            if (sum == 24) {
                count++;
            }
        }
        
        printf("%d\n", count);
    }
    
    return 0;
}
