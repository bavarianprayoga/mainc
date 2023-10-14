#include <stdio.h>

int main(){

    long long int num;

    scanf("%lld", &num);

    if(num % 2 == 0){
        puts("even");
    }
    else{
        puts("odd");
    }

    return 0;
}