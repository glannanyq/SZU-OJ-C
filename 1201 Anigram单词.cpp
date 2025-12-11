#include<stdio.h>
#include<string.h>

void sort_string(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int findAnigram(char str1[][10], char str2[], char sorted_str1[][10], int N) {
    int num = 0;
    char sorted_str2[10];

    strcpy(sorted_str2, str2);
    sort_string(sorted_str2);
    
    for (int i = 0; i < N; i++) {

        if (strcmp(str1[i], str2) == 0) {
            continue;
        }

        if (strcmp(sorted_str1[i], sorted_str2) == 0) {
            num++;
        }
    }
    
    return num;
}

int main() {
    int N;
    scanf("%d", &N);
    
    char word[10000][10] = {0};
    char sorted_word[10000][10] = {0};
    
    for (int i = 0; i < N; i++) {
        scanf("%s", word[i]);

        strcpy(sorted_word[i], word[i]);
        sort_string(sorted_word[i]);
    }

    int M, num;
    scanf("%d", &M);
    char search[10000][10] = {0};
    
    for (int i = 0; i < M; i++) {
        scanf("%s", search[i]);
    }
    
    for (int i = 0; i < M; i++) {
        num = findAnigram(word, search[i], sorted_word, N);
        printf("%d", num);
        if (i < M - 1) printf("\n");
    }

}
