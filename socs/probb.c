#include <stdio.h>

int same(int num[100][100], int n){
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            
            for(int k = j + 1; k < n; k++){
                if(num[i][j] == num[i][k]) return 1; 
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            
            for(int k = j + 1; k < n; k++){
                if(num[j][i] == num[k][i]) return 1;
            }
        }
    }
    return 0;
}

int main(){

    int n;
    scanf("%d", &n);

    int num[100][100];
    
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &num[i][j]);
        }
    }
    
    int ssame = same(num, n);

    if(ssame == 0){
        printf("Yay\n");
    }
    else{
        printf("Nay\n");
    }   

    return 0;
}