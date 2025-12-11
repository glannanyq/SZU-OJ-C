#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    
    while (t--) {
        char s1[20], s2[20];
        scanf("%s %s", s1, s2);

        int i = 0;
        while (s2[i] != '\0') {
            s1[i] = s2[i];
            i++;
        }
        s1[i] = '\0';
        
        printf("%s\n", s1);
    }
    
    return 0;
}
