#include <stdio.h>
#include <string.h>

struct Student {
    char id[10];
    char name[50];
    int grade1, grade2, grade3;
    int total;
};

int main() {
    int n;
    scanf("%d", &n);
    
    struct Student students[n];
    struct Student *max_student = &students[0];
    
    int sum1 = 0, sum2 = 0, sum3 = 0;

    for (int i = 0; i < n; i++) {
        scanf("%s %s %d %d %d", 
              students[i].id,
              students[i].name, 
              &students[i].grade1, 
              &students[i].grade2, 
              &students[i].grade3);

        sum1 += students[i].grade1;
        sum2 += students[i].grade2;
        sum3 += students[i].grade3;

        students[i].total = students[i].grade1 + students[i].grade2 + students[i].grade3;

        if (i == 0 || students[i].total > max_student->total) {
            max_student = &students[i];
        }
    }

    printf("%d %d %d\n", sum1/n, sum2/n, sum3/n);

    printf("%s %s %d %d %d\n", 
           max_student->id,
           max_student->name,
           max_student->grade1,
           max_student->grade2,
           max_student->grade3);
    
    return 0;
}
