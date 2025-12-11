#include<stdio.h>

int main()
{
	int n,a;
	int min,max;
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &a);
		
		if (a % 2 != 0 || a < 2){
			printf("0 0\n");
			continue;
		}
		
		min = a / 4 + (a % 4) / 2;
		max = a / 2;
		
		printf("%d %d\n", min, max);
	} 
}
