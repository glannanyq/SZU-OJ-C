#include <stdio.h>

int main() 
{
    int n;
    char name[5];
    int li = 0, zhang = 0, fu = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%s", name);
        
        if (name[0] == 'L') {
            li++;
        } else if (name[0] == 'Z') {
            zhang++;
        } else if (name[0] == 'F') {
            fu++;
        }
    }
    
    printf("Li:%d\n", li);
    printf("Zhang:%d\n", zhang);
    printf("Fu:%d\n", fu);

}

