#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);

    if (a + b <= c || a + c <= b || b + c <= a) {
        printf("非三角形\n");
        return 0;}
    int equ = 0, iso = 0, riang = 0;
    
    // 等边
    if (fabs(a - b) < 0.001 && fabs(b - c) < 0.001) {
        equ = 1;}
    
    // 等腰
    if (fabs(a - b) < 0.001 || fabs(a - c) < 0.001 || fabs(b - c) < 0.001) {
        iso = 1;}
    
    // 直角
    if (fabs(a*a + b*b - c*c) < 0.001 || 
        fabs(a*a + c*c - b*b) < 0.001 || 
        fabs(b*b + c*c - a*a) < 0.001) {
        riang = 1;}

    if (equ) {
        printf("等边三角形\n");
    } else if (iso && riang) {
        printf("等腰直角三角形\n");
    } else if (iso) {
        printf("等腰三角形\n");
    } else {
        printf("普通三角形\n");
    }
    
    return 0;
}
