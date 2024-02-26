#include <stdio.h>

int main(){

    double height[10] = {175, 165, 166, 157, 184, 156, 163, 176, 171, 167};
    double avg = 0;

    for(int i = 0; i < 10; i++){
        avg += height[i];
    }

    avg /= 10;

    printf("Average height: %.1lf\n", avg);
    
    return 0;
}