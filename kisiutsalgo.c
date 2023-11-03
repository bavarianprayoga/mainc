#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *suffix(int suf){
    switch(suf){
        case 1: return "st";
        case 2: return "nd";
        case 3: return "rd";
        default: return "th";
    }
}

void uname(char username[][50], int user, int i){
    printf("Input the %d%s username: ", i + 1, suffix(i+1));
    scanf("%[^\n]", &username[i]);
    getchar();
}

void passConvert(char password[][50], int user, int i){
    printf("Converting password...\n");
    for (int j = 0; password[i][j] != '\0'; j++) {
        if(password[i][j] == 'A' || password[i][j] == 'a'){
            password[i][j] = '@';
        } 
        else if (password[i][j] == 'B' || password[i][j] == 'b'){
            password[i][j] = '8';
        }
        else if (password[i][j] == 'E' || password[i][j] == 'e'){
            password[i][j] = '3';
        }
        else if (password[i][j] == 'G' || password[i][j] == 'g'){
            password[i][j] = '9';
        }
        else if (password[i][j] == 'I' || password[i][j] == 'i'){
            password[i][j] = '1';
        }
        else if (password[i][j] == 'O' || password[i][j] == 'o'){
            password[i][j] = '0';
        }
        else if (password[i][j] == 'S' || password[i][j] == 's'){
            password[i][j] = '$';
        }
        else if (password[i][j] == 'T' || password[i][j] == 't'){
            password[i][j] = '7';
        }
    }
    
    int len = strlen(password[i]);
    password[i][0] = toupper(password[i][0]);
    password[i][len-1] = toupper(password[i][len-1]);

    for(int j = 1; j < len - 1; j++){
        password[i][j] = tolower(password[i][j]);
    }

    if(len < 49){
        password[i][len] = '!';
        password[i][len + 1] = '\0';
    }
    
    printf("This is the %d%s user new password: %s\n", i + 1, suffix(i+1), password[i]);
}

void pass(char password[][50], int user, int i){
    do{
        printf("Please input the %d%s user password[min. 5 characters]: ", i + 1, suffix(i+1));
        scanf("%[^\n]", &password[i]);
        getchar();
    } while(strlen(password[i]) < 5);
    passConvert(password, user, i);
}

void newPass(char password[][50], char newPassword[][50], int user, int i){
    do{
        printf("Please re-type the %d%s user password: ", i + 1, suffix(i+1));
        scanf("%[^\n]", &newPassword[i]);
        getchar();
    } while(strcmp(password[i], newPassword[i]) != 0);
}

void mailCheck(char email[][50], int user, int i){
    int cek = 0;

    do{
        printf("Please input the %d%s user email[ends with @gmail.com or @yahoo.com]: ", i + 1, suffix(i+1));
        scanf("%[^\n]", &email[i]);
        getchar();
        
        int len = strlen(email[i]);
        if(len >= 10 && (strstr(email[i] + len - 10, "@gmail.com") == email[i] + len - 10 || strstr(email[i] + len - 10, "@yahoo.com") == email[i] + len - 10)){
            cek = 1;
        }

    } while(cek == 0);
    
}

int main(){

    int user;

    do{
        printf("Input max user [3-10]: ");
        scanf("%d", &user);
        getchar();
    } while(user < 3 || user > 10);

    char username[user][50];
    char password[user][50];
    char newPassword[user][50];
    char email[user][50];

    for(int i = 0; i < user; i++){
        uname(username, user, i);
        pass(password, user, i);
        newPass(password, newPassword, user, i);
        mailCheck(email, user, i);
        printf("Data inputted successfully!\n\n");
    }

    printf("No | Username          | Email\n");
    for(int i = 0; i < user; i++){
        printf("%d  | %-17s | %s\n", i + 1, username[i], email[i]);
    }

    return 0;
}