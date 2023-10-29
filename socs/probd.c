#include <stdio.h>
#include <math.h>

int square(int num){
    int root = (int)sqrt(num);
    return root * root == num;
}

int cubic(int num){
    int cube = (int)cbrt(num);
    return cube * cube * cube == num;
}

int prime(int num){
    if(num <= 1) return 0;
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){

    int cases;
    scanf("%d", &cases);
    getchar();

    for(int i = 0; i < cases; i++){
        int num;
        scanf("%d", &num);
        getchar();

        int isPrime = prime(num);
        int isSquare = square(num);
        int isCubic = cubic(num);

        printf("Case #%d : ", i+1);

        if(isPrime){
            printf("prime");
            if (isSquare || isCubic){
                printf(" ");
            }
        }

        if(isSquare == 1){
            printf("square");
            if (isCubic){
                printf(" ");
            }
        }

        if(isCubic == 1){
            printf("cubic");
        }

        if(!isPrime && !isSquare && !isCubic){
            printf("none");
        }

        printf("\n");
    }

    return 0;
}