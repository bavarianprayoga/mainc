#include <stdio.h>

void merge(int array[], int startL, int endL, int startR, int endR){
    int temp[endR - startL + 1]; 
    int l = startL;
    int r = startR;
    int idx = 0;

    while(l <= endL && r <= endR){
        if(array[l] < array[r]){
            temp[l + r - startL - startR] = array[l];
            l++;
            idx++;
        } 
        else{
            temp[l + r - startL - startR] = array[r];
            r++;
            idx++;
        }
    }

    while(l <= endL){
        temp[idx] = array[l];
        l++;
        idx++;
    }

    while(r <= endR){
        temp[idx] = array[r];
        r++;
        idx++;
    }

    for(int i = startL; i <= endR; i++){
        array[i] = temp[i - startL];
    }
}

void mergeSort(int array[], int start, int end){
    if(start == end) return;
    int mid = (start + end) / 2;
    mergeSort(array, start, mid);
    mergeSort(array, mid + 1, end);
    merge(array, start, mid, mid + 1, end);
}

int main(){
    int array[10] = {7, 3, 9, 1, 5, 2, 8, 4, 6, 0};
    int size = sizeof(array) / sizeof(array[0]);
    int start = 0; // Use index values
    int end = size - 1;

    mergeSort(array, start, end);

    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }

    return 0;
}
