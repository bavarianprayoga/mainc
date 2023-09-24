#include <stdio.h>

//* circumference generator >D

int main(){

    const double PI = 3.14159;
    double rad;
    double circum;
    double area;

    printf("Enter the radius of a circle: ");
    scanf("%lf", &rad);

    circum = 2 * PI * rad;
    area = PI * rad * rad;

    printf("\nCircumference: %lf", circum);
    printf("\nArea: %lf", area);

    return 0;
}