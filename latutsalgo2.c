#include <stdio.h>

int main(){
    
    int n;
    scanf("%d",&n);

    int matrix[n][n];
    int maxRow = 0;
    int maxCol = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&matrix[i][j]);
            if(matrix[i][j] > matrix[maxRow][maxCol]){
                maxRow = i;
                maxCol = j;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != maxRow && j != maxCol){
                printf("%d ", matrix[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
