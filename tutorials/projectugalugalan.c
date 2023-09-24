#include <stdio.h>

int main(){

    char unit;
    float temp;

    printf("Is the temperature in (F) or (C)? ");
    scanf("%c", &unit);

    if(unit == 'C' || unit == 'c'){
        printf("Enter the temperature in Celcius: ");
        scanf("%f", &temp);
        temp = (temp * 9 / 5) + 32;
        printf("The temperature in Fahrenheit is %.1f", temp);
    }
    else if(unit == 'F' || unit == 'f'){
        printf("Enter the temperature in Fahrenheit: ");
        scanf("%f", &temp);
        temp = ((temp - 32) * 5) / 9;
        printf("The temperature in Celcius is %.1f", temp);
    }
    else{
        printf("yang bener lah su");
    }
    
    return 0;
}