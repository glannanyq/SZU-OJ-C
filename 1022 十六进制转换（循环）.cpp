#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    getchar();
    
    while (T--) {
        char ch;
        long long result = 0;
        int sign = 1;

        ch = getchar();
        if (ch == '-') {
            sign = -1;
        } else {
            int v;
            if (ch >= '0' && ch <= '9') {
                v = ch - '0';
            } else if (ch >= 'A' && ch <= 'F') {
                v = ch - 'A' + 10;
            } else if (ch >= 'a' && ch <= 'f') {
                v = ch - 'a' + 10;
            }
            result = result * 16 + v;
        }

        while ((ch = getchar()) != '\n' && ch != EOF) {
            int v;
            if (ch >= '0' && ch <= '9') {
                v = ch - '0';
            } else if (ch >= 'A' && ch <= 'F') {
                v = ch - 'A' + 10;
            } else if (ch >= 'a' && ch <= 'f') {
                v = ch - 'a' + 10;
            } else {
                continue;
            }
            result = result * 16 + v;
        }
        
        printf("%lld\n", result * sign);
    }
    
    return 0;
}
