#include <stdio.h>
#include <stdlib.h> 

int ThreeSame(int a[6]) {
	for(int i = 0; i < 4; i++) {
		if (a[i] == a[i + 1] && a[i + 1] == a[i + 2]) {
			return 0;
		}
	}
	return 1;
}

int UnderFour(int a[6]) {
	for(int i = 0; i < 4; i++) {
		if (abs(a[i] - a[i + 1]) > 4) {
			return 0;
		}
	}
	return 1;
}

void Standard(int num, int a[6]) {
	for (int i = 5;i >= 0; i--) {
		a[i] = num % 10;
		num /= 10;
	}
} 

int Range(int a[6]) {
	for (int i = 0; i < 6; i++) {
		if (a[i] < 0 || a[i] > 6) {
			return 0; 
		}
	}
	return 1;
}

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		
		for (int num = x; num <= y; num++) {
			int a[6];
			Standard(num, a);
			
			if (!Range(a)) {
				continue;
			}
			
			if (!UnderFour(a)) {
				continue;
			}
			
			if (!ThreeSame(a)) {
				continue;
			}
			
			printf("%06d\n", num);
		}
		
		if (i != n - 1) {
			printf("\n");
		}
	}
		
}

