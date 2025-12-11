#include <stdio.h>
#include <string.h>

int main() {
    char num[6];
    scanf("%s", num);
    
    int len = strlen(num);

    printf("%d\n", len);

    for (int i = 0; i < len; i++) {
        printf("%c", num[i]);
        if (i < len - 1) {
            printf(" ");
        }
    }
    printf("\n");

    for (int i = len - 1; i >= 0; i--) {
        printf("%c", num[i]);
    }
    printf("\n");
    
    return 0;
}
