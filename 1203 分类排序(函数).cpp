#include <stdio.h>

void sort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j= 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]){
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

int find(int a[], int n, int value) {
	for (int i = 0; i < n; i++) {
		if (a[i] == value) {
			return i;
		}
	}
	return -1;
}

void display(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d", a[i]);
		if (i < n - 1){
			printf(" ");
		}
	}
	printf("\n");
}

void reverse(int a[], int n) {
	for (int i = 0; i < n / 2; i++) {
		int temp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = temp; 
	}
}

int main() {
	int n;
	scanf("%d", &n);
	
	while (n--) {
		int arr[10];
		int size = 10;
		
		for (int i = 0; i < 10; i++) {
			scanf("%d", &arr[i]);
		}
		
		int a;
		scanf("%d", &a);
		
		if (a % 2 != 0 && find(arr, 10, a) != -1) {
			int pos = find(arr, 10, a);
			for (int i = pos; i < 9; i++) {
				arr[i] = arr[i + 1]; 
			}
			size = 9;
			
			sort(arr, size);
			display(arr, size);
		}
		
		else if (a % 2 == 0 && find(arr, 10, a) == -1) {
			arr[10] = a;
			size = 11;
			
			sort(arr, size);
			reverse(arr, size);
			display(arr, size);
		}
		
		else {
			int odds[10], evens[10];
			int odd_count = 0, even_count = 0;
			
			for (int i = 0; i < 10; i++) {
				if (arr[i] % 2 != 0) {
					odds[odd_count++] = arr[i];
				}
				else {
					evens[even_count++] = arr[i];
				}
			}
			
			sort(odds, odd_count);
			reverse(odds, odd_count);
			
			sort(evens, even_count);
			reverse(evens, even_count);

			int result[10];
            int idx = 0;
            
            for (int i = 0; i < odd_count; i++) {
                result[idx++] = odds[i];
            }
            for (int i = 0; i < even_count; i++) {
                result[idx++] = evens[i];
            }

            display(result, 10);
		}
	} 
}
