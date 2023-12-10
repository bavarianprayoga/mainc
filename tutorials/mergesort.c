#include <stdio.h>

void merge(int array[], int leftStart, int leftEnd, int rightStart, int RightEnd){
    int temp[RightEnd - leftStart + 1]; 
    int l = leftStart;
    int r = rightStart;
    int idx = 0;

    while(l <= leftEnd && r <= RightEnd){
        if(array[l] < array[r]){
            temp[l + r - leftStart - rightStart] = array[l];
            l++;
            idx++;
        } 
        else{
            temp[l + r - leftStart - rightStart] = array[r];
            r++;
            idx++;
        }
    }

    while(l <= leftEnd){
        temp[idx] = array[l];
        l++;
        idx++;
    }

    while(r <= RightEnd){
        temp[idx] = array[r];
        r++;
        idx++;
    }

    for(int i = leftStart; i <= RightEnd; i++){
        array[i] = temp[i - leftStart];
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
