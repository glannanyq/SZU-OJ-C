#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        char str1[100], str2[100], a[10];
        
        scanf("%s", str1);
        scanf("%s", str2);

        a[0] = str1[0];
        a[1] = str1[1];
        a[2] = str1[2];

        int len2 = strlen(str2);
      
        a[3] = str2[len2 - 3];
        a[4] = str2[len2 - 2];
        a[5] = str2[len2 - 1];
        
        a[6] = '\0';
      
        printf("%s\n", a);
    }
    
    return 0;
}
