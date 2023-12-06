#include <stdio.h>
#include <string.h>

int main(){
    
    FILE *file = fopen("testdata.in", "r");

    int t;
    fscanf(file, "%d\n", &t);

    for(int i = 0; i < t; i++){
        char str[100];
        fscanf(file, "%s\n", str);

        int pcs;
        fscanf(file, "%d\n", &pcs);
        
        char change[26][2];
        int freq[26] = {0};

        for(int j = 0; j < pcs; j++){
            fscanf(file, "%c %c\n", &change[j][0], &change[j][1]);
        }

        for(int j = 0; j < strlen(str); j++){
            freq[str[j] - 'A']++;
        }

        for(int j = 0; j < pcs; j++){
            freq[change[j][1] - 'A'] += freq[change[j][0] - 'A'];
            freq[change[j][0] - 'A'] = 0;
        }

        for(int j = pcs - 1; j >= 0; j--){
            printf("%c %d\n", change[j][1], freq[change[j][1] - 'A']);
        }


    }

    return 0;
}
