#include <stdio.h>

int main() {
    int M, T, U, F, D;
    scanf("%d %d %d %d %d", &M, &T, &U, &F, &D);
    
    char s[100001];
    for (int i = 0; i < T; i++) {
        scanf(" %c", &s[i]);  // 注意！%c前的空格用于跳过换行符！
    }
    
    int total_time = 0;
    int max_distance = 0;
    
    for (int i = 0; i < T; i++) {
        // 往返总时间 = 去程时间 + 回程时间
        int time_round_trip;
        if (s[i] == 'u' || s[i] == 'd') {
            time_round_trip = U + D;  // 去程如果是上坡，回程就是下坡，反之亦然
        } else { // 'f'
            time_round_trip = F * 2;  // 平地往返时间相同
        }
        
        total_time += time_round_trip;
        
        // 如果总时间超过限制，就不能再往前跑了
        if (total_time > M) {
            break;
        }
        
        max_distance = i + 1;  // 能跑到第i+1段（从1开始计数）
    }
    
    printf("%d\n", max_distance);
    return 0;
}
