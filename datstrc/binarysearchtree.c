#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct Node *insertNode(struct Node *root, int data){
    if(root == NULL){
        return newNode(data); //Checks if the subtree is empty (in this case if we reaches a leaf node, we insert the new node there.)
    }
    if(data < root->data){
        root->left = insertNode(root->left, data);
    }
    else if(data > root->data){
        root->right = insertNode(root->right, data);
    }
    return root;

    //This function will iterate through the tree until it finds the correct position to insert the new node.
}

struct Node *search(struct Node *root, int data){
    if(root == NULL || root->data == data){
        return root;
    }
    if(root->data < data){
        return search(root->right, data);
    }
    return search(root->left, data);
}

struct Node *minValueNode(struct Node *node){ //Find the minimum value node in the tree
    struct Node *current = node;
    while(current && current->left != NULL){
        current = current->left;
    }
    return current;
}

void inorder(struct Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d->", root->data);
    inorder(root->right);
}

struct Node *deleteNode(struct Node *root, int data){
    if(root == NULL){
        return root;
    }
    if(data < root->data){
        root->left = deleteNode(root->left, data);
    }
    else if(data > root->data){
        root->right = deleteNode(root->right, data);
    }
    else{
        if(root->left == NULL){ //The node has only one child (right child)
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){ //The node has only one child (left child)
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        //The node has two children
        struct Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}



int main(){

    struct Node *root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
    insertNode(root, 90);
    insertNode(root, 10);
    insertNode(root, 25);
    insertNode(root, 35);

    printf("Inorder traversal:\n");
    inorder(root);

    printf("\n\nAfter deleting 20\n");
    root = deleteNode(root, 20);
    inorder(root);


    return 0;
}