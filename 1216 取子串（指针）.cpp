#include <stdio.h>
#include <string.h>

char *substr(char *s, int startloc, int len) {
    static char result[51];
    int s_len = strlen(s);

    if (startloc > s_len) {
        return NULL;
	}

    int start_index = startloc - 1;

    int actual_len = len;
    if (start_index + len > s_len) {
        actual_len = s_len - start_index;
    }

    strncpy(result, s + start_index, actual_len);
    result[actual_len] = '\0';
    
    return result;
}

int main() {
    int t;
    char s[51];
    int startloc, len;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        scanf("%s %d %d", s, &startloc, &len);
        
        char *sub_string = substr(s, startloc, len);
        
        if (sub_string == NULL) {
            printf("NULL\n");
        } else {
            printf("%s\n", sub_string);
        }
    }
    
    return 0;
}
