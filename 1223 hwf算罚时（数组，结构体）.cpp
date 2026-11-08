#include <stdio.h> 

struct Problem {
	int h, m, s, a;
};

struct Team {
	struct Problem problems[15];
	long long total;
};

int main() {
	int t; 
	scanf("%d", &t);
	
	while (t--) {
		long long n;
		int k;
		scanf("%d %d", &n, &k);
		
		struct Team teams[1005];
		
		for (int i = 0; i < n; i++) {
			teams[i].total = 0;
			
			for (int j = 0; j < k; j++) {
                scanf("%d %d %d %d", 
                      &teams[i].problems[j].h,
                      &teams[i].problems[j].m,
                      &teams[i].problems[j].s,
                      &teams[i].problems[j].a);	
			}
		}
		
		for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                if (teams[i].problems[j].h == 0 &&
                    teams[i].problems[j].m == 0 &&
                    teams[i].problems[j].s == 0) {
                    continue;
                }
                
                long long AC = (long long)teams[i].problems[j].h * 3600 +
                                (long long)teams[i].problems[j].m * 60 +
                                (long long)teams[i].problems[j].s;
                                
            	long long punish = (long long)teams[i].problems[j].a * 1200;
            	
            	teams[i].total += AC + punish;
    	    }
    	}
    	
		for (int i = 0; i < n; i++) {
            printf("%lld", teams[i].total);
            if (i < n - 1) printf(" ");
        }
        printf("\n");

        if (t > 0) {
            printf("\n");
		}
	}
	
}
