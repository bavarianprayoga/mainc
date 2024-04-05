#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int id;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int id){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void enqueue(Node **head, int id){
    Node *newNode = createNode(id);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node *tail = *head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->prev = tail;
}

Node *dequeue(Node **head){
    if(*head == NULL){
        return NULL;
    }
    Node *temp = *head;
    if((*head)->next == NULL){
        *head = NULL;
    }
    else{
        *head = (*head)->next;
        (*head)->prev = NULL;
    }
    return temp;
}


int main(){

    int online, walkIn, cancel;
    Node *onlineHead = NULL;
    Node *walkInHead = NULL;
    Node *finalHead = NULL;

    scanf("%d %d", &online, &walkIn);

    for(int i = 0; i < online; i++){
        int id;
        scanf("%d", &id);
        enqueue(&onlineHead, id);
    }

    for(int i = 0; i < walkIn; i++){
        int id;
        scanf("%d", &id);
        enqueue(&walkInHead, id);
    }

    int totalCancel[online + walkIn - 1];
    scanf(" %d", &cancel);
    
    while(onlineHead != NULL || walkInHead != NULL){
        if(onlineHead != NULL){
            Node *curr = dequeue(&onlineHead);
            enqueue(&finalHead, curr->id);
            free(curr);
        }
        if(walkInHead != NULL){
            Node *curr = dequeue(&walkInHead);
            enqueue(&finalHead, curr->id);
            free(curr);
        }
    }

    if(cancel > 0){
        for(int i = 0; i < cancel; i++){
            scanf(" %d", &totalCancel[i]);
            Node *curr = finalHead;
            Node *prev = NULL;

            while(curr != NULL && curr->id != totalCancel[i]){
                prev = curr;
                curr = curr->next;
                if(curr == finalHead){
                    break;
                }
            }

            if(curr == NULL){
                printf("Invalid ID\n");
            }
            else{
                if(curr == finalHead){
                    finalHead = finalHead->next;
                    free(curr);
                }
                else{
                    prev->next = curr->next;
                    free(curr);
                }
            }
        }
    }

    Node *curr = finalHead;
    while(curr != NULL){
        printf("%d ", curr->id);
        curr = curr->next;
    }
    puts("");

    while(finalHead != NULL){
        Node *temp = finalHead;
        finalHead = finalHead->next;
        free(temp);
    }

    return 0;
}