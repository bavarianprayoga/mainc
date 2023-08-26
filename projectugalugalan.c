#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

    double T; //temperature
    char type; //temperature type (C, F)
    double convt; //converted temperature
    
    printf("THE TEMPERATER");
    printf("\nEnter the temperature: ");
    scanf("%lf", &T);
    getchar();

    printf("\nIs the temperature in C? (y/n) ");
    scanf("%c", &type);

    if(type == 'y' || type == 'Y'){
        convt = (9 / 5 * T) + 32;
        printf("The temperature is %.2lfF\n\n", convt);
    }
    else if(type == 'n' || type == 'N'){
        convt = (T - 32) * 5 / 9;
        printf("The temperature is %.2lfC\n\n", convt);
    }
    else{
        printf("yang bener lah su\n\n");
    }

    system("pause");
    return 0;
}