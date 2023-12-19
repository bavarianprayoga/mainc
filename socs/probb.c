#include <stdio.h>

void sum(int num[], int n, int index, int curr){
    if(index >= n) return; 

    if(2 * index + 1 >= n && 2 * index + 2 >= n){
        printf("%d\n", curr + num[index]);
    } 
    else{
        sum(num, n, 2 * index + 1, curr + num[index]); 
        sum(num, n, 2 * index + 2, curr + num[index]); 
    }
}

int main(){
    int t, n;
    scanf(" %d", &t);

    for(int i = 0; i < t; i++){
        scanf(" %d", &n);

        int num[n];

        for(int j = 0; j < n; j++){
            scanf(" %d", &num[j]);
        }

        printf("Case #%d:\n", i+1);
        sum(num, n, 0, 0); 
    }

    return 0;
}

