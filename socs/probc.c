#include <stdio.h>
#include <string.h>

typedef struct{
    char shrt[100];
    char ori[100];
} dict;

int main(){

    dict kamus[100];

    FILE *file = fopen("testdata.in", "r");

    int size;
    fscanf(file, "%d\n", &size);

    for(int i = 0; i < size; i++){
        fscanf(file, "%[^#]#%s\n", kamus[i].shrt, kamus[i].ori);
    }

    int t;
    fscanf(file, "%d\n", &t);

    for(int i = 0; i < t; i++){
        char sentence[size + 1][101];
        fscanf(file, "%[^\n]\n", sentence[i]);

        char* word = strtok(sentence[i], " ");

        int panjang = 0;
        while(word != NULL && panjang < 101){
            strcpy(sentence[panjang], word);
            word = strtok(NULL, " ");
            panjang++;
        }

        printf("Case #%d:\n", i+1);
        for(int j = 0; j < panjang; j++){
            int found = 0;
            for(int k = 0; k < size; k++){
                if(strcmp(sentence[j], kamus[k].shrt) == 0){
                    printf("%s", kamus[k].ori);
                    found = 1;
                    break;
                }
            }
        
            if(found == 0){
                printf("%s", sentence[j]);
            }
            if(j != panjang - 1){
                printf(" ");
            }
        }
        printf("\n");

    }

    fclose(file);

    return 0;
}
