#include <stdio.h>

int n, r;
int combi[15];

void genCombi(int start, int depth) {
    if (depth == r) {
        for (int i = 0; i < r; i++) {
            printf("%d", combi[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i >= 1; i--) {
        combi[depth] = i;
        genCombi(i - 1, depth + 1);
    }
}

int main() {
    scanf("%d %d", &n, &r);
    genCombi(n, 0);
    return 0;
}
