#include <stdio.h>

int main() {


    char name[50][100];
    int age[50];
    int idx = 0;
    char filename[100];

    printf("Enter filename: ");
    scanf("%s", filename);
    getchar();

    FILE *fp2 = fopen(filename, "r");
    
    while(fscanf(fp2, "%[^_]_%d\n", name[idx], &age[idx]) != EOF) {
        idx++;
    }
    
    fclose(fp2);

    for (int i = 0; i < idx; i++) {
        printf("name: %s\nAge: %d\n\n", name[i], age[i]);
    }

    return 0;
}

    // FILE *fp = fopen("gatau.txt", "w");

    // fprintf(fp, "bavarian\n");
    // fprintf(fp, "buda\n");
    // fprintf(fp, "budi\n");
    // fprintf(fp, "budu\n");
    // fprintf(fp, "bude\n");
    // fprintf(fp, "budo\n");

    // fclose(fp);



