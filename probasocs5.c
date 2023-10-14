#include <stdio.h>

int main(){

    int t;
    
    scanf("%d", &t);

    long long int n[t], m[t], sum[t], k;

    for(int i = 0; i < t; i++){
        scanf("%lld %lld", &n[i], &m[i]);
        sum[i] = 0;
    
        for(int j = 0; j < n[i]; j++){
            scanf("%lld", &k);
            sum[i] += k;
        }
    }
    for(int i = 0; i < t; i++){
        if(sum[i] <= m[i]){
            printf("Case #%d: No worries\n", i+1);
        }
        else{
            printf("Case #%d: Wash dishes\n", i+1);
        }
    }

    return 0;
}