#include <stdio.h>
#include <string.h>

struct Player{
    char name[12];
    int score;
};

int main(){

    struct Player player1;
    struct Player player2;

    strcpy(player1.name, "bap");
    //pake strcpy kalo mau ganti value string di struct
    player1.score = 7;

    strcpy(player2.name, "yanto");
    player2.score = 8;

    printf("Player one: %s\n", player1.name);
    printf("Score: %d\n", player1.score);
    
    printf("Player two: %s\n", player2.name);
    printf("Score: %d\n", player2.score);

    return 0;
}