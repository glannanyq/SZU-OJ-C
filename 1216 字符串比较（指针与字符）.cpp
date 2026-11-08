#include <stdio.h>
#include <string.h> 

int compare(char *S, char *T) {
    char *s = S;
    char *t = T;
    int win = 0;

    while (*S && *T) {
        if (*S > *T) win++;
        else if (*S < *T) win--;
        S++;
        T++;
    }
    
    if (win > 0) return 1;
    if (win < 0) return -1;

    int len1 = 0, len2 = 0;
    while (*s) { len1++; s++; }
    while (*t) { len2++; t++; }
    
    if (len1 > len2) return 1;
    if (len1 < len2) return -1;
    return 0;
}

int main() {
    int t;
    scanf("%d", &t);
    getchar();
    
    while (t--) {
        char str1[101], str2[101];
      
        fgets(str1, sizeof(str1), stdin);
        fgets(str2, sizeof(str2), stdin);
        
        str1[strcspn(str1, "\n")] = '\0';
        str2[strcspn(str2, "\n")] = '\0';
      
        printf("%d\n", compare(str1, str2));
    }
    
    return 0;
}
