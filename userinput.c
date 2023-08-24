#include <stdio.h>
#include <string.h> //input ini biar bisa pake strlen

int main(){

    char name[50];  //bytes
    int age;

    printf("What's your name? ");
    //scanf("%s", &name); //pake '&' buat nandain itu userinput. scanf ga bisa baca spasi, cuma baca kata pertama aja
    fgets(name, 50, stdin); //fgets biar bisa ngurusin spasi. 'nama variable', 'batas byte(samain ama variablenya aja), 'stdin(std input)'
    name[strlen(name)-1]='\0';  //biar ga error pas output di namanya. kalo ga pake ini nanti bakal bikin line baru setelah output namanya.
    //*kalo udah pake strlen gausa pake scanf

    printf("How old are you? ");
    scanf("%d", &age);

    printf("\nHello, %s\n", name);
    printf("You're %d years old\n", age);
    printf("%s is a funny name", name);



    return 0;
}