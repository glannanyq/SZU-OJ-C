#include <stdio.h>

int main() {
	int a, b, c;
	char op;
	scanf("%d %d %c", &a, &b, &op);

	if (op == '+') {
		c = a + b;
		printf("%d\n", c);
	}
	
	else if (op == '-') {
		c = a - b;
		printf("%d\n", c);
	}
	
	else if (op == '*') {
		c = a * b;
		printf("%d\n", c);
	}

	
	else if (op == '/') {
		if (b == 0) {
			printf("Divided by zero!\n");
		}
		else {
			c = a / b;
			printf("%d\n", c);
		}
	}
	
	else {
		printf("Invalid operator!\n");
	}

}
