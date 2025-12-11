#include <stdio.h>

int main() {
    long long num1, num2;
    char op;
    
    scanf("%llx %c %llx", &num1, &op, &num2);
    
    long long result;
    if (op == '+') {
        result = num1 + num2;
    } else {
        result = num1 - num2;
    }

    printf("%llo\n", result);
    
    return 0;
}
