#include <stdio.h> 

int GetPathNumber(int a,int b) {
	if (a == b) {
		return 1;
	}
	if (a > b) {
		return 0;
	}
	int d = b - a;
	int fib[60];
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i <= d; i++) {
		fib[i] = fib[i - 1] + fib[i - 2]; 
	}
	return fib[d];
	
}

int main() {
	int n;
	scanf("%d", &n);
	
	while (n--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", GetPathNumber(a, b));
		
	}
}
