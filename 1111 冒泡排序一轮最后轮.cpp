#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
  	int arr[t];
    
    while (t--) {
        int N;
        scanf("%d", &N);

        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        int swapped;
        for (int i = 0; i < N - 1; i++) {
            swapped = 0;
            for (int j = 0; j < N - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = 1;
                }
            }
            if (!swapped) {
                break;
            }
        }

        for (int i = 0; i < N; i++) {
            printf("%d", arr[i]);
            if (i < N - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}
