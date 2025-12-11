#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);
        
        int matrix[N][M];
        int rotated[M][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        for (int j = M - 1; j >= 0; j--) {
            for (int i = 0; i < N; i++) {

                rotated[M-1-j][i] = matrix[i][j];
            }
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d", rotated[i][j]);
                if (j < N - 1) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    
    return 0;
}
