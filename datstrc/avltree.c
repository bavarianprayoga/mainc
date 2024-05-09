#include <stdio.h>

typedef struct Node{
    int value;
    int height;
    struct Node *left;
    struct Node *right;
}Node;

int height(Node *node){
    if(node == NULL) return -1;
    return node->height;
}
// TODO: AVLTREE

int main(){

    Node *node = NULL;


    return 0;
}