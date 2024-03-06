#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int value;
    struct Node *next;
    struct Node *prev;
};

struct Node *createNode(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void printList(struct Node *head){
    struct Node *curr = head;
    while(curr != NULL){
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

struct Node *insertHead(struct Node *head, int value){
    struct Node *newNode = createNode(value);
    if(head == NULL){
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
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
    newNode->prev = tail;
    newNode->next = NULL;
    return head;
}

struct Node *deleteHead(struct Node *head){
    if(head == NULL){
        return NULL;
    }
    struct Node *newHead = head->next;
    newHead->prev = NULL;
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
    int choice;

    do{
        printf("What do you want to do?\n");
        printf("1. Display data\n");
        printf("2. Insert data at the head\n");
        printf("3. Insert data at the tail\n");
        printf("4. Delete data at the head\n");
        printf("5. Delete data at the tail\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printList(head);
                break;
            case 2:
                printf("How many data do you want to insert? ");
                int n;
                scanf("%d", &n);

                for(int i = 0; i < n; i++){
                    printf("Enter the value to be inserted: ");
                    int x;
                    scanf("%d", &x);
                    head = insertHead(head, x);
                }

                break;
            case 3:
                printf("How many data do you want to insert? ");
                int t;
                scanf("%d", &t);

                for(int i = 0; i < t; i++){
                    printf("Enter the value to be inserted: ");
                    int x;
                    scanf("%d", &x);
                    head = insertTail(head, x);
                }

                break;
            case 4:
                head = deleteHead(head);
                break;
            case 5:
                head = deleteTail(head);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice != 6);

    return 0;
}