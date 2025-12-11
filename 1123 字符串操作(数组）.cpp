#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 10005

char str[MAX_LEN * 2];  // 字符串缓冲区
int length = 0;         // 当前字符串长度

// 判断是否为元音
int isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// 在指定位置插入字符串
void insert_str(int index, char* substr) {
    int sublen = strlen(substr);
    
    // 将原字符串从index-1位置向后移动
    for (int i = length - 1; i >= index - 1; i--) {
        str[i + sublen] = str[i];
    }
    
    // 插入新字符串
    for (int i = 0; i < sublen; i++) {
        str[index - 1 + i] = substr[i];
    }
    
    length += sublen;
    str[length] = '\0';
    printf("%s\n", str);
}

// 删除指定字符
void delete_char(char c) {
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] != c) {
            str[j++] = str[i];
        }
    }
    length = j;
    str[length] = '\0';
    printf("%s\n", str);
}

// 删除指定范围的子串
void delete_range(int left, int right) {
    int delete_len = right - left + 1;
    
    // 将后面的字符串前移
    for (int i = right; i < length; i++) {
        str[left - 1 + i - right] = str[i];
    }
    
    length -= delete_len;
    str[length] = '\0';
    printf("%s\n", str);
}

// 将字符串反转后接在自身后面
void insert_reverse_str() {
    // 先反转当前字符串到末尾
    for (int i = 0; i < length; i++) {
        str[length + i] = str[length - 1 - i];
    }
    length *= 2;
    str[length] = '\0';
    printf("%s\n", str);
}

// 反转字符串
void reverse_str() {
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
    printf("%s\n", str);
}

// 统计元音数量
void count_vowel() {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (isVowel(str[i])) {
            count++;
        }
    }
    printf("%d\n", count);
}

int main() {
    char operation[50];
    str[0] = '\0';  // 初始为空串
    
    while (1) {
        scanf("%s", operation);
        
        if (strcmp(operation, "OVER") == 0) {
            break;
        }
        else if (strcmp(operation, "INSERT_STR") == 0) {
            int index;
            char substr[MAX_LEN];
            scanf("%d %s", &index, substr);
            insert_str(index, substr);
        }
        else if (strcmp(operation, "DELETE_CHAR") == 0) {
            char c;
            scanf(" %c", &c);
            delete_char(c);
        }
        else if (strcmp(operation, "DELETE_RANGE") == 0) {
            int left, right;
            scanf("%d %d", &left, &right);
            delete_range(left, right);
        }
        else if (strcmp(operation, "INSERT_REVERSE_STR") == 0) {
            insert_reverse_str();
        }
        else if (strcmp(operation, "REVERSE_STR") == 0) {
            reverse_str();
        }
        else if (strcmp(operation, "COUNT_VOWEL") == 0) {
            count_vowel();
        }
    }
    
    return 0;
}
