#include <stdio.h>

int main(){

    int num;
    char letter = 'A';
    int count = 1;

    scanf("%d", &num);

    for(int i = 1; i <= num; i++){
        for(int j = num; j > i; j--){
            printf(" ");
        }
        for(int k = 1; k <= count; k++){
            printf("%c", letter);
            if(k < count){
                printf(" ");
            }
        }
        printf("\n");
        letter++;
        count++;

        if(letter > 'Z'){
            letter = 'A';
        }
    }

    return 0;
}