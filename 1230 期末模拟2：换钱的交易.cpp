#include <stdio.h>
#include <math.h>

int main() {
	int n;
	scanf("%d", &n);
	
	int stranger = n * 100000;
	int million = (1 - pow(2,n)) / (1 - 2);
	printf("%d\n%d\n", stranger, million);
}
