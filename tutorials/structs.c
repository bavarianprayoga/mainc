#include <stdio.h>
#include <string.h>

// struct Player{
//     char name[12];
//     int score;
// };
// ini kalo ga pake typedef

typedef struct{
    char name[12];
    int score;
} Player;
//typedef buat ngasih nickbname ke datatype

int main(){

    // struct Player player1;
    // struct Player player2;

    Player player1;
    Player player2;
    //typedefnya 'Player' jd gausa ngasih struct diawal

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