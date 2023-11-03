#include <stdio.h>

int main(){

    int makan;
    scanf("%d", &makan);

    int aan[makan], kenken[makan];
    int sumaan = 0, sumkenken = 0;

    for(int i = 0; i < makan; i++){
        scanf("%d", &aan[i]);
    }

    for(int i = 0; i < makan; i++){
        scanf("%d", &kenken[i]);
    }

    if(makan % 2 == 0){
        for(int i = 1; i < makan; i += 2){
            aan[i] += 2000;
        }
    }
    else{
        for(int i = 0; i < makan; i += 2){
            aan[i] += 2500;
        }
    }

    for(int i = 0; i < makan; i++){
        sumaan += aan[i];
        sumkenken += kenken[i];
    }

    if(sumaan > sumkenken){
        printf("aan\n");
    }
    else if(sumaan < sumkenken){
        printf("kenken\n");
    }
    else{
        printf("patungan\n");
    }

    return 0;
}