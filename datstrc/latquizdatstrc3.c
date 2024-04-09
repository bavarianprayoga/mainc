#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        // if head is null OR newNode's diamond is less than head's diamond OR newNode's diamond is equal to head's diamond but newNode's date is less than head's date (earlier)
        newNode->next = head;
        if(head != NULL){
            //if head is not null, set head's prev to newNode as newNode is the new head
            head->prev = newNode;
        }
        return newNode;
    }
    Node *curr = head;
    // iterate through the list until we find the correct position to insert newNode
    while(curr->next != NULL && ((curr->next->diamond < newNode->diamond && curr->next->date <= newNode->date) || (curr->next->diamond == newNode->diamond && curr->next->date < newNode->date))){
        // while curr's next is not null AND (curr's next's diamond is less than newNode's diamond AND curr's next's date is less than or equal to newNode's date) OR (curr's next's diamond is equal to newNode's diamond AND curr's next's date is less than newNode's date)
        // used next node because we want to insert newNode between curr and curr->next
        curr = curr->next;
    }
    if(curr->next == NULL){
        // if curr's next is null, that means curr is the last node. So, insert newNode after curr
        curr->next = newNode;
        newNode->prev = curr;
    }
    else{
        // insert newNode between curr and curr->next
        newNode->next = curr->next;
        curr->next->prev = newNode;
        curr->next = newNode;
        newNode->prev = curr;
    }
    return head;
}

void printStock(Node *head, int diamondType, char *diamondName){
    // passing the pointer of diamondName so the function knows that diamondName is a pointer to a string and not just a char
    // why? you're actually passing a pointer to the first character of the string. This allows the function to access the entire string, 
    // because it can use the pointer to traverse the array of characters.
    Node *curr = head;
    int totalAmount = 0;
    // iterate through the list to calculate the total amount of the diamondType
    while(curr != NULL){
        if(curr->diamond == diamondType){
            totalAmount += curr->amount;
        }
        curr = curr->next;
    }
    printf("%s Stock: %d\n", diamondName, totalAmount);

    curr = head;
    // iterate through the list to print the items of the diamondType
    while(curr != NULL){
        if(curr->diamond == diamondType){
            printf("%s: %d item (%d-%d-%d)\n", diamondName, curr->amount, curr->date % 100, (curr->date / 100) % 100, curr->date / 10000);
            // date % 100 gives the day, 
            // (date / 100) % 100 gives the month (dibagi 100 biar harinya ilang, trs di modulo 100)
            // date / 10000 gives the year
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
    // used double pointer to change the head pointer (we want to change where the head points to, so we need to pass the address of the head pointer)
    Node *curr = *head;
    Node *temp;
    // iterate through the list to delete the nodes with diamondType
    while(curr != NULL){
        if(curr->diamond == diamondType){
        // if curr's diamond is equal to diamondType, delete the node
            if(curr->prev == NULL){
                // if curr is the head node
                *head = curr->next; //change the head to curr's next
                if(curr->next != NULL){
                    // if curr's next is not null, set curr's next's prev to null
                    // because curr is the head node, so there is no previous node
                    curr->next->prev = NULL;
                    // also same as (*head)->prev = NULL; (because curr->next is the new head node)
                }
            }
            else{
                curr->prev->next = curr->next;
                // updating the next pointer of the node before the current node (curr). It's setting it to the node after curr. 
                if(curr->next != NULL){
                    // check if there is a node after curr.
                    curr->next->prev = curr->prev;
                    /* If there is a node after curr, this line updates the prev pointer of that node to point to the node before curr. 
                    This ensures that the node after curr is correctly linked to the previous node */
                }
            }
            // curr is removed from the list. Now, free the memory allocated for curr
            temp = curr;
            curr = curr->next;
            // move to the next node before freeing the memory, to continue the iteration
            free(temp);
            // this frees the memory allocated for the node that was removed
        } else {
            curr = curr->next;
            // if curr's diamond is not equal to diamondType, move to the next node
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
        // change the date to a single integer and YYYYMMDD format for easier comparison

        head = insertSorted(head, createNode(date, diamondValue(diamond), amount));
    }

    printSorted(head);

    char deleteDiamond[10];
    scanf(" %s", deleteDiamond);
    pop(&head, diamondValue(deleteDiamond));
    // use &head because we want to change the head pointer to the new head after deleting the nodes with the specified diamond type

    printSorted(head);

    return 0;
}