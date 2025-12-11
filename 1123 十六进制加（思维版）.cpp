#include <stdio.h>
#include <string.h>
#include <math.h>

int isValidHex(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (!((c >= '0' && c <= '9') || 
              (c >= 'A' && c <= 'F') || 
              (c >= 'a' && c <= 'f'))) {
            return 0;
        }
    }
    return 1; 
}

int hexCharToDecimal(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    } else if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    return 0;
}

int hexToDecimal(char str[]) {
    int len = strlen(str);
    int decimal = 0;
    int power = 0;

    for (int i = len - 1; i >= 0; i--) {
        decimal += hexCharToDecimal(str[i]) * pow(16, power);
        power++;
    }
    return decimal;
}

int main() {
    int T;
    char hex1[10], hex2[10];

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%s", hex1);
        scanf("%s", hex2);

        if (!isValidHex(hex1) || !isValidHex(hex2)) {
            printf("-1\n");
            continue;
        }

        int num1 = hexToDecimal(hex1);
        int num2 = hexToDecimal(hex2);
        int sum = num1 + num2;

        printf("%d\n", sum);
    }
    
    return 0;
}
