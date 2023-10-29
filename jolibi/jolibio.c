#include <stdio.h>

int calc(int num) {
    while(num > 0){
        int digit = num % 10;
        
        if (digit == 3 || digit == 5){
            return 1;
        }
        num /= 10;
    }
    
    return 0;
}

int main() {
    int count = 0;

    for (int num = 1; num <= 1000000; num++){
        if (calc(num)){
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
