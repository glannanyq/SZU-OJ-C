#include <stdio.h>

int main() {
	int n;
	
	while (scanf("%d", &n) == 1 && n != -1) {
		int a[n];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		
		if (n == 1) {
			printf("YES\n");
			continue;
		}
		
		int i = 0;
		
		while (i < n - 1 && a[i] < a[i + 1]) {
			i++;
		}
		
		while (i < n - 1 && a[i] == a[i + 1]) {
			i++;
		}
		
		while (i < n - 1 && a[i] > a[i + 1]) {
			i++;
		}
		
		if (i == n - 1) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	
	return 0;
}

