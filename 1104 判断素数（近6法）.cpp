#include<stdio.h>
#include<math.h>
bool is_Prime(int num)
{
    if (num == 2 || num == 3)
        return true;
 
    if (num % 6 != 1 && num % 6 != 5)
        return false;
}
int main()
{    
    int i,num;
   
    for (i = 2; i*i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }

    return true;
}

