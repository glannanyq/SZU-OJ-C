#include <stdio.h>

int main() {
	int n, pos;
	scanf("%d", &n);
	int grade[n];
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &grade[i]); 	
	}
	
	scanf("%d", &pos);
	
	int *p = grade;
	
	p = p + pos;
	
	int pre = *(--p);
	
	int cur = *(++p);
	
	int nex = *(++p);
	
	printf("%d %d %d", pre, cur, nex); 
	
}
