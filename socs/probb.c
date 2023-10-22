#include <stdio.h>
#include <string.h>

int main() {
    char text[1000];
    char vowels[] = "aeiou";
    char consonants[] = "bcdfghjklmnpqrstvwxyz";

    int vow = 0;
    int con = 0;
    
    int vowcount[26] = {0};
    int concount[26] = {0};

    scanf(" %[^\n]", text);

    for (int i = 0; text[i] != '\0'; i++) {
        char x = text[i];

        if (strchr(vowels, x) != NULL) {
            if (!vowcount[x - 'a']) {
                vowcount[x - 'a'] = 1;
                vow++;
            }
        } else if (x != ' ') {
            if (!concount[x - 'a']) {
                concount[x - 'a'] = 1;
                con++;
            }
        }
    }

    printf("Vocal: %d\n", vow);
    printf("Consonant: %d\n", con);

    return 0;
}