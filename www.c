#include <stdio.h>
#include <string.h>

typedef struct{
    char name[50];
    int age;
} student;

int main(){

    student student1;

    printf("Enter name: ");
    scanf("%s", student1.name);
    printf("Enter age: ");
    scanf("%d", &student1.age);

    printf("Name: %s\n", student1.name);
    printf("Age: %d\n", student1.age);
        student student2;
        strcpy(student2.name, "John");
        student2.age = 20;

        printf("Name: %s\n", student2.name);
        printf("Age: %d\n", student2.age);

        student student3;
        strcpy(student3.name, "Jane");
        student3.age = 22;

        printf("Name: %s\n", student3.name);
        printf("Age: %d\n", student3.age);

        student student4;
        strcpy(student4.name, "Mike");
        student4.age = 19;

        printf("Name: %s\n", student4.name);
        printf("Age: %d\n", student4.age);

        student student5;
        strcpy(student5.name, "Emily");
        student5.age = 21;

        printf("Name: %s\n", student5.name);
        printf("Age: %d\n", student5.age);

        return 0;
}