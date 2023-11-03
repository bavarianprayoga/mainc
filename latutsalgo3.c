#include <stdio.h>
#include <math.h>

int main(){
    
    int t;
    scanf("%d", &t);

    int bulan[t], bunga[t];
    long long int uang[t];

    for(int i = 0; i < t; i++){
        scanf("%lld %d %d", &uang[i], &bunga[i], &bulan[i]);

        printf("Case #%d:\n", i+1);
        for(int j = 0; j < bulan[i]; j++){
            uang[i] += floor(uang[i] * ((bunga[i]/100.0) / 12) * 0.8);
            printf("%d %lld\n", j + 1, uang[i]);
        }
    }

    return 0;
}

