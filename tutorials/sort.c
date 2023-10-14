#include <stdio.h>

void sort(char array[], int size){
    for(int i = 0; i < size - 1; i++){
        
        for(int j = 0; j < size -1; j++){
            
            if(array[j] > array[j + 1]){
                //ganti dari > ke < kalo mau descending
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }

        }
    }
}

void print(char array[], int size){
    for(int i = 0; i < size; i++){
        printf("%c ", array[i]);
    }
}

int main(){

    // int array[] = {7, 5, 6, 3, 9, 8, 1, 2, 0, 4};
    char array[] = {'z', 's', 'a', 'm', 'w', 'e'};
    int size = sizeof(array)/sizeof(array[0]);

    sort(array, size);
    print(array, size);

    return 0;
}