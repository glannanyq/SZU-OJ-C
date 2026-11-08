#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int matrix[2][3];

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        int *p = &matrix[0][0];

        for (int col = 2; col >= 0; col--) {
            for (int row = 0; row < 2; row++) {
                printf("%d ", *(p + row * 3 + col));
                if (row < 1) printf(" ");
            }
            printf("\n");
        }
    }
    
    return 0;
}
