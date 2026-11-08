/*题目描述
输入两组整数(每行不超过20个整数，每组整数中元素有可能重复)。
合并两组整数，去掉在两组整数中都出现的整数，并按从大到小顺序排序输出（即两组整数集异或）。

输入
首先输入第一组整数的个数，然后在下一行输入第一组整数，以一个空格分隔各个整数；
然后以同样的方式输入第二组整数。

输出
按从大到小顺序排序输出合并后的整数集
（去掉在两组整数中都出现的整数，以一个空格分隔各个整数），若为空，则输出NULL。*/

#include <stdio.h>

int main() {
    int n1, n2;
    int arr1[25], arr2[25];
    int result[50];
    int count = 0;

    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) scanf("%d", &arr1[i]);
    
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) scanf("%d", &arr2[i]);

    for (int i = 0; i < n1; i++) {
        int f2 = 0;
        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                f2 = 1;
                break;
            }
        }

        if (!f2) {
            result[count++] = arr1[i];
        }
    }

    for (int i = 0; i < n2; i++) {
        int f1 = 0;
        for (int j = 0; j < n1; j++) {
            if (arr2[i] == arr1[j]) {
                f1 = 1;
                break;
            }
        }

        if (!f1) {
            result[count++] = arr2[i];
        }
    }

    if (count == 0) {
        printf("NULL\n");
        return 0;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (result[j] < result[j + 1]) {
                int temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        if (i > 0) printf(" ");
        printf("%d", result[i]);
    }
    printf("\n");
    
    return 0;
}
