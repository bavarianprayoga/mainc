#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char category[50];
    char details[50];
    int amount;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct CategoryList{
    char *category;
    int total;
    struct CategoryList *next;
    struct CategoryList *prev;
} CategoryList;

Node *createNode(char category[50], char details[50], int amount){
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->category, category);
    strcpy(newNode->details, details);
    newNode->amount = amount;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node *insertAtTail(Node *tail, Node *newNode){
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    return tail;
}

CategoryList *Categorizing(Node *head){
    CategoryList *listHead = NULL;
    CategoryList *listTail = NULL;
    Node *curr = head;

    while(curr != NULL){
        CategoryList *currCat = listHead;

        while(currCat != NULL && strcmp(currCat->category, curr->category) != 0){
            currCat = currCat->next;
        }

        if(currCat == NULL){
            currCat = malloc(sizeof(CategoryList));
            currCat->category = curr->category;
            currCat->total = 0;
            currCat->next = NULL;

            // If the list is empty, update the head
            if(listHead == NULL) listHead = currCat;
                // Otherwise, append to the tail
            else  listTail->next = currCat;

            listTail = currCat;
        }

        currCat->total += curr->amount;
        curr = curr->next;
    }

    return listHead;
}

Node *deleteDetails(Node *head, char *details){
    Node *curr = head;
    Node *prev = NULL;
    while(curr != NULL){
        if(strcmp(curr->details, details) == 0){
            if(prev == NULL){
                // If the node to be deleted is the head
                head = curr->next;
                free(curr);
                curr = head;
            }
            else{
                // If the node to be deleted is not the head
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
            }
        }
        else{
            // If the node is not the one to be deleted
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

int calculateBalance(Node *head, int balance){
    Node *curr = head;
    while(curr != NULL){
        balance -= curr->amount;
        curr = curr->next;
    }
    return balance;
}

void printCategory(CategoryList *head){
    CategoryList *curr = head;
    while(curr != NULL){
        printf("%s: %d\n", curr->category, curr->total);
        curr = curr->next;
    }
    puts("");
}

void printDetails(Node *head){
    Node *curr = head;
    while(curr != NULL){
        printf("%s (%s): %d\n", curr->details, curr->category, curr->amount);
        curr = curr->next;
    }
    puts("");
}

int main(){

    Node *head = NULL;
    Node *tail = NULL;

    int balance;
    scanf(" %d", &balance);

    int transactionAmount;
    scanf(" %d", &transactionAmount);

    for(int i = 0; i < transactionAmount; i++){
        char category[50], details[50];
        int amount;

        scanf(" %s %s", category, details);
        scanf(" %d", &amount);

        Node *newNode = createNode(category, details, amount);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail = insertAtTail(tail, newNode);
        }
    }

    char detailsToDelete[50];
    scanf(" %s", detailsToDelete);
    head = deleteDetails(head, detailsToDelete);

    puts("");

    printf("Account Balance: %d\n", calculateBalance(head, balance));
    CategoryList *categorizedHead = Categorizing(head);
    printCategory(categorizedHead);
    printDetails(head);

    return 0;
}