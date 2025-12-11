#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    
    double delta = b * b - 4 * a * c;
    
    if (delta > 0) {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        printf("x1=%.3f x2=%.3f\n", x1, x2);
    } 
  	else if (delta == 0) {
        double x = -b / (2 * a);
        printf("x1=%.3f x2=%.3f\n", x, x);
    } 
  	else {
        double real = -b / (2 * a);
        double imag = sqrt(-delta) / (2 * a);
        printf("x1=%.3f+%.3fi x2=%.3f-%.3fi\n", real, imag, real, imag);
    }
    
    return 0;
}
