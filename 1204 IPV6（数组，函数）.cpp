#include <stdio.h>
#include <string.h>

char seg[8][8+1];
char line[200];

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    getchar();

    while (t--) {
        if (!fgets(line, sizeof(line), stdin)) break;
        int L = strlen(line);
        while (L > 0 && (line[L-1] == '\n' || line[L-1] == '\r')) {
            line[--L] = '\0';
        }

        int pos = 0;
        for (int i = 0; i < 8; ++i) {
            int j = 0;
            while (pos < L && line[pos] != ':' && j < 8) {
                seg[i][j++] = line[pos++];
            }
            seg[i][j] = '\0';
            pos++;
        }

        for (int i = 0; i < 8; ++i) {
            int len = strlen(seg[i]);
            int p = 0;
            while (p < len - 1 && seg[i][p] == '0') p++;
            if (p > 0) {
                int q = 0;
                while (p < len) seg[i][q++] = seg[i][p++];
                seg[i][q] = '\0';
            }
        }

        int best_start = -1, best_len = 0;
        for (int i = 0; i < 8; ) {
            if (strcmp(seg[i], "0") == 0) {
                int j = i;
                while (j < 8 && strcmp(seg[j], "0") == 0) j++;

                best_start = i;
                best_len = j - i;
                break;
            } else {
                ++i;
            }
        }

        int need_colon = 0;
        for (int i = 0; i < 8; ++i) {
            if (i == best_start) {
                printf("::");
            
                need_colon = 0;
                i += best_len - 1;
                continue;
            }
            if (need_colon) printf(":");
            printf("%s", seg[i]);
            need_colon = 1;
        }

        printf("\n");
    }

    return 0;
}

