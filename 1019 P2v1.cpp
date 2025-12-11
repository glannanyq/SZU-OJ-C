#include <stdio.h>

int main() {
    int x1, y1, x2, y2, x, y;

    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x, &y);
    
    // 矩形左上角坐标不一定是x1,y1最小，需要比较确定范围
    int left = (x1 < x2) ? x1 : x2;
    int right = (x1 > x2) ? x1 : x2;
    int top = (y1 > y2) ? y1 : y2;
    int bottom = (y1 < y2) ? y1 : y2;
    
    if (x >= left && x <= right && y >= bottom && y <= top) {
        printf("IN\n");
    } else {
        printf("OUT\n");
    }
    
    return 0;
}
