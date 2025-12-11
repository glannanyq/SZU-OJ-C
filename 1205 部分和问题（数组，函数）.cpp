#include <stdio.h>
#include <stdbool.h>

#define MAX_N 20

int n, k;
int arr[MAX_N];
bool selected[MAX_N];
bool found = false;

void backtrack(int index, int current_sum) {
    if (found) return;

    if (current_sum == k) {
        found = true;
        return;
    }

    if (index >= n) {
        return;
    }

    selected[index] = true;
    backtrack(index + 1, current_sum + arr[index]);

    if (found) return;

    selected[index] = false;
    backtrack(index + 1, current_sum);
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d %d", &n, &k);
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            selected[i] = false;
        }
        
        found = false;
        backtrack(0, 0);
        
        if (found) {
            printf("YES\n");
          
            bool first = true;
            for (int i = 0; i < n; i++) {
                if (selected[i]) {
                    if (!first) {
                        printf(" ");
                    }
                    printf("%d", arr[i]);
                    first = false;
                }
            }
            printf("\n");
        } else {
            printf("NO\n");
        }
    }
    
    return 0;
}
