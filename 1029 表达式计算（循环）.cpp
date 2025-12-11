#include <stdio.h>
#include <math.h>

int main() 
{
    int t;
    double x, y;
    
    scanf("%d", &t);
    
    while (t--) {
        scanf("%lf", &x);
        
        if (x < 0) {
            y = -x;
        }
      	else if (x < 1) {
            y = sin(2 * x);
        }
      	else if (x < 5) {
            y = sqrt(x * x * x + x);
        }
      	else {
            y = 2 * x + 10;
        }
        
        printf("%.2lf\n", y);
    }

}
