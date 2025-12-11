#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int x1, y1, x2, y2; // 矩形1的左上角(x1,y1)和右下角(x2,y2)
        int x3, y3, x4, y4; // 矩形2的左上角(x3,y3)和右下角(x4,y4)

        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d %d %d %d", &x3, &y3, &x4, &y4);

        if (x2 >= x3 && x1 <= x4 && y2 >= y3 && y1 <= y4) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}
