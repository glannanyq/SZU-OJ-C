#include <stdio.h>

int main() 
{
    char c, max = 0;
    
    while ((c = getchar()) != '\n' && c != EOF) {
        if (max == 0) {
            max = c;
        }
      	else if (c < max) {
            max = c;
        }
    } 
    
    printf("%c\n", max);
    return 0;
}
