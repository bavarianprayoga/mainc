#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    char s[n];
    scanf("%s", s);

    for(int i = 0; i < n; i++){
        printf("%s\n", s);
    }

    return 0;
}