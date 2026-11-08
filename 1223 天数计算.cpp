#include <stdio.h>

struct Date {
	int y, m, d;
};  

int isLyear(int y) {
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) return 1;
	return 0;
}

int main() {
	struct Date date;
	
	scanf("%d %d %d", &date.y, &date.m, &date.d);
	
	int DinM[13] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (isLyear(date.y)) {
		DinM[2] = 29;
	}
	
	int total = 0;
	
	for (int i = 0; i < date.m; i++) {
		total += DinM[i];
	}
	
	total += date.d;
	
	printf("%d\n", total);
	
}
