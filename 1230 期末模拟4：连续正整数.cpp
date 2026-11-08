/*题目描述
一个正整数有可能可以被表示为n(n>=2)个连续正整数之和，如：
15=1+2+3+4+5
15=4+5+6
15=7+8
请编写程序，根据输入的任何一个正整数，找出符合这种要求的所有连续正整数序列。

输入
输入一个正整数（小于等于10000）

输出
输出符合题目描述的全部正整数序列，每行一个序列，
每个序列都从该序列的最小正整数开始、以从小到大的顺序打印。
如果结果有多个序列，按各序列的最小正整数的大小从小到大打印各序列。
此外，序列不允许重复，序列内的整数用一个空格分隔，每个序列最后一个整数后要有一个空格。
如果没有符合要求的序列，输出"NULL"。*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int found = 0;

    for (int a = 1; a <= n / 2; a++) {
        int sum = 0;
        int count = 0;

        for (int b = a; sum < n; b++) {
            sum += b;
            count++;
            
            if (sum == n && count >= 2) {
                for (int i = 0; i < count; i++) {
                    printf("%d", a + i);
                  	if (i < count - 1) printf(" ");
                }
                printf("\n");
                found = 1;
                break;
            }
        }
    }
    
    if (!found) {
        printf("NULL\n");
    }
    
    return 0;
}
