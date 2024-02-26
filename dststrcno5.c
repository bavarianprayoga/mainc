#include <stdio.h>

int main(){

    int t;
    printf("Input the size of the square matrix: ");
    scanf("%d", &t);

    int arr[t][t];

    for(int i = 0; i < t; i++){
        for(int j = 0; j < t; j++){
            printf("element [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    int rowSum[t], colSum[t];

    for(int i = 0; i < t; i++){
        rowSum[i] = 0;
        colSum[i] = 0;
    }

    for(int i = 0; i < t; i++){
        for(int j = 0; j < t; j++){
            rowSum[i] += arr[i][j];
            colSum[i] += arr[j][i];
        }
    }

    printf("The sum of the rows: ");
    for(int i = 0; i < t; i++){
        printf("%d ", rowSum[i]);
    }
    puts("");

    printf("The sum of the columns: ");
    for(int i = 0; i < t; i++){
        printf("%d ", colSum[i]);
    }
    puts("");

    return 0;
}