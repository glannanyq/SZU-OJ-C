#include <stdio.h>
#include <string.h>

int isPal(const char* s, int l, int r) {
    if (l >= r) return 1;
    return (s[l] == s[r]) && isPal(s, l + 1, r - 1);
}

int countHelper(const char* s, int i, int j, int n) {

    if (i >= n) return 0;

    if (j >= n) return countHelper(s, i + 1, i + 1, n);

    return isPal(s, i, j) + countHelper(s, i, j + 1, n);
}

int countSubstrings(const char* s) {
    int n = strlen(s);
    return countHelper(s, 0, 0, n);
}

int main() {
    char s[100];
    scanf("%s", s);
    printf("%d\n", countSubstrings(s));
    return 0;
}
