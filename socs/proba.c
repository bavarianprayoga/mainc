#include <stdio.h>
#include <string.h>

void revv(char s[], int j, int k){
    if (j >= k) return;
    
    char temp = s[j];
    s[j] = s[k];
    s[k] = temp;

    revv(s, j+1, k-1);
}

void print(char s[][1000], int t){
    for(int i = 0; i < t; i++){
        int j = 0;
        int k = strlen(s[i]) - 1;

        revv(s[i], j, k);
        printf("Case #%d: %s\n", i+1, s[i]); 
    }
}

int main(){

    int t;

    scanf("%d", &t);
    getchar();
    
    char s[t][1000];

    for(int i = 0; i < t; i++){
        scanf("%[^\n]", s[i]);
        getchar();
    }

    print(s, t);

    return 0;
}