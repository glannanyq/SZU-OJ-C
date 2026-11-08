#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int t;
	scanf("%d", &t);
	getchar();
	
	while (t--) {
		char str1[11], str2[11], str3[11];
		
		fgets(str1, sizeof(str1), stdin);
		getchar();
		fgets(str2, sizeof(str2), stdin);
		getchar();
		fgets(str3, sizeof(str3), stdin);
		getchar();
		
		int a1, a2, a3, b1, b2, b3;
		scanf("%d %d", &a1, &b1);
		scanf("%d %d", &a2, &b2);
		scanf("%d %d", &a3, &b3);
		getchar();
		
		int new_len = (b1 - a1 + 1) + (b2 - a2 + 1) + (b3 - a3 + 1);
		char* new_str = (char *)malloc((new_len + 1) * sizeof(char));
		char *p = new_str;
		
		char *ptr1 = str1 + (a1 - 1);
		for (int i = 0; i < (b1 - a1 + 1); i++) {
			*p = *ptr1;
			p++;
			ptr1++;
		}
		
		char *ptr2 = str2 + (a2 - 1);
		for (int i = 0; i < (b2 - a2 + 1); i++) {
			*p = *ptr2;
			p++;
			ptr2++;
		}
		
		char *ptr3 = str3 + (a3 - 1);
		for (int i = 0; i < (b3 - a3 + 1); i++) {
			*p = *ptr3;
			p++;
			ptr3++;
		}
		
		*p = '\0';
		
		char *output = new_str;
		while (*output != '\0') {
			putchar(*output);
			output++; 
		}
		printf("\n");
		free(new_str);
		
		
		
	}
}
