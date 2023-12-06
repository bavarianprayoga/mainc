#include <stdio.h>

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

int binarySearch(int array[], int size, int target, int left, int right){
    if(left > right) return -1; //kalo target gaada di array

    int mid = left + (right - left) / 2;

    if(array[mid] == target){
        return mid; //langsung ketemu
    }
    else if(array[mid] > target){
        return binarySearch(array, size, target, left, mid-1); //berarti target ada di kiri mid
    }
    else{
        return binarySearch(array, size, target, mid+1, right); //target ada di kanan mid
    }
}

int main(){

    int array[] = {7, 5, 6, 3, 9, 8, 1, 2, 0, 4, 8750};
    int size = sizeof(array)/sizeof(array[0]);
    int target = 6;
    
    bubbleSort(array, size);
    int index = binarySearch(array, size, target, 0, size-1);
    // 5 = target, 0 = left index, size-1 = right index

    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    puts("");

    printf("Index of target %d is %d\n", target, index);

    return 0;
}