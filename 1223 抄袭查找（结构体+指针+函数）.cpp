#include <stdio.h>
#include <string.h>

struct Paper {
    int id;
    char answers[3][100];
};

int check(struct Paper *p1, struct Paper *p2) {
    for (int q = 0; q < 3; q++) {
        char *a = p1->answers[q];
        char *b = p2->answers[q];
        
        int len_a = strlen(a);
        int len_b = strlen(b);

        int matches = 0;
        int min_len = len_a < len_b ? len_a : len_b;
        
        for (int i = 0; i < min_len; i++) {
            if (a[i] == b[i]) {
                matches++;
            }
        }

        if (matches >= len_a * 0.9 || matches >= len_b * 0.9) {
            return q + 1;
        }
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    
    struct Paper papers[100];

    for (int i = 0; i < n; i++) {
        scanf("%d", &papers[i].id);
        getchar();
        
        for (int q = 0; q < 3; q++) {
            fgets(papers[i].answers[q], 100, stdin);
            int len = strlen(papers[i].answers[q]);
            if (len > 0 && papers[i].answers[q][len-1] == '\n') {
                papers[i].answers[q][len-1] = '\0';
            }
        }
    }

    int results[100][3];
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cheat = check(&papers[i], &papers[j]);
            if (cheat > 0) {
                results[count][0] = papers[i].id;
                results[count][1] = papers[j].id;
                results[count][2] = cheat;
                count++;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%d %d %d\n", results[i][0], results[i][1], results[i][2]);
    }

}
