#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    while (n--) {
        int num;
        scanf("%d", &num);
        
        int d1 = num / 1000;
        int d2 = (num / 100) % 10;
        int d3 = (num / 10) % 10;
        int d4 = num % 10;

        d1 = (d1 + 5) % 10;
        d2 = (d2 + 5) % 10;
        d3 = (d3 + 5) % 10;
        d4 = (d4 + 5) % 10;

        int temp;
        temp = d1; d1 = d4; d4 = temp;
        temp = d2; d2 = d3; d3 = temp;

        int Ans = d1 * 1000 + d2 * 100 + d3 * 10 + d4;
        printf("%04d\n", Ans);
    }
    
    return 0;
}
