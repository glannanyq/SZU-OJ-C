#include <stdio.h>

int main() {
    
  	int t;
    scanf("%d", &t);
    
    while (t--) {
    	int year, month, day, remain;
    	int total = 0;
    	scanf("%d%d%d", &year, &month, &day);

    	for (int i = 1; i < month; i++) {
        	switch(i) {
            	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                	total += 31;
                	break;
            	case 4: case 6: case 9: case 11:
                	total += 30;
                	break;
            	case 2:
                	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                    	total += 29;
                	}
            		else {
                    	total += 28;
                	}
                	break;
        	}
    	}
    	total += day;

    	printf("%d\n", total);
      
    }
  
    return 0;
}
