#include <stdio.h>
#include <string.h>

int main(){

    char string1[] = "Yellow", string2[] = "Prius";

    //strlwr(string1);                              // convert ke lowercase
    //strupr(string1);                              // convert ke uppercase
    //strcat(string1, string2);                     // gabungin string2 ke akhir dr string1
    //strncat(string1, string2, 2);                 // gabungin string 2 ke akhir dr string1 sebanyak n huruf pertama
    //strcpy(string1, string2);                     // copy string2 ke string1
    //strncpy(string1, string2, 3);                 // copy sebanyak n huruf pertama dr string2 ke string1

    //strset(string1, '?');                         // ganti semua karakter dari string1 ke karakter yang kita mau
    //strnset(string1, 'x', 1);                     // ganti sebanyak n karakter pertama dari string1 ke karakter yang kita mau
    //strrev(string1);                              // reverse isi string

    //int result = strlen(string1);                 // ubah panjang string jadi integer
    //int result = strcmp(string1, string2);        // compare string, kalo sama hasilnya 0
    //int result = strcmpi(string1, string2);       // sama, cuma ignore case
    //int result = strncmp(string1, string2, 1);    // compare string sebanyak n karakter
    //int result = strnicmp(string1, string2, 1);   // sama, cuma ignore case

    printf("%s", string1);

    return 0;
}