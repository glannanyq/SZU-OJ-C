#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float grade1, grade2, grade3;
    float aver;
};

int main() {
    int n;
    scanf("%d", &n);
    
    struct Student students[n];
    struct Student *max_student = &students[0];

    for (int i = 0; i < n; i++) {
        scanf("%d %s %f %f %f", 
        	&students[i].id, 
            students[i].name, 
            &students[i].grade1, 
            &students[i].grade2, 
            &students[i].grade3);

        students[i].aver = (students[i].grade1 + students[i].grade2 + students[i].grade3) / 3.0;

        if (i == 0 || students[i].aver > max_student->aver) {
            max_student = &students[i];
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d %s %.2f %.2f %.2f %.2f\n", 
            students[i].id,
            students[i].name,
            students[i].grade1,
            students[i].grade2,
            students[i].grade3,
            students[i].aver);
    }

    printf("%s %.2f\n", 
           max_student->name, 
           max_student->aver);
    
    return 0;
}
