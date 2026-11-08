#include <stdio.h>
#include <string.h>

double strToDouble(char str[]) {
	double num = 0;
  	int len = strlen(str);
  	int sign = 1, dot = 0, has_num = 0;
  	double div = 1;
  	char tem[11];
  
  	if (len == 0) return 0;
  
  	int idx = 0;
  	if (str[0] == '-') {
      	sign = -1;
        idx = 1;
    }
    
  	for (int i = idx; i < len; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
      		has_num = 1;
      			
      		if (!dot) {
      			num = num * 10 + (str[i] - '0');
			}
			else {
				div *= 10;
				num = num + (str[i] - '0') / div;
			}
    	}
      	else if (str[i] == '.') {
      		if (!dot) {
      			dot = 1; 
			}
        }
    }
    if (!has_num) return 0;
    	
    return num * sign;
}



int main() {
  	int t; 
  	scanf("%d", &t);
  
  	while (t--) {
      	char str[11];
      	scanf("%s", str);
      	
      	float num = strToDouble(str);
      
      	printf("%.6g\n", num);
    }
}
