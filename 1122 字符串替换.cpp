#include <stdio.h>
#include <string.h>

int main() {
    char str[1001];
    char result[1500];
    
    while (1) {
        fgets(str, 1001, stdin);

        str[strcspn(str, "\n")] = '\0';

        if (strcmp(str, "-==-") == 0) {
            break;
        }
        
        int len = strlen(str);
        int j = 0;

        for (int i = 0; i < len; ) {
            if (i + 2 < len && str[i] == 'y' && str[i+1] == 'o' && str[i+2] == 'u') {
                result[j++] = 'w';
                result[j++] = 'e';
                i += 3;
            } else {
                result[j++] = str[i++];
            }
        }
        result[j] = '\0';
        
        printf("%s\n", result);
    }
    
    return 0;
}
