#include <stdio.h>

// 定义点结构体
struct Point {
    double x;
    double y;
};

// 定义线段结构体
struct Segment {
    struct Point p1;
    struct Point p2;
};

// 判断两个线段是否相交（使用斜率方法）
int segmentsIntersect(struct Segment s1, struct Segment s2) {
    // 计算线段1的斜率和截距
    double k1, b1;
    double k2, b2;
    
    // 处理线段1
    if (s1.p2.x == s1.p1.x) {
        // 垂直线，斜率不存在
        k1 = 0; // 特殊标记
        b1 = s1.p1.x; // 存储x值
    } else {
        k1 = (s1.p2.y - s1.p1.y) / (s1.p2.x - s1.p1.x);
        b1 = s1.p1.y - k1 * s1.p1.x;
    }
    
    // 处理线段2
    if (s2.p2.x == s2.p1.x) {
        // 垂直线，斜率不存在
        k2 = 0;
        b2 = s2.p1.x;
    } else {
        k2 = (s2.p2.y - s2.p1.y) / (s2.p2.x - s2.p1.x);
        b2 = s2.p1.y - k2 * s2.p1.x;
    }
    
    // 情况1：两条线段都是垂直线
    if (k1 == 0 && k2 == 0) {
        // 都是垂直线
        if (b1 != b2) return 0; // 不同x值，不相交
        
        // 在同一条垂直线上，检查y范围是否重叠
        double min_y1 = s1.p1.y < s1.p2.y ? s1.p1.y : s1.p2.y;
        double max_y1 = s1.p1.y > s1.p2.y ? s1.p1.y : s1.p2.y;
        double min_y2 = s2.p1.y < s2.p2.y ? s2.p1.y : s2.p2.y;
        double max_y2 = s2.p1.y > s2.p2.y ? s2.p1.y : s2.p2.y;
        
        // 检查y范围是否重叠
        if (max_y1 < min_y2 || max_y2 < min_y1) {
            return 0;
        }
        return 1;
    }
    
    // 情况2：只有一条是垂直线
    if (k1 == 0) {
        // s1是垂直线，s2不是
        double x_intersect = b1;
        double y_intersect = k2 * x_intersect + b2;

        double min_y1 = s1.p1.y < s1.p2.y ? s1.p1.y : s1.p2.y;
        double max_y1 = s1.p1.y > s1.p2.y ? s1.p1.y : s1.p2.y;
        double min_x2 = s2.p1.x < s2.p2.x ? s2.p1.x : s2.p2.x;
        double max_x2 = s2.p1.x > s2.p2.x ? s2.p1.x : s2.p2.x;
        double min_y2 = s2.p1.y < s2.p2.y ? s2.p1.y : s2.p2.y;
        double max_y2 = s2.p1.y > s2.p2.y ? s2.p1.y : s2.p2.y;
        
        if (x_intersect >= min_x2 && x_intersect <= max_x2 &&
            y_intersect >= min_y1 && y_intersect <= max_y1 &&
            y_intersect >= min_y2 && y_intersect <= max_y2) {
            return 1;
        }
        return 0;
    }
    
    if (k2 == 0) {

        double x_intersect = b2;
        double y_intersect = k1 * x_intersect + b1;
        
        double min_x1 = s1.p1.x < s1.p2.x ? s1.p1.x : s1.p2.x;
        double max_x1 = s1.p1.x > s1.p2.x ? s1.p1.x : s1.p2.x;
        double min_y1 = s1.p1.y < s1.p2.y ? s1.p1.y : s1.p2.y;
        double max_y1 = s1.p1.y > s1.p2.y ? s1.p1.y : s1.p2.y;
        double min_y2 = s2.p1.y < s2.p2.y ? s2.p1.y : s2.p2.y;
        double max_y2 = s2.p1.y > s2.p2.y ? s2.p1.y : s2.p2.y;
        
        if (x_intersect >= min_x1 && x_intersect <= max_x1 &&
            y_intersect >= min_y1 && y_intersect <= max_y1 &&
            y_intersect >= min_y2 && y_intersect <= max_y2) {
            return 1;
        }
        return 0;
    }

    if (k1 == k2) {
        if (b1 != b2) return 0;
        
        double min_x1 = s1.p1.x < s1.p2.x ? s1.p1.x : s1.p2.x;
        double max_x1 = s1.p1.x > s1.p2.x ? s1.p1.x : s1.p2.x;
        double min_x2 = s2.p1.x < s2.p2.x ? s2.p1.x : s2.p2.x;
        double max_x2 = s2.p1.x > s2.p2.x ? s2.p1.x : s2.p2.x;
        
        if (max_x1 < min_x2 || max_x2 < min_x1) {
            return 0;
        }
        return 1;
    }

    double x_intersect = (b2 - b1) / (k1 - k2);
    double y_intersect = k1 * x_intersect + b1;
    
    // 点是否在线段上 
    double min_x1 = s1.p1.x < s1.p2.x ? s1.p1.x : s1.p2.x;
    double max_x1 = s1.p1.x > s1.p2.x ? s1.p1.x : s1.p2.x;
    double min_y1 = s1.p1.y < s1.p2.y ? s1.p1.y : s1.p2.y;
    double max_y1 = s1.p1.y > s1.p2.y ? s1.p1.y : s1.p2.y;
    double min_x2 = s2.p1.x < s2.p2.x ? s2.p1.x : s2.p2.x;
    double max_x2 = s2.p1.x > s2.p2.x ? s2.p1.x : s2.p2.x;
    double min_y2 = s2.p1.y < s2.p2.y ? s2.p1.y : s2.p2.y;
    double max_y2 = s2.p1.y > s2.p2.y ? s2.p1.y : s2.p2.y;
    
    if (x_intersect >= min_x1 && x_intersect <= max_x1 &&
        y_intersect >= min_y1 && y_intersect <= max_y1 &&
        x_intersect >= min_x2 && x_intersect <= max_x2 &&
        y_intersect >= min_y2 && y_intersect <= max_y2) {
        return 1;
    }
    
    return 0;
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        struct Segment seg1, seg2;
        
        scanf("%lf %lf %lf %lf", 
              &seg1.p1.x, &seg1.p1.y, 
              &seg1.p2.x, &seg1.p2.y);
        scanf("%lf %lf %lf %lf", 
              &seg2.p1.x, &seg2.p1.y, 
              &seg2.p2.x, &seg2.p2.y);
        
        if (segmentsIntersect(seg1, seg2)) {
            printf("intersect\n");
        } else {
            printf("disjoint\n");
        }
    }
    
    return 0;
}
