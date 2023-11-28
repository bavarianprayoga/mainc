#include <stdio.h>

void insertion(int array[], int size){
    for(int i = 1; i < size; i++){
        int temp = array[i];
        int j;

        for(int j = i - 1; j >= 0; j--){
            if(array[j] > temp){
                array[j + 1] = array[j];
            }
            else break;
        }
        array[j + 1] = temp;

        //! MASIH ERROR LETSGOOOOOO
    }
}

int main(){

    int array[] = {5, 6, 2, 4, 9, 8, 1, 7, 3};
    int size = sizeof(array)/sizeof(array[0]);

    insertion(array, size);

    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }

    return 0;
}