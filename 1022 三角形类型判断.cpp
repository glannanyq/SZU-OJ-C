#include <stdio.h>
#include <math.h>

// 浮点数相等判断
int equal(double a, double b) {
    return fabs(a - b) < 0.001;}

// 判断三角形类型并输出
void triangle_type(double a, double b, double c) {
    // 先排序以方便比较
    if (a > b) { double t = a; a = b; b = t; }
    if (b > c) { double t = b; b = c; c = t; }
    if (a > b) { double t = a; a = b; b = t; }
    // 令 a <= b <= c

    // 1. 能否构成三角形
    if (a + b <= c || equal(a + b, c)) {
        printf("no triangle\n");
        return;}

    // 计算面积
    double s = (a + b + c) / 2.0;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    // 2. 等边
    if (equal(a, b) && equal(b, c)) {
        printf("equilateral triangle, %.1lf\n", area);
        return;}

    // 3. 等腰直角
    int is_isosceles = (equal(a, b) || equal(b, c) || equal(a, c));
    int is_right = equal(a*a + b*b, c*c);

    if (is_isosceles && is_right) {
        printf("isosceles right triangle, %.1lf\n", area);
        return;}

    // 4. 等腰
    if (is_isosceles) {
        printf("isosceles triangle, %.1lf\n", area);
        return;}

    // 5. 直角
    if (is_right) {
        printf("right triangle, %.1lf\n", area);
        return;}

    // 6. 一般
    printf("general triangle, %.1lf\n", area);
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        double a, b, c;
        scanf("%lf %lf %lf", &a, &b, &c);
        triangle_type(a, b, c);}
    return 0;
}
