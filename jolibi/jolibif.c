#include <stdint.h>
#include <stdio.h>

int main(){

    uint32_t a, b;
    uint64_t result;

    scanf("%u %u", &a, &b);

    result = (uint64_t)a * b ;

    printf("%llu\n", result);

    return 0;
}