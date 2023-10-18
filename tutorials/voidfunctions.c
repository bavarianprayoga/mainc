#include <stdio.h>

void bday(char name[], int age); 
    /*  
    function protoype, gunanya buat mastiin kalo requirementnya udah terpenuhi semua (in this case it's name and age)
    kalo gapake ini, misal kita cuma masukin nama, nanti agenya jadi ngaco dan bukan muncul error.
    note: ini cuma berlaku kalo functionnya ada sesudah main
    */

int main(){

    char name[] = "bap";
    int age = 18;

    bday(name, age);

    return 0;
}

void bday(char name[], int age){
    printf("\nHappy Birthday, %s", name);
    printf("\nYou're now %d years old.", age);
}