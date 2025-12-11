#include <stdio.h>

int main() 
{
    int T;
    scanf("%d", &T);
    
    int tot, eff;
    double y;

    scanf("%d %d", &tot, &eff);
    y = (double)eff / tot;

    for (int i = 1; i < T; i++) {
        scanf("%d %d", &tot, &eff);
        double x = (double)eff / tot;
        
        if (x - y > 0.05) {
            printf("better\n");
        } else if (y - x > 0.05) {
            printf("worse\n");
        } else {
            printf("same\n");
        }
    }
    
    return 0;
}
