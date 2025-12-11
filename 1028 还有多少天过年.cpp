#include <stdio.h>
int main() {
    int y, m, d, days[] = {31,28,31,30,31,30,31,31,30,31,30,31}, sum = 0;
    scanf("%d %d %d", &y, &m, &d);
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        days[1] = 29;
    sum += days[m-1] - d;
    for (int i = m; i < 12; i++)
        sum += days[i];
    printf("%d", sum);
    return 0;
}
