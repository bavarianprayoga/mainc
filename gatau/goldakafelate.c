#include <stdio.h>
#include <string.h>

int main() {
    FILE *file = fopen("testdata.in", "r");

    int t;
    fscanf(file, "%d\n", &t);

    for(int i = 0; i < t; i++){
        char x[100];
        fscanf(file, "%s\n", x);

        int n;
        fscanf(file, "%d\n", &n);

        char mapping[26];
        for(int j = 0; j < 26; j++){
            mapping[j] = 'A' + j;
        }
        
        for(int j = 0; j < n; j++){
            char fix, rep;
            fscanf(file, "%c %c\n", &fix, &rep);
            mapping[fix - 'A'] = rep;
        }

        int count[26] = {0};
        for(int j = 0; j < strlen(x); j++){
            count[mapping[x[j] - 'A'] - 'A']++;
        }

        for(char c = 'A'; c <= 'Z'; c++){
            if(count[c - 'A'] > 0){
                printf("%c %d\n", c, count[c - 'A']);
            }
        }
    }

    fclose(file);
    return 0;
}
