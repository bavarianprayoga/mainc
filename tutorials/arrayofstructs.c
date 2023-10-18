#include <stdio.h>

typedef struct student{
    char name[25];
    float gpa;
} student;

int main(){

    student student1 = {"bap", 4.0};
    student student2 = {"flora", 3.8};
    student student3 = {"gebi", 3.5};
    student student4 = {"muchang", 3.6};

    student students[] = {student1, student2, student3, student4};

    for(int i = 0; i < sizeof(students)/sizeof(students[0]); i++){
        printf("%-12s\t", students[i].name);
        printf("%.2f\n", students[i].gpa);
    }

    return 0;
}