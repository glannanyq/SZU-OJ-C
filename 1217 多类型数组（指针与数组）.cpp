#include <stdio.h>

void process_I(int n) {
    int arr[100];
    int *p = arr;
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", p + i);
    }
    
    for (int i = 0; i < n; i++) {
        sum += *(p + i);
    }
    
    printf("%g\n", (double)sum / n);
}

void process_C(int n) {
    char arr[100];
    char *p = arr;
    char max;
    
    for (int i = 0; i < n; i++) {
        scanf(" %c", p + i);
        if (i == 0 || *(p + i) > max) {
            max = *(p + i);
        }
    }
    
    printf("%c\n", max);
}

void process_F(int n) {
    float arr[100];
    float *p = arr;
    float min;
    
    for (int i = 0; i < n; i++) {
        scanf("%f", p + i);
        if (i == 0 || *(p + i) < min) {
            min = *(p + i);
        }
    }
    
    printf("%g\n", min);
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        char type;
        int n;
        scanf(" %c %d", &type, &n);
        
        if (type == 'I') {
        	process_I(n);
        }
      	else if (type == 'C') {
            process_C(n);
        }
        else if (type == 'F') {
            process_F(n);
        }
      	else {
        	continue;
        }
    }
    
    return 0;
}
