#include <stdio.h>
#include <string.h>

void bubble(char title[101][1001], int views[], int size){
    int swapped;
    do{
        swapped = 0;
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size - i - 1; j++){
                if(views[j] < views[j+1] || (views[j] == views[j+1] && strcmp(title[j], title[j+1]) > 0)){
                    int temp = views[j];
                    views[j] = views[j+1];
                    views[j+1] = temp;

                    char temp2[101][1001];
                    strcpy(temp2[j], title[j]);
                    strcpy(title[j], title[j+1]);
                    strcpy(title[j+1], temp2[j]);

                    swapped = 1;
                }
            }
        }
    } while(swapped == 1);
    
}

int main(){

    FILE *file = fopen("testdata.in", "r");

    char title[101][1001];
    char name[101][1001];
    int views[101];

    int idx = 0;

    while(fscanf(file, "%[^#]#%[^#]#%d\n", title[idx], name[idx], &views[idx]) != EOF){
        idx++;
    }

    for(int i = 0; i < idx; i++){
        strcat(title[i], " by ");
        strcat(title[i], name[i]);
    }

    bubble(title, views, idx);

    for(int i = 0; i < idx; i++){
        printf("%s - %d\n", title[i], views[i]);
    }

    fclose(file);

    return 0;
}