#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char text[1000];
    char vowels[] = "aeiou";
    char consonants[] = "bcdfghjklmnpqrstvwxyz";

    scanf(" %[^\n]", text);  // Notice the space before %[^\n] to consume any leading whitespace.

    int distinctVowels = 0;
    int distinctConsonants = 0;

    // Arrays to keep track of seen vowels and consonants
    int isVowel[26] = {0};
    int isConsonant[26] = {0};

    // Iterate through the input text and process each character
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = tolower(text[i]);  // Convert to lowercase for case insensitivity

        if (ch >= 'a' && ch <= 'z') {
            if (strchr(vowels, ch) != NULL) {
                if (!isVowel[ch - 'a']) {
                    isVowel[ch - 'a'] = 1;
                    distinctVowels++;
                }
            } else if (strchr(consonants, ch) != NULL) {
                if (!isConsonant[ch - 'a']) {
                    isConsonant[ch - 'a'] = 1;
                    distinctConsonants++;
                }
            }
        }
    }

    // Print the results
    printf("Vocal: %d\n", distinctVowels);
    printf("Consonant: %d\n", distinctConsonants);

    return 0;
}
