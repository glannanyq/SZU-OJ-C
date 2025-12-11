#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int n;
    scanf("%d", &n);
    
    while (n--) {
        int k, b;
        char str[5001];

        scanf("%d %d", &k, &b);
        getchar();
        fgets(str, sizeof(str), stdin);
        
        int len = strlen(str);
        if (str[len - 1] == '\n') {
            str[len - 1] = '\0';
            len--;
        }

        for (int i = 0; i < len; i++) {
            char c = str[i];
            
            if (isalpha(c)) {
                int x;
                if (isupper(c)) {
                    x = c - 'A';
                } else {
                    x = c - 'a';
                }

                int y = (k * x + b) % 26;

                if (isupper(c)) {
                    str[i] = 'A' + y;
                } else {
                    str[i] = 'a' + y;
                }
            }

        }
        
        printf("%s\n", str);
    }
    
    return 0;
}
