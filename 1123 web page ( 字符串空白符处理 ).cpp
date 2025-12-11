#include <stdio.h>

int main()
{
  	int t;
  	char str[500];
  	scanf("%d", &t);
  	getchar();
  	
  	for (int i = 0; i < t; i++){
      	fgets(str, sizeof(str), stdin);
      
      	int j = 0;
      	for (int k = 0; str[k]!='\0'; k++){
          	if (str[k] != ' ' || str[k] != '\n'){
              	str[j] = str[k];
              	j++;
            }
        }
      	
      	str[j] = '\0';
      
      	printf("%s",str);
    }
}
              	
      	
