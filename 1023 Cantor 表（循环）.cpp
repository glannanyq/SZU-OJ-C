#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int k = 0;
    while (k * (k + 1) / 2 < N) {
        k++;}

    int pos = N - (k - 1) * k / 2;

    if (k % 2 == 1) {
        printf("%d/%d\n", k - pos + 1, pos);
    } else {
        printf("%d/%d\n", pos, k - pos + 1);
    }
    
    return 0;
}
