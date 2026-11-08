#include <stdio.h>

int main () {
    float tem[1000], sum = 0;
    int count = 0;
    float *p = tem;
    
    while (1) {
        scanf("%f", p);
        if (*p == 0) break;
        sum += *p;
        count++;
        p++;
    }
    
    printf("%d %g\n", count, sum / count);
    return 0;
}
