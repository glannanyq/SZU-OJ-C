#include <stdio.h>

int main() 
{
    for (char who = 'A'; who <= 'D'; ++who) {
      
        int a = (who != 'A');

        int b = (who == 'C');

        int c = (who == 'D');

        int d = (who != 'D');

        int truths = a + b + c + d;
        
        if (truths == 3) {
            printf("%c\n", who);
            break;
        }
    }
}
