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

    int pos[t], neg[t];
    int j = 0, k = 0;

    for(int i = 0; i < t; i++){
        if(arr[i] >= 0){
            pos[j] = arr[i];
            j++;
        }else{
            neg[k] = arr[i];
            k++;
        }
    }

    printf("The positive elements are: ");
    for(int i = 0; i < j; i++){
            printf("%d ", pos[i]);
    }
    puts("");

    printf("The negative elements are: ");
    for(int i = 0; i < k; i++){
            printf("%d ", neg[i]);
    }
    puts("");

    return 0;
}