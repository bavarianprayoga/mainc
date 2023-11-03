#include <stdio.h>

int main(){

    char menu[][20] = {"Panda Mi", "Panda Milk", "Yellow Band", "Healthy Olive Oil", "Three Panda Rice", "Chicken Egg", "Panda Soy Sauce", "Your Salt", "My Sugar", "Baby Soap"};
    int stock[10] = {5, 10, 1, 3, 15, 20, 1, 5, 10, 10};
    int price[10] = {5000, 7500, 3000, 50000, 70000, 11000, 12000, 3000, 21000, 3000};
    int count[10] = {0};
    int totalItem[10] = {0};
    int totalPrice = 0, choice = 0;

    printf("No.  | Item Name         | Stock | Price | Count | Total\n");
    for(int i = 0; i < 10; i++){
        printf("%-2d   | %-17s | %-5d | %-5d | %-5d | %-5d\n", i + 1, menu[i], stock[i], price[i], count[i], totalItem[i]);
    }

    printf("Input item that you want [1-10]: ");
    scanf("%d", &choice);



    return 0;
}