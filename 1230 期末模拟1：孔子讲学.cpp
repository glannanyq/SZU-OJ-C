#include <stdio.h>

int main() {
	int a, n, m;
	scanf("%d %d %d", &a, &n, &m);
	double sum = n * a + m * a * 0.5;
	printf("%lf", sum);
}

