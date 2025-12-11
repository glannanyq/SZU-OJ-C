#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    for (int t = 0; t < T; t++) {
        int m, n;
        scanf("%d %d", &m, &n);

        float a[100][100];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%f", &a[i][j]);
            }
        }
        
        printf("%f", a);

        float minVal = a[0][0];
        int minRow = 1, minCol = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] < minVal) {
                    minVal = a[i][j];
                    minRow = i + 1;
                    minCol = j + 1;
                }
            }
        }

        printf("%f %d %d\n", minVal, minRow, minCol);
    }
    
    return 0;
}
