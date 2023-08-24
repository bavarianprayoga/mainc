#include <stdio.h>

int main(){

    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    if(age >= 18){
        printf("Congrats, you can suffer alone.");
    }
    else if(age < 0){
        printf("dumbass");
    }
    else{
        printf("get outta here");
    }

    return 0;
}