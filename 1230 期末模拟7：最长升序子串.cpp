#include <stdio.h>
#include <string.h>

int main() {
    char str[100001];
    scanf("%s", str);
    int n = strlen(str);
    
    int m[100001];
    int max = 0;

    for (int i = 0; i < n; i++) {
        m[i] = 1;
        for (int j = 0; j < i; j++) {
            if (str[i] >= str[j] && m[j] + 1 > m[i]) {
                m[i] = m[j] + 1;
            }
        }

        if (m[i] > max) {
            max = m[i];
        }
    }
    
    printf("%d\n", max);
    
}
