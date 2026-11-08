#include <stdio.h>

int helper(int num, char str[], int idx) {
    if (num == 0) {
        return idx;
    }

    idx = helper(num / 10, str, idx);
    str[idx] = (num % 10) + '0';
    return idx + 1;
}

void itostr(int num, char str[]) {
    if (num == 0) {
        str[0] = '0';
        str[1] = '\0';
        return;
    }
    
    int idx = 0;
    if (num < 0) {
        str[0] = '-';
        idx = 1;
        num = -num;
    }

    int end_idx = helper(num, str, idx);
    str[end_idx] = '\0';
}

int main()
{
    const int SIZE = 20;
    int t,num;
    char str[SIZE];
    
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &num);
        itostr(num, str);
        printf("%s\n", str); 	
    }
    return 0;		
}
