#include <stdio.h>

void selection(int array[], int size){
    for(int i = 0; i < size - 1; i++){
        int max = 0;
        int j;
        for(int j = 0; j < size - i; j++){ //buat ngeloop utk nentuin size terbesar
            if(array[max] < array[j]){
                max = j; //buat nentuin index terbesar
            }
        }

        if(max != size - i - 1){
            int temp = array[size - i - 1];
            array[size - i - 1] = array[max];
            array[max] = temp;
        }
    }
}

int main(){

    int array[] = {5, 6, 2, 4, 9, 8, 1, 7, 3};
    int size = sizeof(array)/sizeof(array[0]);

    selection(array, size);

    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }

    return 0;
}