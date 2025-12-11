#include <stdio.h>
#include <string.h>

void Reverse(char x[], const char y[], int len) {
    for (int i = 0; i < len; i++) {
        x[i] = y[len - 1 - i];
    }
    x[len] = '\0';
}

int main() {
	int n;
	scanf("%d", &n);
	
	while (n--) {
		char str[1000];
		scanf("%s", &str);
		
		int len = strlen(str);
		
		while (len % 2 == 0) {
            int half = len / 2;
            char l[505], r[505], rev_l[505], rev_r[505];
            
            strncpy(l, str, half);
            l[half] = '\0';
            strncpy(r, str + half, half);
            r[half] = '\0';
            
            Reverse(rev_l, l, half);
            Reverse(rev_r, r, half);

            if (strcmp(rev_l, r) == 0) {
                len = half;
                str[half] = '\0';
            } else {
                break;
            }
        }
        
        printf("%d\n", len);
    }
    
    return 0;
}

