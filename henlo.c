#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int array[], int size){
    int swapped;
    do{
        swapped = 0;
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size - 1 - i; j++){ //dikurang i karena biar ga looping lagi element yg udah diurutin
                if(array[j] > array[j + 1]){
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                    swapped = 1; //kalo gaada yang berubah urutannya swapped ttp 0, jadi gausah lanjutin looping
                }
            }
        }
    } while(swapped == 1);
}



int main(){

    srand(time(0)); // Seed the random number generator with the current time

    int array[10000]; // Change this to the size you want
    int size = sizeof(array)/sizeof(array[0]);

    // Fill the array with random numbers
    for(int i = 0; i < size; i++){
        array[i] = rand() % 10000; // Generate a random number between 0 and 99
    }
    
    bubbleSort(array, size);

    for(int i = 0; i < size; i++){
        printf("%d, ", array[i]);
    }
    puts("");

    return 0;
}