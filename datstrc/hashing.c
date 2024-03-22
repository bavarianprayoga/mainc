#include <stdio.h>
#include <string.h>
#define MAX 10

char array[MAX][MAX];

void init(){
    for(int i = 0; i < MAX; i++){
        strcpy(array[i], "");
    }
}

int hash(char *str){
    return str[0] - 'A';
}

void insert(char *str){
    int index = hash(str);

    for(int i = index; i < MAX; i++){
        if(strcmp(array[i], "") == 0){
            strcpy(array[i], str);
            return;
        }
    }
}

int main(){

    //Dewi, Fendy, Eko, Cici, Alam, Ceki, Alex, Fahmi
    //Hash relies on the first character of the string

    init();

    insert("Dewi");
    insert("Fendy");
    insert("Eko");
    insert("Cici");
    insert("Alam");
    insert("Ceki");
    insert("Alex");
    insert("Fahmi");

    for(int i = 0; i < MAX; i++){
        printf("%s\n", array[i]);
    }



    return 0;
}