#include <stdio.h>
#include <ctype.h>

int main(){  

    char vow;

    scanf("%c", &vow);

    vow = toupper(vow);

    if(vow == 'A' || vow == 'I' || vow == 'U' || vow == 'E' || vow == 'O'){
        printf("%c is a vowel\n", vow);
    }
    else{
        printf("%c is not a vowel\n", vow);
    }

    return 0;
}
