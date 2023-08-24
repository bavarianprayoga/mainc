#include <stdio.h>
#include <math.h>

//*hypotenuse generator >D

int main(){

    double height;
    double base;
    double hypotenuse;

    printf("Enter the base of the triangle: ");
    scanf("%lf", &base);

    printf("Enter the height of the triangle: ");
    scanf("%lf", &height);

    hypotenuse = sqrt(pow(height, 2) + pow(base, 2));

    printf("\nThe hypotenuse is: %lf\n", hypotenuse);

    system("pause");
    return 0;
}