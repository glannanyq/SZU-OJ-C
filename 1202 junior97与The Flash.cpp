#include <stdio.h>
#include <math.h> 

#define PI 3.141592653

int main() {
	int T;
	scanf("%d", &T);
	
	while(T--) {
		int n, m;
		scanf("%d %d", &n, &m);
		
		int cur = 1;
		double total = 0;
		double denom = sin(PI / n);
		
		for(int i = 0; i < m; i++) {
			int target;
			scanf("%d", &target);
			int diff = abs(target - cur);
			int d = diff < n - diff ? diff : n - diff;
			
			if(d > 0) {
				double len = sin (PI * d / n) / denom;
				total += len;
			}
			
			cur = target;
		}
		printf("%.5lf\n", total);
	} 

}
