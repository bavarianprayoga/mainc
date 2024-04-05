#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
100D = 1
500D = 2
1000D = 3
*/

typedef struct Node{
    int date;
    int diamond;
    int amount;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int date, int diamond, int amount){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->date = date;
    newNode->diamond = diamond;
    newNode->amount = amount;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int diamondValue(char diamond[10]){
    if(strcmp(diamond, "100D") == 0) return 1;
    else if(strcmp(diamond, "500D") == 0) return 2;
    else if(strcmp(diamond, "1000D") == 0) return 3;
    return 0;
}

Node *insertSorted(Node *head, Node *newNode){
    if(head == NULL || newNode->diamond < head->diamond || (newNode->diamond == head->diamond && newNode->date < head-> date)){
        newNode->next = head;
        if(head != NULL){
            head->prev = newNode;
        }
        return newNode;
    }
    Node *curr = head;
    while(curr->next != NULL && ((curr->next->diamond < newNode->diamond && curr->next->date <= newNode->date) || (curr->next->diamond == newNode->diamond && curr->next->date < newNode->date))){
        curr = curr->next;
    }
    if(curr->next == NULL){
        curr->next = newNode;
        newNode->prev = curr;
    }
    else{
        newNode->next = curr->next;
        curr->next->prev = newNode;
        curr->next = newNode;
        newNode->prev = curr;
    }
    return head;
}

void printStock(Node *head, int diamondType, char *diamondName){
    Node *curr = head;
    int totalAmount = 0;
    while(curr != NULL){
        if(curr->diamond == diamondType){
            totalAmount += curr->amount;
        }
        curr = curr->next;
    }
    printf("%s Stock: %d\n", diamondName, totalAmount);

    curr = head;
    while(curr != NULL){
        if(curr->diamond == diamondType){
            printf("%s: %d item (%d-%d-%d)\n", diamondName, curr->amount, curr->date % 100, (curr->date / 100) % 100, curr->date / 10000);
        }
        curr = curr->next;
    }
}

void printSorted(Node *head){
    printStock(head, 1, "100D");
    printStock(head, 2, "500D");
    printStock(head, 3, "1000D");
}

void pop(Node **head, int diamondType){
    Node *curr = *head;
    Node *temp;
    while(curr != NULL){
        if(curr->diamond == diamondType){
            if(curr->prev == NULL){
                *head = curr->next;
                if(curr->next != NULL){
                    curr->next->prev = NULL;
                }
            }
            else{
                curr->prev->next = curr->next;
                if(curr->next != NULL){
                    curr->next->prev = curr->prev;
                }
            }
            temp = curr;
            curr = curr->next;
            free(temp);
        } else {
            curr = curr->next;
        }
    }
}

int main(){

    int t;
    scanf(" %d", &t);

    Node *head = NULL;

    for(int i = 0; i < t; i++){
        int day, month, year, date, amount;
        char diamond[10];
        scanf(" %d-%d-%d %s %d", &day, &month, &year, diamond, &amount);
        date = year * 10000 + month * 100 + day;

        head = insertSorted(head, createNode(date, diamondValue(diamond), amount));
    }

    printSorted(head);

    char deleteDiamond[10];
    scanf(" %s", deleteDiamond);
    pop(&head, diamondValue(deleteDiamond));

    // Node *curr = head;
    // while(curr != NULL){
    //     printf("%d %d %d\n", curr->date, curr->diamond, curr->amount);
    //     curr = curr->next;
    // }

    printSorted(head);

    return 0;
}