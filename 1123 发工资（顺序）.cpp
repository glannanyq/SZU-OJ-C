#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int hundred = n / 100;
    n %= 100;
    printf("%d\n", n);
    int fifty = n / 50;
    n %= 50;
	printf("%d\n", n); 
    int twenty = n / 20;
    n %= 20;
    printf("%d\n", n);
    int ten = n / 10;
    n %= 10;
    printf("%d\n", n);
    int five = n / 5;
    n %= 5;
    printf("%d\n", n);
    
    int one = n;
    
    printf("%d %d %d %d %d %d\n", hundred, fifty, twenty, ten, five, one);
    
    return 0;
}
