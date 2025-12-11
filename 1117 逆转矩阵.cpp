#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int A, B;
        scanf("%d %d", &A, &B);
        
        int matrix[A][B];
        int transposed[B][A];

        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                transposed[j][i] = matrix[i][j];
            }
        }
        
        for (int i = 0; i < B; i++) {
            for (int j = 0; j < A; j++) {
                printf("%d", transposed[i][j]);
              	if (j < A - 1) {
                    printf(" ");
                }
            }
            printf("\n");
        }
	}
    return 0;
}
