#include <stdio.h>
#include <string.h>

void playing(char keyword[6]);

int main(){

    FILE *file = fopen("key.txt", "r");

    char keyword[6];
    fscanf(file, "%s", keyword);

    int choice;

    do{
        puts("====================");
        puts(" ");
        puts("    Wordle Game");
        puts(" ");
        puts("====================");
        puts(" ");

        puts("1. Play");
        puts("2. Rules");
        puts("3. Exit");

        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                playing(keyword);
                break;
            case 2:
                puts("Rules!\n");
                puts("1. The answer is a 5 letter word stored in key.txt.");
                puts("2. You have 5 tries to guess the word.");
                puts("3. You will be given a hint after each guess.");
                puts("4. If your guessed letter is in the correct position, the * will be replaced with corresponding letter");
                puts("5. If your guessed letter is in the word but not in the correct position, the * will change to !.");
                puts("6. If your guessed letter is not in the word, the * will remain as is.");
                break;
            case 3:
                puts("Thank you for playing!");
                break;
            default:
                puts("Invalid Choice");
                break;
        }

    } while(choice != 3);

    return 0;
}

void playing(char keyword[6]){
    char answer[6];

    for(int i = 0; i < 5; i++){
        char check[6] = "*****";

        do{
            printf("Guess %d: ", i+1);
            scanf("%s", answer);
            strupr(answer);

            if(strlen(answer) != 5){
                puts("The answer is a 5 letter word.");
            }   
        } while(strlen(answer) != 5);

        if(strcmp(answer, keyword) == 0){
            puts("Congratulations! You guessed the word!");
            printf("The word is %s\n", keyword);
            break;
        }

        for(int j = 0; j < 5; j++){
            if(answer[j] == keyword[j]){
                check[j] = answer[j];
            }
            else if(strchr(keyword, answer[j]) != NULL){
                check[j] = '!';
            }
        }

        printf("Hint: %s\n", check);
    }

    if(strcmp(answer, keyword) != 0){
        puts("You ran out of tries!");
        printf("The word is %s\n", keyword);
        puts("Better luck next time!");
    }

    puts(" ");

    return;
}