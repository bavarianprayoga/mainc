#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char nim[11];
    char name[21];
} data;

int comp(const void *a, const void *b){
    data *x = (data *)a;
    data *y = (data *)b;

    return strcmp(x->nim, y->nim);
}

int main(){

    data siswa[1000];

    FILE *file = fopen("testdata.in", "r");

    int jumlah;
    fscanf(file, "%d", &jumlah);

    for(int i = 0; i < jumlah; i++){
        fscanf(file, "%s %[^\n]\n", siswa[i].nim, siswa[i].name);
    }

    fclose(file);

    qsort(siswa, jumlah, sizeof(data), comp);

    for(int i = 0; i < jumlah; i++){
        printf("%s %s\n", siswa[i].nim, siswa[i].name);
    }

    return 0;
}

