#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int n;
        scanf("%d", &n);
        
        int arr[20];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        for (int i = 0; i < n - 1; i++) {
            int swapped = 0;
          
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = 1;
                }
            }

            for (int k = 0; k < n; k++) {
                printf("%d", arr[k]);
                if (k < n - 1) printf(" ");
            }
            printf("\n");

            if (!swapped) break;
        }
    }
    
    return 0;
}
