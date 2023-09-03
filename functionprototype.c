#include <stdio.h>

/* 
Function declaration, w/o a body, before main()
Ensure that calls to a function are made w the correct arguments
*/

void hello(char[], int);

int main(){

    char name[] = "bap";
    int age = 18;

    hello(name, age);

    return 0;
}

void hello(char name[], int age){
    printf("\nHello %s", name);
    printf("\nYou're %d years old", age);
}