#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        char hex1[10], hex2[10];
        char *endptr1, *endptr2;
        
        scanf("%s", hex1);
        scanf("%s", hex2);

        long num1 = strtol(hex1, &endptr1, 16);
        long num2 = strtol(hex2, &endptr2, 16);
        
        if (*endptr1 != '\0' || *endptr2 != '\0') {
            printf("-1\n");
        } else {
            long sum = num1 + num2;
            printf("%ld\n", sum);
        }
    }
    
    return 0;
}
