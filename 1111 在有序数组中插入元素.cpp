#include <stdio.h>

int check_order(int arr[], int size) {
    if (arr[0] < arr[1]) {
        return 1;  // ÉýÐò
    } else {
        return 0;  // ½µÐò
    }
}

int main() {
    int arr[10];

    for (int i = 0; i < 9; i++) {
        scanf("%d", &arr[i]);
    }

    int num;
    scanf("%d", &num);

    int is_asc = check_order(arr, 9);

    int pos = 9; 
    if (is_asc) {
        for (int i = 0; i < 9; i++) {
            if (num < arr[i]) {
                pos = i;
                break;
            }
        }
    } else {
        for (int i = 0; i < 9; i++) {
            if (num > arr[i]) {
                pos = i;
                break;
            }
        }
    }

    for (int i = 9; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = num;

    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}
    
