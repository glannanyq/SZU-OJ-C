#include <stdio.h>
#include <string.h>

int main() {
    char origin[1000];
    scanf("%s", origin);
    int row;
    scanf("%d", &row);
    
    int len = strlen(origin);
    
    // 特殊情况处理
    if (row == 1 || len <= row) {
        printf("%s", origin);
        return 0;
    }
    
    int lens[1000] = { 0 };
    char Z[1000][500] = { 0 };
    
    int k = -1, turn = 1;
    for (int i = 0; i < len; i++) {
        k = k + turn;
        Z[k][lens[k]++] = origin[i];
        if (k == 0) turn = 1;
        if (k == row - 1) turn = -1;
    }
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < lens[i]; j++) {
            printf("%c", Z[i][j]);
        }
    }
    
    return 0;
}
