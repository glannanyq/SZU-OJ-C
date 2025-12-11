#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

int main() {
    char target[100];
    char article[MAX_LENGTH];
    char words[MAX_WORDS][MAX_WORD_LEN];
    int positions[MAX_WORDS];
    int word_count = 0;

    fgets(target, sizeof(target), stdin);
    fgets(article, sizeof(article), stdin);

    target[strcspn(target, "\n")] = '\0';
    article[strcspn(article, "\n")] = '\0';
    
    for (int i = 0; target[i]; i++) {
        target[i] = tolower(target[i]);
    }
    
    int article_len = strlen(article);
    int current_pos = 0;

    for (int i = 0; i < article_len && word_count < MAX_WORDS; i++) {
        if (article[i] == ' ') continue;

        int word_start = i;
        int word_len = 0;
        char temp_word[MAX_WORD_LEN] = {0};

        while (i < article_len && article[i] != ' ') {
            if (word_len < MAX_WORD_LEN - 1) {
                temp_word[word_len] = article[i];
                word_len++;
            }
            i++;
        }
        temp_word[word_len] = '\0';
        
        if (word_len > 0) {
            strcpy(words[word_count], temp_word);
            positions[word_count] = word_start;
            word_count++;
        }

    }
    
    int count = 0;
    int first_pos = -1;
    
    for (int i = 0; i < word_count; i++) {
        char temp[MAX_WORD_LEN] = {0};

        for (int j = 0; j < strlen(words[i]); j++) {
            temp[j] = tolower(words[i][j]);
        }
        temp[strlen(words[i])] = '\0';

        if (strcmp(temp, target) == 0) {
            count++;
            if (first_pos == -1) {
                first_pos = positions[i];
            }
        }
    }

    if (count > 0) {
        printf("%d %d\n", count, first_pos);
    } else {
        printf("-1\n");
    }
    
    return 0;
}
