#include <stdio.h>

int main(){

    int n, fren, a, b;

    scanf("%d", &n);

    int vid[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &vid[i]);
    }

    scanf("%d", &fren);
    getchar();
    
    int sum[fren];

    for(int i = 0; i < fren; i++){
        scanf("%d %d", &a, &b);
        getchar();
        for(int j = a - 1; j < b; j++){
            sum[i] += vid[j];
        }
    }

    for(int i = 0; i < fren; i++){
        printf("Case #%d: %d\n", i+1, sum[i]);
    }
    

    return 0;
}