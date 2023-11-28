#include <stdio.h>

int main(){

    int t;
    int n;

    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        scanf("%d", &n);

        long long int table[n][n];
        long long int total[n];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%lld", &table[i][j]);
            }
        }

        for(int j = 0; j < n; j++){
            total[j] = 0;
        }

        for(int j = 0; j < n; j++){
            for(int i = 0; i < n; i++){
                total[j] += table[i][j];
            }
        }

        printf("Case #%d:", i+1);
        for(int i = 0; i < n; i++){
            printf(" %lld", total[i]);
        }
        printf("\n");

    }

    return 0;
}