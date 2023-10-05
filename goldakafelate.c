#include <stdio.h>  

int main(){  

    // char board[39];
    int numthrow, dice;
    int pos = 0;

    scanf("%d", &numthrow);

    for(int i = 0; i < numthrow; i++){
        scanf("%d", &dice);
        pos += dice;
        if(pos >= 40){
            pos -= 40;
        }
        else if(pos == 12){
            pos = 28;
        } 
        else if (pos == 35){
            pos = 7;
        } 
        else if (pos == 30){
            pos = 10;
        }
    }

    printf("%d\n", pos);

    return 0;
}