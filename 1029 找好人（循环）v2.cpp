#include <stdio.h>

int main() {
    for (char who = 'A'; who <= 'D'; who++) {
        int truths = 0;

        if ((who != 'A') == 1) {
            truths++;
        }

        if ((who == 'C') == 1) {
            truths++;
        }

        if ((who == 'D') == 1) {
            truths++;
        }
        
        if ((who != 'D') == 1) {
            truths++;
        }
        
        if (truths == 3) {
            printf("%c\n", who);
            break;
        }
    }
}
