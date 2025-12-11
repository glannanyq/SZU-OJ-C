#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char words[100][100];
    int counts[100] = {0};
    int word_count = 0;
    
    char word[100];

    while (1) {
        scanf("%s", word);

        if (strcmp(word, "0") == 0) {
            break;
        }

        int found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(words[i], word) == 0) {
            	
                counts[i]++;
                found = 1;
                break;
            }
        }

        if (!found && word_count < 100) {
        	
            strcpy(words[word_count], word);
            counts[word_count] = 1;
            word_count++;
        }
    }

    for (int i = 0; i < word_count - 1; i++) {
        for (int j = 0; j < word_count - 1 - i; j++) {
            if (counts[j] < counts[j + 1]) {
            	
                int temp_count = counts[j];
                counts[j] = counts[j + 1];
                counts[j + 1] = temp_count;

                char temp[100];
                
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
                
            }
        }
    }

    for (int i = 0; i < word_count; i++) {
        printf("%d %s\n", counts[i], words[i]);
    }
    
    return 0;
}
