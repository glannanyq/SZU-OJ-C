#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int t;
    scanf("%d", &t);
    getchar();
    
    while (t--) {
        char bef[1000], key[100], aft[1000];

        scanf("%s", bef);
        //OR:
		//fgets(bef, sizeof(bef), stdin);
        //bef[strcspn(bef, "\n")] = '\0'; 
		        
        scanf("%s", key);
        getchar();
        
        char *p = bef, *q = key, *s = aft;
        char *start = key;
        
        while (*p != '\0') {
            int shift = *q - '0';
            char base, enc;
                
            if (islower(*p)) {
                base = 'a';
            }
			else {
                base = 'A';
            }
                
            enc = ((*p + shift - base) % 26) + base;
            *s = enc;
            
        	p++;
        	s++;
        	
            q++;
            if (*q == '\0') {
            	q = start;
			}

    	}
        
        *s = '\0';
        printf("%s\n", aft);
	}
    
    return 0;
}
