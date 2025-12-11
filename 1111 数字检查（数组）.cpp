#include <stdio.h>

int main() {
    int nums[50];
    int count = 0;
    int n;

    while (1) {
        scanf("%d", &n);
        if (n == -1) break;
        nums[count++] = n;
    }

    int even_nums[50];
    int even_count = 0;
    
    for (int i = 0; i < count; i++) {
        int num = nums[i];
        int all_even = 1;

        int temp = num;
        while (temp > 0) {
            int digit = temp % 10;
            if (digit % 2 != 0) {
                all_even = 0;
                break;
            }
            temp /= 10;
        }
        
        if (all_even) {
            even_nums[even_count++] = num;
        }
    }

    printf("%d\n", even_count);

    for (int i = 0; i < even_count - 1; i++) {
        for (int j = 0; j < even_count - i - 1; j++) {
            if (even_nums[j] > even_nums[j + 1]) {
                int temp = even_nums[j];
                even_nums[j] = even_nums[j + 1];
                even_nums[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < even_count; i++) {
        printf("%04d\n", even_nums[i]);
    }
    
    return 0;
}
