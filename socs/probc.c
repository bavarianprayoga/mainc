#include <stdio.h>

int main(){

    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        int n;
        scanf("%d", &n);

        int table[n][n];
        int sum[n];

        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                scanf("%d", &table[j][k]);
            }
        }

        for(int l = 0; l < n; l++){
            sum[l] = 0;
            for(int m = 0; m < n; m++){
                sum[l] += table[m][l];
            } 
        }

        printf("Case #%d: ", i+1);
        for(int o = 0; o < n - 1; o++){
            printf("%d ", sum[o]);
        }
        printf("%d\n", sum[n - 1]);
    }



    return 0;
}