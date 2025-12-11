#include <stdio.h>
#include <math.h>

void printSubsets(char set[], int n) {
    int total = pow(2, n);
    
    printf("%d\n", total);

    for (int i = 0; i < total; i++) {
        printf("{");
      
        for (int j = 0; j < n; j++) {
          
            if (j < n - 1) {
                printf("%c,", set[j]);
            }
            else {
              	printf("%c", set[j]);
            }
        }
        printf("}\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        scanf("%d", &n);
        
        char set[20];
        for (int i = 0; i < n; i++) {
            scanf(" %c", &set[i]);
        }
        
        printSubsets(set, n);
        
        if (t > 0) {
            printf("\n");
        }
    }
    
    return 0;
}
