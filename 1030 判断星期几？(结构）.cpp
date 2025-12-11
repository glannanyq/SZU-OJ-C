#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int y, m, d, start_day;
        scanf("%d/1/1 %d", &y, &start_day);
        scanf("%d/%d/%d", &y, &m, &d);

        int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
            month_days[1] = 29;
        }

        int total_days = 0;
        for (int i = 0; i < m - 1; i++) {
            total_days += month_days[i];
        }
        total_days += (d - 1);

        int day_of_week = (start_day + total_days) % 7;

        printf("%d/%02d/%02d是", y, m, d);

        switch (day_of_week) {
            case 0: printf("星期日\n"); break;
            case 1: printf("星期一\n"); break;
            case 2: printf("星期二\n"); break;
            case 3: printf("星期三\n"); break;
            case 4: printf("星期四\n"); break;
            case 5: printf("星期五\n"); break;
            case 6: printf("星期六\n"); break;
        }
    }
    
    return 0;
}
