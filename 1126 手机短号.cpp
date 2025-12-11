#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidPrefix(char prefix[]) {
    char validPrefixes[18][4] = {
        "133", "153", "180", "181", "189",
        "130", "131", "132", "155", "156",
        "134", "135", "136", "137", "138", "182", "183", "184"
    };
    
    for (int i = 0; i < 18; i++) {
        int match = 1;
        for (int j = 0; j < 3; j++) {
            if (prefix[j] != validPrefixes[i][j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            return 1;
        }
    }
    return 0;
}

int getShortNumber(char phone[], char shortNum[]) {
    int len = 0;
    while (phone[len] != '\0') {
        len++;
    }
    if (len != 11) {
        return 0;
    }

    for (int i = 0; i < 11; i++) {
        if (phone[i] < '0' || phone[i] > '9') {
            return 0;
        }
    }

    char prefix[4];
    for (int i = 0; i < 3; i++) {
        prefix[i] = phone[i];
    }
    prefix[3] = '\0';
    
    if (!isValidPrefix(prefix)) {
        return 0;
    }

    shortNum[0] = '6';
    for (int i = 1; i < 6; i++) {
        shortNum[i] = phone[i + 5];
    }
    shortNum[6] = '\0';
    
    return 1;
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        char phone[12], shortNum[7];
        scanf("%s", phone);
        
        if (getShortNumber(phone, shortNum)) {
            printf("%s\n", shortNum);
        } else {
            printf("error\n");
        }
    }
    
    return 0;
}
