#include <stdio.h>

void sort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int pintu(int orang, int waktu, int urutan[]){
    sort(urutan, orang);

    int door = 1; int detik = urutan[0];

    for(int i = 1; i < orang; i++){
        if(urutan[i] - detik > waktu){
            door++;
            detik = urutan[i];
        }
    }
    return door;
}

int main(){
    
    int t;
    scanf("%d", &t);

    int result[t];

    for(int i = 0; i < t; i++){
        int orang;
        int waktu;

        scanf("%d %d", &orang, &waktu);

        int urutan[orang];
        for(int j = 0; j < orang; j++){
            scanf("%d", &urutan[j]);
        }

        result[i] = pintu(orang, waktu, urutan);
    }

    for(int i = 0; i < t; i++){
        printf("%d\n", result[i]);
    }
    
    return 0;
}
