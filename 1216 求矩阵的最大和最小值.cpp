#include <stdio.h>

void find_max_min(int *matrix, int rows, int cols, int *max, int *min) {
    *max = *matrix;
    *min = *matrix;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value = *(matrix + i * cols + j);
            
            if (value > *max) *max = value;
            if (value < *min) *min = value;
        }
    }
}

int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    
    int matrix[rows][cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int max_val, min_val;

    find_max_min(&matrix[0][0], rows, cols, &max_val, &min_val);
    
    printf("%d\n%d\n", max_val, min_val);
    
    return 0;
}
