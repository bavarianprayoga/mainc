#include <stdio.h>
#include <string.h>

void bubbleSort(char name[][11], int score[], int n){
    int swapped;
    do{
        swapped = 0;
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - 1 - i; j++){
                if(score[j] < score[j + 1] || (score[j] == score[j + 1] && strcmp(name[j], name[j + 1]) > 0)){
                    int temp = score[j];
                    score[j] = score[j + 1];
                    score[j + 1] = temp;

                    char temp2[11];
                    strcpy(temp2, name[j]);
                    strcpy(name[j], name[j + 1]);
                    strcpy(name[j + 1], temp2);

                    swapped = 1;
                }
            }
        }
    } while(swapped == 1);
}

int linear(char name[][11], int score[], int n, char target[]){
    int idx = -1;
    for(int i = 0; i < n; i++){
        if(strcmp(name[i], target) == 0){
            idx = i;
            break;
        }
    }
    return idx;
}

int main(){

    int t;
    scanf("%d", &t);
    int final[t];

    for(int i = 0; i < t; i++){
        int n;
        scanf(" %d", &n);
        
        char name[n][11];
        int score[n];
        char target[11];

        for(int j = 0; j < n; j++){
            scanf(" %[^#]#%d", name[j], &score[j]);
        }

        bubbleSort(name, score, n);

        scanf(" %s", target);

        final[i] = linear(name, score, n, target) + 1;
    }

    for(int i = 0; i < t; i++){
        printf("Case #%d: %d\n", i+1, final[i]);
    }

    return 0;
}