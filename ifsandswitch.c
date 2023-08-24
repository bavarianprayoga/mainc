#include <stdio.h>

int main(){

    // int age;

    // printf("Enter your age: ");
    // scanf("%d", &age);

    // if(age >= 18, age < 80){
    //     printf("congrats, you can suffer alone.");
    // }
    // else if(age >= 80){
    //     printf("better write your will");
    // }
    // else if(age < 0){
    //     printf("dumbass");
    // }
    // else{
    //     printf("get outta here");
    // }

    //* daripada pake banyak else if, mending pake switch, Tapi, switch cuma bisa exact comparison.

    int grade;

    printf("Enter your letter grade: ");
    scanf("%s", &grade);
    
    switch(grade){
        case 'A':
            printf("weelll");
            break;
        case 'B':
            printf("mantep");
            break;
        case 'C':
            printf("mayan");
            break;
        case 'D':
            printf("yauda la ya");
            break;
        case 'F':
            printf("goblok");
            break;
        default:
            printf("yang bener lah anjg");
    }


    return 0;
}