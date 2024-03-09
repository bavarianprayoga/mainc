#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue[MAX];
int front = -1;
int back = -1;

void enqueue(int data){
    if(back == MAX - 1){
        printf("Queue Overflow\n");
        return;
    }
    if(front == -1){
        front = 0;
    }
    back++;
    queue[back] = data;
}

int dequeue(){
    if(front == -1 || front > back){
        printf("Queue Underflow\n");
        return -1;
    }
    int data = queue[front];
    front++;
    return data;
}

void printQueue(){
    if(front == -1 || front > back){
        printf("Queue is empty\n");
        return;
    }
    for(int i = front; i <= back; i++){
        printf("%d ", queue[i]);
    }
    puts("");
}

int main(){

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    printQueue();

    dequeue();
    dequeue();
    dequeue();

    printQueue();

    return 0;
}
