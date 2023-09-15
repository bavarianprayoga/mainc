#include <stdio.h>

int main(){

    int T;
    
    scanf("%d", &T);

    int K[T], N[T], M[T];

    for(int i=0; i<T; i++){
        scanf("%d %d %d", &K[i], &N[i], &M[i]);
    }
    for(int i=0; i<T; i++){
        if(K[i] <= N[i] + M[i]){
            printf("Case #%d: yes\n", i+1);
        }
        else{
            printf("Case #%d: no\n", i+1);
        }
    }

    return 0;
}