#include <stdio.h>

void bday(char name[], int age){
    printf("\nHappy Birthday, %s", name);
    printf("\nYou're now %d years old.", age);
}

int main(){

    char name[] = "bap";
    int age = 18;

    bday(name, age);

    return 0;
}