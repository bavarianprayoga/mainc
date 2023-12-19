#include <stdio.h>
#include <string.h>

int linear(char name[][31], int n, char target[]){
    for(int i = 0; i < n; i++){
        if(strcmp(name[i], target) == 0) return i;
    }
    return -1;
}

int main(){

    FILE *file = fopen("data.txt", "r");

    int t;
    fscanf(file, " %d", &t);

    int check[t];

    for(int i = 0; i < t; i++){
        int n;
        fscanf(file, " %d", &n);

        char name[n][31];
        for(int j = 0; j < n; j++){
            fscanf(file, " %s", name[j]);
        }

        char target[31];
        fscanf(file, " %s", target);

        check[i] = linear(name, n, target) + 1;
    }

    for(int i = 0; i < t; i++){
        printf("Case #%d: ", i+1);
        if(check[i] != 0) printf("%d\n", check[i]);
        else printf("Not found\n");
    }

    fclose(file);

    return 0;
}