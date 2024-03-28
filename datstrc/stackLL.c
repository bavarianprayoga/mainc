#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Stack{
    struct Node *top;
};

struct Node *NewNode(int data){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct Stack *CreateStack(){
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

int IsEmpty(struct Stack *stack){
    return stack->top == NULL;
}

int Push(struct Stack *stack, int data){
    struct Node *temp = NewNode(data);
    temp->next = stack->top;
    stack->top = temp;
    return data;
}

int Pop(struct Stack *stack){
    if(IsEmpty(stack)){
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node *temp = stack->top;
    stack->top = stack->top->next;
    int data = temp->data;
    free(temp);
    return data;
}

void printStack(struct Stack *stack){
    for(struct Node *temp = stack->top; temp != NULL; temp = temp->next){
        printf("%d ", temp->data);
    }
    puts("");
}

int main(){

    struct Stack *stack = CreateStack();

    for(int i = 0; i < 5; i++){
        printf("Pushed %d\n", Push(stack, i + 1));
    }
    puts("");

    printf("Stack: ");
    printStack(stack);

    for(int i = 0; i < 3; i++){
        printf("Popped %d\n", Pop(stack));
    }
    puts("");
    
    if(IsEmpty(stack)){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack: ");
        printStack(stack);
    }



    return 0;
}