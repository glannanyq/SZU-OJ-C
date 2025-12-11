#include <stdio.h>
#include <math.h>

int main() {
    double ma, mb, mc;
    
    while (scanf("%lf %lf %lf", &ma, &mb, &mc) != EOF) {
        // 检查三条中线是否能构成三角形
        if (ma + mb > mc && ma + mc > mb && mb + mc > ma) {
            double sm = (ma + mb + mc) / 2.0;
            double Sm = sqrt(sm * (sm - ma) * (sm - mb) * (sm - mc));
            double area = (4.0 / 3.0) * Sm;
            
            if (area > 0) {
                printf("%.3f\n", area);
            } else {
                printf("-1\n");
            }
        } else {
            printf("-1\n");
        }
    }
    
    return 0;
}
