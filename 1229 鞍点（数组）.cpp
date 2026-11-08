#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int A, B;
        scanf("%d %d", &A, &B);
        
        int matrix[A][B];

        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }
        
        int saddle_row = -1, saddle_col = -1;
        int found = 0;

        for (int i = 0; i < A && !found; i++) {
          
            int max_in_row = matrix[i][0];
            int max_col = 0;
            for (int j = 1; j < B; j++) {
                if (matrix[i][j] > max_in_row) {
                    max_in_row = matrix[i][j];
                    max_col = j;
                }
            }

            int is_min_in_col = 1;
            for (int k = 0; k < A; k++) {
                if (matrix[k][max_col] < max_in_row) {
                    is_min_in_col = 0;
                    break;
                }
            }

            if (is_min_in_col) {
                saddle_row = i;
                saddle_col = max_col;
                found = 1;
            }
        }

        if (found) {
            printf("%d %d %d\n", matrix[saddle_row][saddle_col], saddle_row, saddle_col);
        } else {
            printf("null\n");
        }
    }
    
    return 0;
}
