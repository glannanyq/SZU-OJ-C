#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    double x = *(double *)a;
    double y = *(double *)b;
    if (x < y) return 1;
    if (x > y) return -1;
    return 0;
}

int main() {
    char ch;
    char buf[30];
    int index = 0;
    double nums[20];
    int count = 0;

    while ((ch = getchar()) != EOF) {

        if (ch == '\n' || ch == '\r') {
            continue;
        }

        if (isdigit(ch) || ch == '.') {
            buf[index++] = ch;
        } else {
            if (index > 0) {
                buf[index] = '\0';
                nums[count++] = atof(buf);
                index = 0;
            }
        }
    }

    if (index > 0) {
        buf[index] = '\0';
        nums[count++] = atof(buf);
    }

    qsort(nums, count, sizeof(double), cmp);

    for (int i = 0; i < count; i++) {
        printf("%.2f ", nums[i]);
    }

    return 0;
}

