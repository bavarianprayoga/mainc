#include <stdio.h>

int main(){

    int quantity, changes;

    scanf("%d", &quantity);

    long long int items[quantity];

    for(int i = 0; i < quantity; i++){
        scanf("%lld", &items[i]);
    }

    scanf("%d", &changes);

    long long int cases[changes][2];

    for(int i = 0; i < changes; i++){
        scanf("%lld %lld", &cases[i][0], &cases[i][1]);
    }

    for(int i = 0; i < changes; i++){
        items[cases[i][0]-1] = cases[i][1]; 
        printf("Case #%d: ", i+1);

        for(int j = 0; j < quantity-1; j++){
            printf("%lld ", items[j]);
        }
        printf("%lld\n", items[quantity-1]);
    }

    return 0;
}