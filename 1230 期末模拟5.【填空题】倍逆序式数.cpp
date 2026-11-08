#include <stdio.h>

/********** Write your code here! **********/
// 计算逆序数并存储各位数字到arr
int rev(int n, int arr[]) {
    int m = 0;
    int temp = n;
    int digits = 0;
    
    // 先计算位数
    while (temp > 0) {
        digits++;
        temp /= 10;
    }
    
    // 计算逆序数并存储各位数字
    temp = n;
    for (int i = 0; i < digits; i++) {
        arr[i] = temp % 10;  // 从个位开始存储
        temp /= 10;
    }
    
    // 计算逆序数
    for (int i = 0; i < digits; i++) {
        m = m * 10 + arr[i];
    }
    
    return m;
}
/*******************************************/

int main()
{
	int t, a, b, arr[100], i;
	scanf("%d", &t);
	while (t--) {		
/********** Write your code here! **********/
        scanf("%d", &a);
/*******************************************/
		b = rev(a,arr);		
/********** Write your code here! **********/
        // 检查是否存在倍逆序式
        int found = 0;
        
        // 计算n的位数
        int digits = 0;
        int temp = a;
        while (temp > 0) {
            digits++;
            temp /= 10;
        }
        
        // 检查b是否是a的整数倍
        if (b % a == 0) {
            int k = b / a;
            // 输出倍逆序式
            printf("%d*%d=%d\n", a, k, b);
            found = 1;
        }
        
        if (!found) {
            // 输出n和m，m需要保持与n相同的位数
            // 由于rev函数已经正确处理了前导0，直接输出即可
            printf("%d ", a);
            
            // 输出逆序数，保持相同位数（需要处理前导0）
            // 按照arr数组中存储的顺序输出
            temp = a;
            int count = 0;
            while (temp > 0) {
                count++;
                temp /= 10;
            }
            
            for (i = 0; i < count; i++) {
                printf("%d", arr[i]);
            }
            printf("\n");
        }
/*******************************************/
	}
	return 0;
}
