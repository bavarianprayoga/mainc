#include <stdio.h>

int main(){

    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    if(age >= 18, age < 80){
        printf("congrats, you can suffer alone.");
    }
    else if(age >= 80){
        printf("better write your will");
    }
    else if(age < 0){
        printf("dumbass");
    }
    else{
        printf("get outta here");
    }

    return 0;
}