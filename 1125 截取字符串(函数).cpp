#include <stdio.h>
#include <string.h>

int Substring(char str1[], char str2[], int index) {
  	int len = strlen(str1);
  	if (index >= len) {
      	return 0;
    }
  	int i = index, j = 0;
  	while (str1[i] != '\0') {
      	str1[i++] = str2[j++];
    }
  	str2[j] = '\0';
  	return 1;
}

int main()
{
  	int n;
  	scanf("%d", &n);
  	
  	for (int i = 0; i < n; i++) {
      	char str1[100], str2[100];
      	int index;
      
      	scanf("%s %d", str1, &index);
      	
      	if (Substring(str1, str2, index)) {
      		
            printf("%s\n", str2);
        } else {
            printf("IndexError\n");
        }
    }
}
