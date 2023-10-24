#include <stdio.h>

int main(){

    int n, value;
    scanf("%d", &n);
    getchar();

    int num[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
        getchar();
    }
    
    scanf("%d", &value);

    for(int i = 0; i < n; i++){
        if(num[i] <= value){
            printf("%d,", num[i]);
        }
    }
    printf("\n");

    return 0;
}