#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int value;
    struct Node *next; //buat ke node selanjutnya
};

struct Node *createNode(int value){ //node baru
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)); //allocate memory
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node *head){ //print linked list
    struct Node *curr = head;
    while(curr != NULL){
        printf("%d ", curr->value);
        curr = curr->next;
    }
}

struct Node *insertHead(struct Node *head, int value){
    struct Node *newNode = createNode(value);
    if(head == NULL){
        return newNode;
    }
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node *insertTail(struct Node *head, int value){
    struct Node *newNode = createNode(value);
    if(head == NULL){
        return newNode;
    }
    struct Node *tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = newNode;
    return head;
}

struct Node *deleteHead(struct Node *head){
    if(head == NULL){
        return NULL;
    }
    struct Node *newHead = head->next;
    free(head);
    return newHead;
}

struct Node *deleteTail(struct Node *head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        free(head);
        return NULL;
    }
    struct Node *curr = head;
    while(curr->next->next != NULL){
        curr = curr->next;
    }
    free(curr->next);
    curr->next = NULL;
    return head;
}

int main(){

    struct Node *head = NULL;

    int t;
    printf("Masukkan jumlah angka: ");
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        int x;
        printf("Masukkan angka: ");
        scanf("%d", &x);
        head = insertTail(head, x);
    }
    
    for(int i = 0; i < t; i++){
        printf("Data = %d\n", head->value);
        head = head->next;
    }

    return 0;
}