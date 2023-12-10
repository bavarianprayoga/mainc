#include <stdio.h>

void bubble(int num[], int t){
    int swapped;
    do{
        swapped = 0;
        for(int i = 0; i < t; i++){
            for(int j = 0; j < t - i - 1; j++){
                if(num[j] > num[j + 1]){
                    int temp = num[j];
                    num[j] = num[j + 1];
                    num[j + 1] = temp;
                    swapped = 1;
                }
            }
        }
    } while(swapped == 1);
}

int main(){

    int t;
    scanf("%d", &t);

    int num[t];

    for(int i = 0; i < t; i++){
        scanf("%d", &num[i]);
    }

    bubble(num, t);

    for(int i = 0; i < t; i++){
        printf("%d ", num[i]);
    }
}