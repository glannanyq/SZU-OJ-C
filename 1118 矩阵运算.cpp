#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        scanf("%d", &n);
        
        int A[n][n], B[n][n], C[n][n], D[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &A[i][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &B[i][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                C[i][j] = A[i][j] + B[i][j];
            }
        }

		for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                D[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    D[i][j] += A[i][k] * B[k][j];  // A的第i行 × B的第j列
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d", C[i][j]);
                if (j < n - 1) printf(" ");
            }
            printf("\n");
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d", D[i][j]);
                if (j < n - 1) printf(" ");
            }
            printf("\n");
        }
    }
    
    return 0;
}
