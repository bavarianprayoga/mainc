#include <stdio.h>  

int main(){  

    int a[4], b[4], c[4], d[4]; 
    double sum[4];

    for(int i = 0; i < 3; i++){
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
        a[i] *= 2;
        b[i] *= 2;
        c[i] *= 2;
        sum[i] = (double)a[i] + b[i] + c[i] +d[i];
    }

    for(int i = 0; i < 3; i++){
        printf("%.2lf\n", sum[i]);
    }


    return 0;
}