#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);
    getchar();

    char sky[n][n];

    for(int i = 0; i < n; i++){
        scanf("%s", &sky[i]);
        getchar();
    }

    for(int i = 0; i < n / 2; i++){
        for(int j = 0; j < n; j++){
            char temp = sky[i][j];
            sky[i][j] = sky[n - i - 1][j];
            sky[n - i - 1][j] = temp;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n / 2; j++){
            char temp = sky[i][j];
            sky[i][j] = sky[i][n - j - 1];
            sky[i][n - j - 1] = temp;
        }
    }

    for(int i = 0; i < n; i++){
        printf("%s\n", sky[i]);
    }

    return 0;
}
