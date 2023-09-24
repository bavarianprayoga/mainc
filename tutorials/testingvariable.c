#include <stdio.h>

int main(){

    float apel = 5.75;
    float kolor = 99.99;
    const float AKUA = 1.99;

    // const biar value sebuah data ga bisa diubah, kalo diubah bakal error

    printf("Kolor: $%.2f\n", kolor);
    printf("Apel: $%.2f\n", apel);
    printf("Akua: $%.2f\n", AKUA);

    return 0;
}