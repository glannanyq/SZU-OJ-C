#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 201

// ±È½Ïº¯Êý
int cmp(const void *a, const void *b) 
{
    const char *s1 = *(const char **)a;
    const char *s2 = *(const char **)b;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    if (len1 != len2) {
        return len1 - len2;
    } else {
        return strcmp(s2, s1);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    
    char *arr[N];
    for (int i = 0; i < N; i++) {
        arr[i] = malloc(MAX_LEN * sizeof(char));
        scanf("%s", arr[i]);
    }
    
    qsort(arr, N, sizeof(char *), cmp);
    
    for (int i = 0; i < N; i++) {
        printf("%s\n", arr[i]);
        free(arr[i]);
    }
    
    return 0;
}
