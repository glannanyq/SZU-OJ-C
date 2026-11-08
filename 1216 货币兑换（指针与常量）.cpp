#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	
	const double D_rate = 6.2619;
	const double E_rate = 6.6744;
	const double Y_rate = 0.0516;
	const double H_rate = 0.8065;
	
	const double *rate_ptr;
	
	while (t--) {
		char type;
		double amount;
		
		scanf(" %c %lf", &type, &amount);
		
		if (type == 'D')  rate_ptr = &D_rate;
		if (type == 'E')  rate_ptr = &E_rate;
		if (type == 'Y')  rate_ptr = &Y_rate;
		if (type == 'H')  rate_ptr = &H_rate;
		
		double rmb = amount * (*rate_ptr);
		printf("%.4lf\n", rmb); 
	}
}
