#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO bikin pop/remove buat completed task

typedef struct Node{
    int id;
    int dueDate;
    char desc[100];
    char employee[100];
    int status; //1 for completed, 0 for pending
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int id, int dueDate, char desc[100], char employee[100], int status){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->dueDate = dueDate;
    strcpy(newNode->desc, desc);
    strcpy(newNode->employee, employee);
    newNode->status = status;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node *insertSorted(Node *head, Node *newNode){
    if(head == NULL || newNode->dueDate < head->dueDate){ //check if head is NULL or newNode's dueDate is smaller than head's. If true, insert at head
        newNode->next = head; //newNode's next is head, if head is NULL, newNode's next is NULL
        if(head != NULL){ //if head is not NULL, head's prev is newNode. This means newNode is now the head
            head->prev = newNode;
        }
        return newNode;
    }
    Node *curr = head;
    while(curr->next != NULL && curr->dueDate < newNode->dueDate){
        curr = curr->next;
    }
    if(curr->next == NULL){ //insert at tail
        curr->next = newNode;
        newNode->prev = curr;
    }
    else{ //insert in between
        newNode->next = curr->next;
        curr->next->prev = newNode;
        curr->next = newNode;
        newNode->prev = curr;
    }
    return head;
}

void printPendingTasks(Node *head){
    Node *curr = head;
    if(curr != NULL) printf("%-5s %-30s %-25s %-15s %-10s\n", "ID", "Task Description", "Assigned Employee", "Due Date", "Status");
    while(curr != NULL){
        if(curr->status == 0){
            printf("%-5d %-30s %-25s %04d-%02d-%02d %12s\n", curr->id, curr->desc, curr->employee, curr->dueDate / 10000, (curr->dueDate / 100) % 100, curr->dueDate % 100, curr->status == 0 ? "Pending" : "Completed");
        }
        curr = curr->next;
    }
    free(curr);
}

void printCompletedTasks(Node *head){
    Node *curr = head;
    while(curr != NULL){
        if(curr->status == 1){
            printf("Task details:\n");
            printf("ID: %d\n", curr->id);
            printf("Task Description: %s\n", curr->desc);
            printf("Assigned Employee: %s\n", curr->employee);
            printf("Due Date: %04d-%02d-%02d\n", curr->dueDate / 10000, (curr->dueDate / 100) % 100, curr->dueDate % 100);
            printf("Status: %s\n", curr->status == 0 ? "Pending" : "Completed");
            puts("");
        }
        curr = curr->next;
    }
    free(curr);
}

int main(){

    int t;
    int id = 1;
    printf("Input number of tasks: ");
    scanf(" %d", &t);

    Node *head = NULL;

    for(int i = 0; i < t; i++){
        int year, month, day, dueDate, status; //status automatically set to 0
        char desc[100], employee[100];
        printf("Task description: ");
        scanf(" %[^\n]", desc);

        printf("Assign employee: ");
        scanf(" %[^\n]", employee);

        printf("Due date (YYYY-MM-DD): ");
        scanf(" %d-%d-%d", &year, &month, &day);
        dueDate = year * 10000 + month * 100 + day;
        puts("");

        head = insertSorted(head, createNode(id, dueDate, desc, employee, 0));
        id++;
    }

    printPendingTasks(head);

    char completedChoice;

    printf("Do you want to mark a task as completed? (Y/N): ");
    scanf(" %c", &completedChoice);
    if(completedChoice == 'Y' || completedChoice == 'y'){
        int amountCompleted;
        printf("How many? ");
        scanf(" %d", &amountCompleted);

        for(int i = 0; i < amountCompleted; i++){
            Node *curr = head;
            while(curr != NULL && curr->status == 1){
                curr = curr->next;
            }
            if(curr != NULL){
                curr->status = 1;
                printf("Task %d marked as completed.\n", curr->id);
            }
            else{
                printf("No more uncompleted tasks.\n");
                break;
            }
        }
    }
    printCompletedTasks(head);
    printPendingTasks(head);

    return 0;
}