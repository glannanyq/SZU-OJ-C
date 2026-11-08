#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	
	while(t--) {
		int a, b, c; 
		scanf("%d %d %d", &a, &b, &c);
		int *pa = &a, *pb = &b, *pc = &c;
		int *temp;
		
		if (*pa < *pb) {
            temp = pa; pa = pb; pb = temp;
        }
        if (*pa < *pc) {
            temp = pa; pa = pc; pc = temp;
        }
        if (*pb < *pc) {
            temp = pb; pb = pc; pc = temp;
        }
        
        printf("%d %d %d \n", *pa, *pb, *pc);
		
	} 
}
