#include <stdio.h>
#include <stdlib.h>

/* 
Traversal types:

1. Inorder: Left node, Root node, Right node
    inorder(root->left)
    display(root)
    inorder(root->right)

2. Postorder: Left node, Right node, Root node
    postorder(root->left)
    postorder(root->right)
    display(root)

3. Preorder: Root node, Left node, Right node
    display(root)
    preorder(root->left)
    preorder(root->right)

*/

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node *insertRight(struct Node *root, int data){
    if(root->right != NULL){
        return NULL;
    }
    root->right = newNode(data);
    return root->right;
}

struct Node *insertLeft(struct Node *root, int data){
    if(root->left != NULL){
        return NULL;
    }
    root->left = newNode(data);
    return root->left;
}

void inorder(struct Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d->", root->data);
    inorder(root->right);
}

void postorder(struct Node *root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d->", root->data);
}

void preorder(struct Node *root){
    if(root == NULL){
        return;
    }
    printf("%d->", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main(){

    struct Node *root = newNode(1);

    insertLeft(root, 2);
    insertRight(root, 3);
    insertLeft(root->left, 4);
    insertRight(root->left, 5);
    insertLeft(root->right, 6);
    insertRight(root->right, 7);
    insertLeft(root->left->left, 8);
    insertRight(root->left->left, 9);

    printf("Inorder\n");
    inorder(root);
    printf("\n");

    printf("Postorder\n");
    postorder(root);
    printf("\n");

    printf("Preorder\n");
    preorder(root);
    printf("\n");

    return 0;
}