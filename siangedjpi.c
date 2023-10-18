#include <stdio.h>

int main(){

    int quantity, changes, no, new;

    scanf("%d", &quantity);

    int items[quantity];

    for(int i = 0; i < quantity; i++){
        scanf("%d", &items[i]);
    }

    scanf("%d", &changes);

    for(int i = 0; i < changes; i++){
        scanf("%d %d", &no, &new);
        items[no-1] = new; 
        printf("Case #%d: ", i+1);

        for(int j = 0; j < quantity; j++){
        printf("%d ", items[j]);
        }
        puts("");
    }


    return 0;
}