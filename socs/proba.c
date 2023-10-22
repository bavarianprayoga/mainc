#include <stdio.h>

int main(){

    int n;

    scanf("%d", &n);

    int num[n];
    int srt[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &srt[i]);   
    }

    for(int i = 0; i < n; i++){
        scanf("%d", &num[srt[i]]);
    }

    for(int i = 0; i < n - 1; i++){
        printf("%d ", num[i]);
    }
    printf("%d\n", num[n - 1]);

    return 0;
}