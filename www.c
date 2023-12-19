#include <stdio.h>
#include <string.h>

int main(){

    int t;

    FILE *file = fopen("w.txt", "r");

    if(file == NULL) perror("errawrrr");

    fscanf(file, " %d", &t);

    char name[t][100];
    int age[t];

    for(int i = 0; i < t; i++){
        fscanf(file, " %[^-]-%d", name[i], &age[i]);
    }

    fclose(file);

    return 0;
}