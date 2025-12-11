#include <stdio.h>

int main() {
    int x1, y1; 
    int x2, y2; 
    int x, y;
    
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x, &y);

    if (x >= x1 && x <= x2 && y >= y2 && y <= y1) {
        printf("IN\n");
    } else {
        printf("OUT\n");
    }
    
    return 0;
}
