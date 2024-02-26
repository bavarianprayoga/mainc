#include <stdio.h>

int main(){

    int t;
    printf("Enter the number of elements: ");
    scanf("%d", &t);

    int arr[t];
    int sum = 0;

    for(int i = 0; i < t; i++){
        printf("element %d: ", i);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("Sum: %d\n", sum);

    return 0;
}