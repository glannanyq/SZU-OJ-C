#include <stdio.h>

int a, n, m, x;

int up(int i, int k) {
	if (i == 1) return a;
	if (i == 2) return k;
	return up(i - 1, k) + up(i - 2, k);
}

int bus(int i, int k) {
	if (i == 1 || i == 2) return a;
	return bus(i - 1, k) + up(i - 2, k);
}

int main() {
	scanf("%d %d %d %d", &a, &n, &m, &x);
	int B = bus(n - 1, 0);
	int A = bus(n - 1, 1) - B;
	int k = (m - B) / A;
	printf("%d\n", bus(x, k));
}
