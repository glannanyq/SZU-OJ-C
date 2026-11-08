#include <stdio.h>
#include <string.h>

struct Birth {
    int y, m, d;
};

int compare(struct Birth date1, struct Birth date2) {
    if (date1.y != date2.y) {
        return date1.y - date2.y;
    }
    if (date1.m != date2.m) {
        return date1.m - date2.m;
    }
    return date1.d - date2.d;
}

int main() {
    int t;
    scanf("%d", &t);
    
    struct Birth dates[t];

    for (int i = 0; i < t; i++) {
        scanf("%d %d %d", 
              &dates[i].y, 
              &dates[i].m, 
              &dates[i].d);
    }
  	
  	int first = 0, second = 0;

    if (compare(dates[0], dates[1]) > 0) {
        first = 1;
        second = 0;
    }
  	else if (compare(dates[0], dates[1]) < 0) {
        first = 0;
        second = 1;
    }
  	else {
		first = 0;
        second = 0;
    }
  	
  	for (int i = 2; i < t; i++) {
        if (compare(dates[i], dates[first]) < 0) {
            second = first;
            first = i;
        } else if (compare(dates[i], dates[second]) < 0) {
            if (compare(dates[i], dates[first]) != 0) {
                second = i;
            }
        } else if (first == second) {
            second = i;
        }
    }

    printf("%d-%d-%d\n", dates[second].y, dates[second].m, dates[second].d);
    
    return 0;
}
