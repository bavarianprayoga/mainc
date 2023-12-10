#include <stdio.h>
#include <string.h>

int main(){

    int t;
    scanf("%d", &t);
    getchar();
    char text[t][1500];

    for(int i = 0; i < t; i++){
        scanf(" %[^\n]", text[i]);
        getchar();
    }

    for(int i = 0; i < t; i++){
        printf("Case #%d: ", i+1);
        for(int j = 0; j < strlen(text[i]); j++){
            if(text[i][j] != 'A' && text[i][j] != 'I' && text[i][j] != 'U' && text[i][j] != 'E' && text[i][j] != 'O' && text[i][j] != 'a' && text[i][j] != 'i' && text[i][j] != 'u' && text[i][j] != 'e' && text[i][j] != 'o'){
                printf("%c", text[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}