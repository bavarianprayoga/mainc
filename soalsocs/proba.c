#include <stdio.h>
#include <math.h>

int main(){

    double base, interest, final;

    scanf("%lf %lf", &base, &interest);

    interest = (interest/100);
    final = base*(pow(interest + 1, 3));

    printf("%.2lf\n", final);

    return 0;
}