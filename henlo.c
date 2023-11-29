#include <stdio.h>
#include <string.h>

typedef struct{
    char name[100];
    int qty;
    int price;
} Data;

int main(){

    FILE *file = fopen("input.txt", "r");

    if(file == NULL){
        printf("errrorrr\n");
        return -1;
    }

    Data sembako[500] = {0};

    int i = 0;

    while(fscanf(file, "%[^#]#%d_%d\n", sembako[i].name, &sembako[i].qty, &sembako[i].price) != EOF){
        i++;
    }

    fclose(file);

    FILE *file2 = fopen("input.txt", "a");

    do{
        printf("Masukkan nama barang baru; [3-100 characters]:");
        scanf("%[^\n]", sembako[i].name);
        getchar();
    } while(strlen(sembako[i].name) <= 3 || strlen(sembako[i].name) > 100);

    do{
        printf("Masukkan jumlah barang baru; [>= 1]:");
        scanf("%d", &sembako[i].qty);
        getchar();
    } while(sembako[i].qty < 1);

    do{
        printf("Masukkan harga barang baru; [>= 100]:");
        scanf("%d", &sembako[i].price);
        getchar();
    } while(sembako[i].price < 100);

    fprintf(file2, "%s#%d_%d\n", sembako[i].name, sembako[i].qty, sembako[i].price);

    fclose(file2);

    printf("Nama          Qty   Harga\n");
    for(int j = 0; j < i; j++){
        printf("%-13s %-5d %d\n", sembako[j].name, sembako[j].qty, sembako[j].price);
    }

    return 0;
}