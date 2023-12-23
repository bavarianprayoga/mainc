#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Bavarian Endra Prayoga
//2702344280
//LN01
//AOL Algoprog Sem 1

void reverse(char text[]){
    int len = strlen(text);
    for(int i = 0; i < len / 2; i++){
        char temp = text[i];
        text[i] = text[len - i - 1];
        text[len - i - 1] = temp;
    }
}

int main(){

    char text[100];
    scanf(" %[^\n]", text);

    for(int i = 0; i < strlen(text); i++){
        if(isalpha(text[i])){
            if(isupper(text[i])){
                text[i] = tolower(text[i]);
            }else{
                text[i] = toupper(text[i]);
            }
        }
    }

    reverse(text);

    printf("%s\n", text);

    return 0;
}