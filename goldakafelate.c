#include <stdio.h>
#include <string.h>

int binarySearch(char arr[][100], int size, char target[]){
    int left = 0, right = size -1;

    while(left <= right){
        int mid = left + (right - left) / 2;

        if(strcmp(arr[mid], target) == 0){
            return mid;
        }
        else if(strcmp(arr[mid], target) > 0){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
}

int main(){

    FILE *file = fopen("input.txt", "r");

    int t;
    fscanf(file, "%d", &t);

    char arr[t][100];

    for(int i = 0; i < t; i++){
        fscanf(file, "%[^\n]\n", arr[i]);
    }
    
    int size = sizeof(arr)/sizeof(arr[0]);

    char target[100];
    fscanf(file, "%[^\n]\n", target);

    int idx = binarySearch(arr, size, target);

    if(idx == -1){
        printf("Not found\n");
    }
    else{
        printf("%s found at index %d\n", target, idx);
    }



    return 0;
}
