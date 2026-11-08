#include <stdio.h>

struct Point {
    int x, y;
};

struct Segment {
    struct Point p1, p2;
};

int crossP(struct Point p1, struct Point p2, struct Point p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

int on(struct Point p, struct Point q, struct Point r) {
    if (q.x <= (p.x > r.x ? p.x : r.x)
	&& q.x >= (p.x < r.x ? p.x : r.x)
	&&q.y <= (p.y > r.y ? p.y : r.y)
	&& q.y >= (p.y < r.y ? p.y : r.y)) {
        return 1;
    }
    return 0;
}

int Intersect(struct Segment s1, struct Segment s2) {
    struct Point p1 = s1.p1, p2 = s1.p2;
    struct Point p3 = s2.p1, p4 = s2.p2;

    int d1 = crossP(p1, p2, p3);
    int d2 = crossP(p1, p2, p4);
    int d3 = crossP(p3, p4, p1);
    int d4 = crossP(p3, p4, p2);

    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
        ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) {
        return 1;
    }

    if (d1 == 0 && on(p1, p3, p2)) return 1;
    if (d2 == 0 && on(p1, p4, p2)) return 1;
    if (d3 == 0 && on(p3, p1, p4)) return 1;
    if (d4 == 0 && on(p3, p2, p4)) return 1;
    
    return 0;
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        struct Segment seg1, seg2;

        scanf("%d %d %d %d", 
              &seg1.p1.x, &seg1.p1.y, 
              &seg1.p2.x, &seg1.p2.y);

        scanf("%d %d %d %d", 
              &seg2.p1.x, &seg2.p1.y, 
              &seg2.p2.x, &seg2.p2.y);

        if (Intersect(seg1, seg2)) {
            printf("intersect\n");
        }
		else {
            printf("disjoint\n");
        }
    }
    
    return 0;
}
