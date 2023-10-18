#include <stdio.h>

int main(){

    int n;

    scanf("%d", &n);

    int a[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    int b[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &b[a[i]]);
    }

    for(int i = 0; i < n; i++){
        printf("%d ", &b[a[i]]);
    }

    return 0;
}