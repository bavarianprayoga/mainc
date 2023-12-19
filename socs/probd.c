#include <stdio.h>
#include <string.h>

int main(){

    FILE *file = fopen("testdata.in", "r");

    int t;
    fscanf(file, "%d", &t);

    for(int i = 0; i < t; i++){
        int size, time;
        fscanf(file, "%d %d", &size, &time);

        char field[size][size];
        char tempField[size][size];

        for(int j = 0; j < size; j++){
            for(int k = 0; k < size; k++){
                fscanf(file, " %c", &field[j][k]);
                tempField[j][k] = field[j][k];
            }
        }

        for(int x = 1; x < time; x++){
            for(int j = 0; j < size; j++){
                for(int k = 0; k < size; k++){
                    if(field[j][k] == 'F'){
                        if(j > 0 && k > 0 && field[j-1][k-1] == '#'){
                            tempField[j-1][k-1] = 'F';
                        }
                        if(j > 0 && field[j-1][k] == '#'){
                            tempField[j-1][k] = 'F';
                        }
                        if(j > 0 && k < size - 1 && field[j-1][k+1] == '#'){
                            tempField[j-1][k+1] = 'F';
                        }
                        if( k > 0 && field[j][k-1] == '#'){
                            tempField[j][k-1] = 'F';
                        }
                        if(k < size - 1 && field[j][k+1] == '#'){
                            tempField[j][k+1] = 'F';
                        }
                        if(j < size -1 && k > 0 &&field[j+1][k-1] == '#'){
                            tempField[j+1][k-1] = 'F';
                        }
                        if(j < size - 1 && field[j+1][k] == '#'){
                            tempField[j+1][k] = 'F';
                        }
                        if(j < size - 1 && k < size - 1 && field[j+1][k+1] == '#'){
                            tempField[j+1][k+1] = 'F';
                        }
                    }
                }
            }
            for(int j = 0; j < size; j++){
                for(int k = 0; k < size; k++){
                    field[j][k] = tempField[j][k];
                }
            }
        }

        printf("Case #%d:\n", i+1);
        for(int j = 0; j < size; j++){
            for(int k = 0; k < size; k++){
                printf("%c", field[j][k]);
            }
            printf("\n");
        }
        printf("\n");

    }

    return 0;
}