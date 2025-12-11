#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 10000

void toLowerString(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char target[100];
    char article[MAX_LENGTH];

    fgets(target, sizeof(target), stdin);
    fgets(article, sizeof(article), stdin);

    target[strcspn(target, "\n")] = '\0';
    article[strcspn(article, "\n")] = '\0';

    toLowerString(target);
    toLowerString(article);
    
    int target_len = strlen(target);
    int article_len = strlen(article);
    
    int count = 0;
    int first_pos = -1;
  
    for (int i = 0; i <= article_len - target_len; i++) {

        if (strncmp(&article[i], target, target_len) == 0) {

            int before = 0, after = 0;

            if (i == 0 || article[i - 1] == ' ') {
                before = 1;
            }

            if (i + target_len == article_len || article[i + target_len] == ' ') {
                after = 1;
            }

            if (before && after) {
                count++;
                if (first_pos == -1) {
                    first_pos = i;
                }
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
