#include <stdio.h>

int main(){

    int t;
    printf("Enter the number of elements: ");
    scanf("%d", &t);

    int arr[t];

    for(int i = 0; i < t; i++){
        printf("element %d: ", i);
        scanf("%d", &arr[i]);
    }

    int len = sizeof(arr) / sizeof(arr[0]);

    printf("The values stored into the array: ");
    for(int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    puts("");

    printf("The values stored into the array in reverse order: ");
    for(int i = len - 1; i >= 0; i--){
        printf("%d ", arr[i]);
    }
    puts("");

    return 0;
}