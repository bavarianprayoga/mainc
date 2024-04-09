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

void enqueue(Node **head, int id){ // note at the end
    Node *newNode = createNode(id);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node *tail = *head;
    while(tail->next != NULL){
        // iterate to the last node
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->prev = tail;
}

Node *dequeue(Node **head){ // note at the end
    if(*head == NULL){
        return NULL;
    }
    Node *temp = *head;
    // bikin pointer baru buat nampung head yang mau dihapus
    if((*head)->next == NULL){
        // if there's only one node
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
        // merge the two queues
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

// why **head in enqueue and dequeue?

/*In C, variables are passed to functions by value, not by reference. This means that if you pass a variable to a function, 
the function creates a local copy of that variable, and any changes made to the variable inside the function do not affect the original variable.

In your code, head is a pointer to the first node in your linked list. If you want to modify the linked list in your enqueue or dequeue function 
(for example, to add a new node or remove the first node), you need to be able to change head. If you passed head directly to your function, 
the function would get a copy of head, and any changes made to head inside the function would not affect the original linked list.

To get around this, you can pass a pointer to head to your function. This is what Node **head is: a pointer to a pointer to a Node. 
When you pass &head (the address of head) to your function, the function can then dereference head (with *head) to get the actual head pointer and modify it. 
This allows the function to make changes to the original linked list.*/

