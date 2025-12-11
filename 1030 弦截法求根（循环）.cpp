#include <stdio.h>
#include <math.h>

double f(double x) {
    return x*x*x - 5*x*x + 16*x - 80;
}

double xpoint(double x1, double x2) {
    return (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
}

double root(double x1, double x2) {
    double x;
    
    do {
        x = xpoint(x1, x2);  // 弦与x轴的交点
        
        if (f(x) * f(x1) > 0) {   // f(x)与f(x1)同号，根在(x, x2)区间
            x1 = x;
        }
      	else {   // f(x)与f(x2)同号，根在(x1, x)区间
            x2 = x;
        }
    }
	while (fabs(f(x)) >= 0.0001);  // 直到 |f(x)| < 0.0001
    
    return x;
}

int main() 
{
    double x1, x2;
    
    while (scanf("%lf %lf", &x1, &x2) != EOF) {   // 检查f(x1)和f(x2)是否异号
        if (f(x1) * f(x2) > 0) {
            printf("reinput:\n");
            continue;
        }

        double result = root(x1, x2);
        printf("%lf\n", result);
    }

}
