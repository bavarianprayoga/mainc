#include <stdio.h>

int main(){

    int T;
    double tot;

    scanf("%d", &T);

    int A[T];
    unsigned long long int B[T];

    for(int i=0; i<T; i++){
        scanf("%d %llu", &A[i], &B[i]);
    }

    for(int i=0; i<T; i++){
        tot = A[i] * B[i] / 360.0;
        printf("%.2lf\n", tot);
    }
        
        return 0;
}