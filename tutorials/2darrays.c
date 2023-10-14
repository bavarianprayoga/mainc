#include <stdio.h>
#include <string.h>

int main(){

    /*
    int numbers[2][3] = {
                        {2, 3, 4}, 
                        {5, 6, 7}
                        };
    2 ini max jumlah brp 2d array, 3 ini max ada brp elemen per array
    gampangnya depan row belakang column
    */

    int numbers[3][3];
    //row ga harus di declare sizenya, tp column harus

    int rows = sizeof(numbers)/sizeof(numbers[0]);
    int colums = sizeof(numbers[0])/sizeof(numbers[0][0]);
    //biar fleksibel sizenya buat di for loop

    numbers[0][0] = 2;
    numbers[0][1] = 3;
    numbers[0][2] = 4;
    numbers[1][0] = 5;
    numbers[1][1] = 6;
    numbers[1][2] = 7;
    numbers[2][0] = 8;
    numbers[2][1] = 9;
    numbers[2][2] = 0;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < colums; j++){
            printf("%d ", numbers[i][j]);
        }
        puts("");
    }

    //array of strings

    char motor[][10] = {"vario", "beat mber", "galih"};
    //10 disini kayaknya max character tiap array

    //kalo mau ganti isi arraynya gbs langsung, hrs pake strcpy
    strcpy(motor[2], "gilang");

    for(int i = 0; i < sizeof(motor)/sizeof(motor[0]); i++){
        printf("%s\n", motor[i]);
    }

    return 0;
}