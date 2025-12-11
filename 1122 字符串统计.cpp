#include <stdio.h>
#include <string.h>

int main() {
  
    char str[100];

        fgets(str, sizeof(str), stdin);
        
        int upper = 0, lower = 0, digits = 0;
        
        for (int j = 0; str[j] != '\0'; j++) {
            char c = str[j];
            
            if (c >= 'A' && c <= 'Z') {
                upper++;
            } else if (c >= 'a' && c <= 'z') {
                lower++;
            } else if (c >= '0' && c <= '9') {
                digits++;
            }
        }

        printf("%d %d %d\n", upper, lower, digits);
    
    return 0;
}
