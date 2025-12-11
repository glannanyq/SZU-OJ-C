#include <stdio.h>
#include <string.h>

int main() 
{
    int n;
    char name[5];
    int li = 0, zhang = 0, fu = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", name);
        
        if (strcmp(name, "Li") == 0) {
            li++;
        }
		else if (strcmp(name, "Zhang") == 0) {
            zhang++;
        }
		else if (strcmp(name, "Fu") == 0) {
            fu++;
        }
    }
    
    printf("Li:%d\n", li);
    printf("Zhang:%d\n", zhang);
    printf("Fu:%d\n", fu);
}

