#include <stdio.h>
#include <math.h>

int is_prime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        
        int found = 0;
        int sum = 0;
        int first = 1;
      
        for (int i = n; i <= m; i++) {
            if (is_prime(i)) {
                    printf("%d ", i);
                
                found = 1;
                sum += i;
            }
        }

        if (found) {
            printf("\n%d\n", sum);
        } else {
            printf("NO\n");
        }
    }
    
    return 0;
}
