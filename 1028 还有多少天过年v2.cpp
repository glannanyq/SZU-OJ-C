#include <stdio.h>

// 判断是否为闰年
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int year, month, day;
    int dInMon[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total = 0;
    int remain = 0;

    scanf("%d %d %d", &year, &month, &day);
    
    // 如果是闰年，2月有29天
    if (isLeapYear(year)) {
        dInMon[1] = 29;
        total = 366; // 闰年有366天
    } else {
        dInMon[1] = 28;
        total = 365; // 平年有365天
    }
    
    // 计算已经过去的天数
    int passed = 0;
    for (int i = 0; i < month - 1; i++) {
        passed += dInMon[i];
    }
    passed += day;
    
    // 计算剩余天数
    remain = total - passed;
    
    // 输出结果
    printf("%d\n", remain);
    
    return 0;
}
