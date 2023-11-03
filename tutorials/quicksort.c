#include <stdio.h>

void quickSort(int arr[], int start, int end);
int urut(int arr[], int start, int end);

int main(){ //*alias ribet

    int arr[] = {3, 6, 8, 2, 5, 1, 7, 9, 4, 0};
    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]) - 1; //buat tau panjang array

    quickSort(arr, start, end);

    printf("Hasil urut: ");
    for(int i =0; i<=end; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void quickSort(int arr[], int start, int end){
    if(end <= start)  return; //base case

    int pivot = urut(arr, start, end);
    quickSort(arr, start, pivot - 1); //ngurus sblh kiri pivot (lbh kecil)
    quickSort(arr, pivot + 1, end); //ngurus sblh kanan pivot (lbh besar)
}

int urut(int arr[], int start, int end){
    int pivot = arr[end]; //ambil pivot terakhir sebagai patokan
    int i = start-1; //indeks untuk elemen yg lebih kecil dari pivot

    for(int j = start; j <= end-1; j++){
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
}