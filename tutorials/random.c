#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(0)); //pake waktu buat seed

    int num1 = rand() % 6 + 1; //random 1-6

    return 0;
}