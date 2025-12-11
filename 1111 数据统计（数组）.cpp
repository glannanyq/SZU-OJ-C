#include <stdio.h>

int main() 
{
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int n;
        scanf("%d", &n);
        
        int nums[30];  // n < 31
        int sum = 0;
        int pos_count = 0, neg_count = 0;
        int max_val, min_val;
        
        // 读取数据并计算总和
        for (int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
            sum += nums[i];
            
            // 统计正负数
            if (nums[i] > 0) pos_count++;
            else if (nums[i] < 0) neg_count++;
            
            // 初始化最大值最小值
            if (i == 0) {
                max_val = nums[i];
                min_val = nums[i];
            }
			else {
                if (nums[i] > max_val) max_val = nums[i];
                if (nums[i] < min_val) min_val = nums[i];
            }
        }
        
        // 计算平均数
        double average = (double)sum / n;
        
        // 统计大于和小于平均数的个数
        int above_avg = 0, below_avg = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > average) above_avg++;
            else if (nums[i] < average) below_avg++;
        }
        
        // 输出结果
        printf("%.2f %d %d\n", average, above_avg, below_avg);
        printf("%d %d\n", pos_count, neg_count);
        printf("max=%d min=%d\n", max_val, min_val);
        
        // 测试用例之间用空行分隔
        if (T > 0) printf("\n");
    }
    
    return 0;
}
