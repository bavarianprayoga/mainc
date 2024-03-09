#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX];

int top = -1;

int push(int data){
    if(top == MAX - 1){
        printf("Stack Overflow\n");
        return -1;
    }
    top++;
    stack[top] = data;
    return 0;
}

int pop(){
    if(top == -1){
        printf("Stack Underflow\n");
        return -1;
    }
    int data = stack[top];
    top--;
    return data;
}

int main(){

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    for(int i = 0; i < 5; i++){
        printf("%d ", stack[i]);
    }
    printf("\n");

    pop();
    pop();
    pop();

    for(int i = 0; i < 2; i++){
        printf("%d ", stack[i]);
    }

    return 0;
}