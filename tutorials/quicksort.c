#include <stdio.h>

void quickSort(int arr[], int start, int end);
int urut(int arr[], int start, int end);

int main(){ //*alias ribet

    int arr[] = {3, 6, 8, 2, 5, 1, 7, 9, 4, 0};
    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]) - 1; //buat tau panjang array

    quickSort(arr, start, end);

    printf("Hasil urut: ");
    for(int i =0; i <= end; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void quickSort(int arr[], int start, int end){
    if(end <= start) return; //base case

    int pivot = urut(arr, start, end);
    quickSort(arr, start, pivot - 1); //ngurus sblh kiri pivot (lbh kecil)
    quickSort(arr, pivot + 1, end); //ngurus sblh kanan pivot (lbh besar)
}

int urut(int arr[], int start, int end){
    int pivot = arr[end]; //ambil pivot terakhir sebagai patokan
    int i = start - 1; //indeks untuk elemen yg lebih kecil dari pivot


    for(int j = start; j <= end - 1; j++){
        if(arr[j] < pivot){
            i++;
            int swap = arr[i];
            arr[i] = arr[j];
            arr[j] = swap; //loop terus sampe semua nilai di kiri nilainya lebih kecil dari pivot
        }
    }
    i++;
    int swap = arr[i];
    arr[i] = arr[end];
    arr[end] = swap; //buat nuker pivot yang ada di akhir array ke tempatnya
    
    return i;

    /*
    kalo mau pivot di tengah:
    int pivotIdx = (start + end) / 2;
    int pivot = arr[pivotIdx];

    int swap = arr[pivotIdx];
    arr[pivotIdx] = arr[end];
    arr[end] = swap;

    taro sebelum int i

    */

    /* 
    kalo mau pivotnya median-of-three (buat gaya)
    
    int mid = (start + end) / 2; //ambil mid

    if(arr[mid] < arr[start]){ //kalo mid lebih kecil dari start
        int swap = arr[mid];
        arr[mid] = arr[start];
        arr[start] = swap; //tuker mid sama start
    }

    if(arr[mid] > arr[end]){ //kalo mid lebih besar dari end
        int swap = arr[mid];
        arr[mid] = arr[end];
        arr[end] = swap; //tuker mid sama end

        if(arr[mid] < arr[start]){ //kalo mid lebih kecil dari start
            int swap = arr[mid];
            arr[mid] = arr[start];
            arr[start] = swap; //tuker mid sama start
        }
    }

    tuker median (mid) sama last element
    int swap = arr[mid];
    arr[mid] = arr[end];
    arr[end] = swap; 

    int pivot = arr[end]; //pivot udah jadiiii (median dr first, mid, end)

    taro sebelum int i
    */
}