#include <stdio.h>

//* Functions and arguments
// void bday(char name[], int age){
//     printf("\nHappy birthday %s!", name);
//     printf("\nYou're now %d years old.", age);
// }

//  int main(){

    // char name[] = "bap";
    // int age = 18;

    // bday(name, age);

//     return 0;
// }

//* Return statement
double cubed(double x){
    return x * x * x; 
    /*
    return buat balikin ke function tempat dia dipanggil
    bisa juga kayak gini:
    double result = x * x * x;
    return result;
    */
}

int main(){

    double x = cubed(9);
    printf("%.2lf", x);

    return 0;
}