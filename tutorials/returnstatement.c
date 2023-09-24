#include <stdio.h>

double cubic(double a){
    return a * a * a;
    //* nama parameter boleh beda yg penting data typenya sama
}

int main(){

    double x = cubic(3.14);
    printf("%lf", x);

    return 0;
}