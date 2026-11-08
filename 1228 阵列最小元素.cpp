#include <stdio.h>

int main() {
  	int t;
  	scanf("%d", &t);
  	
  	while(t--) {
		int n, m;
  		scanf("%d %d", &n, &m);
  
  		double a[n][m];
  		double min_value;
        int min_row = 0, min_col = 0;
        
  		for (int i = 0; i < n; i++) {
    	  	for (int j = 0; j < m; j++) {
    	      	scanf("%lf", &a[i][j]);
    	      	if ((i == 0 && j == 0) || a[i][j] < min_value) {
                    min_value = a[i][j];
                    min_row = i;
                    min_col = j;
                }
            }
        }
        printf("%g %d %d\n", min_value, min_row + 1, min_col + 1);
        }
    }
