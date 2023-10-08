#include <stdio.h>

void mult(int a[4], int b[4]){
    for(int i = 0; i < 4; i++){
        printf("%d\n", a[i] * b[i]);
    }
}

int main(){  

    int a[4], b[4];

    for(int i = 0; i < 4; i++){
        scanf("%d %d", &a[i], &b[i]);
    }

    mult(a, b);

    return 0;
}