#include <stdio.h>
#include <string.h>
 
struct Popul {
	char name[10];
	float total;
};

void bubble(struct Popul popul[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (popul[j].total < popul[j + 1].total) {
                struct Popul temp;
                
                strcpy(temp.name, popul[j].name);
                temp.total = popul[j].total;

                strcpy(popul[j].name, popul[j + 1].name);
                popul[j].total = popul[j + 1].total;

                strcpy(popul[j + 1].name, temp.name);
                popul[j + 1].total = temp.total;
            }
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	
	struct Popul popul[n];
	
	for (int i = 0; i < n; i++) {
		scanf("%s %f", popul[i].name, &popul[i].total);
	}
	
    bubble(popul, n);
    
    for (int i = 0; i < n; i++) {
        printf("%s %gÍòÈË\n", popul[i].name, popul[i].total);
    }
}
