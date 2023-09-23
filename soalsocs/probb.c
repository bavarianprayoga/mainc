#include <stdio.h>

int main(){

    int a, b, c;

    scanf("%d", &a);

    b = a + a;
    c = b - 1;

    printf("%d plus %d is %d\n", a, a, b);
    printf("minus one is %d\n", c);

    return 0;
}