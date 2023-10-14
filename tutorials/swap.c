#include <stdio.h>

int main(){

    // char x = 'x';
    // char y = 'y';
    // char temp;

    // temp = x;
    // x = y;
    // y = temp;

    //kalo string

    char x[15] = "parafin";
    char y[15] = "petrus";
    char temp[15];

    strcpy(temp, x);
    strcpy(y, x);
    strcpy(temp, y);


    return 0;
}