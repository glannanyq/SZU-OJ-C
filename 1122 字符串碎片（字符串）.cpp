#include <stdio.h>
#include <string.h>

int main() {
    int t;
    char str[1000];
    
    scanf("%d", &t);
    
    while (t--) {
        scanf("%s", str);
        int len = strlen(str);
        
        int total_length = 0;
        int fragment_count = 0;
        char current_char = str[0];
        int current_length = 1;

        char fragments[100][100] = {0};
        int frag_count = 0;
        int found;

        for (int i = 1; i <= len; i++) {
            if (i < len && str[i] == current_char) {
                current_length++;
            } else {
                total_length += current_length;
                fragment_count++;

                char current_fragment[100] = {0};
                for (int j = 0; j < current_length; j++) {
                    current_fragment[j] = current_char;
                }

                found = 0;
                for (int k = 0; k < frag_count; k++) {
                    if (strcmp(fragments[k], current_fragment) == 0) {
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("%s ", current_fragment);
                    strcpy(fragments[frag_count], current_fragment);
                    frag_count++;
                }

                if (i < len) {
                    current_char = str[i];
                    current_length = 1;
                }
            }
        }

        double average_length = (double)total_length / fragment_count;
        printf("%.2lf\n", average_length);
    }
    
    return 0;
}
