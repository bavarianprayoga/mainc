#include <stdio.h>

// int linearSearch(int arr[], int size, int target) {
//     int idx = -1;
//     for(int i = 0; i < size; i++){
//         if(arr[i] == target){
//             idx = i;
//             break;
//         }
//     }
//     return idx;
// }

int binarySearch(int array[], int size, int target, int left, int right){ //!array harus udah disort
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
    // int arr[] = {5, 2, 9, 7, 1, 8, 3, 6, 4, 10};
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 8;

    // int idx = linearSearch(arr, size, target);
    int idx = binarySearch(arr, size, target, 0, size-1);

    if(idx == -1) 
        printf("Not found\n");
    else 
        printf("%d found at index %d\n", target, idx);

    return 0;
}



