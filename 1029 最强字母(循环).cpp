#include <stdio.h>

int main() 
{
    char c, max = 0;
    
    while ((c = getchar()) != '\n' && c != EOF) {
        if (max == 0) {
            max = c;
        }
		else if (c >= 'A' && c <= 'Z') {
            if (max >= 'A' && max <= 'Z') {
                if (c < max) max = c;
            }
			else {
                max = c;
            }
        } else if (c >= 'a' && c <= 'z' && max >= 'a' && max <= 'z') {
            if (c < max) max = c;
        }
    } 
    
    printf("%c\n", max);
}
