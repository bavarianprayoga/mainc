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

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *newNode(int data){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node *insertNode(struct Node *root, int data){
    if(root == NULL){
        return newNode(data); //Checks if the subtree is empty (in this case if we reaches a leaf node, we insert the new node there.)
    }
    if(data < root->data){
        root->left = insertNode(root->left, data); //If the data is less than the root's data, we go to the left subtree
    }
    else if(data > root->data){
        root->right = insertNode(root->right, data); //If the data is greater than the root's data, we go to the right subtree
    }
    return root;

    //This function will iterate through the tree until it finds the correct position to insert the new node.
}

Node *search(Node *root, int data){
    if(root == NULL || root->data == data){ // if the root is NULL or the root's data is the data we're looking for, return the root
        return root;
    }
    if(root->data < data){
        return search(root->right, data);
    }
    return search(root->left, data);
}

Node *minValueNode(Node *node){ //Find the minimum value node in the tree
    Node *current = node;
    while(current && current->left != NULL){ // the minimum value node is the leftmost node in the tree
        current = current->left;
    }
    return current;
}

void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d->", root->data);
    inorder(root->right);
}

Node *deleteNode(Node *root, int data){
    if(root == NULL){ // if the tree is empty, return NULL
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
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){ //The node has only one child (left child)
            Node *temp = root->left;
            free(root);
            return temp;
        }
        //The node has two children
        Node *temp = minValueNode(root->right);
        // This line finds the node with the minimum value in the right subtree of the node to be deleted. 
        // This is done because when a node in a binary search tree is deleted, 
        // it can be replaced by either the largest node in its left subtree or the smallest node in its right subtree to maintain the binary search tree property. 
        // In this case, the code chooses to replace it with the smallest node in the right subtree.
        root->data = temp->data; // Copy the inorder successor's content to this node
        root->right = deleteNode(root->right, temp->data); // Delete the inorder successor, because it's already copied to the root
    }
    return root;
}

int height(Node *root){
    if(root == NULL){
        return -1;
    }
    else{
        int left = height(root->left);
        int right = height(root->right);

        return (left > right ? left : right) + 1;
    }
}

int totalNode(Node *root){
    if(root == NULL){
        return 0;
    }
    else{
        return 1 + totalNode(root->left) + totalNode(root->right);
    }
}

int main(){

    Node *root = NULL;
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
    printf("\n\n");
    printf("Height of the tree: %d\n", height(root));
    printf("Total number of nodes: %d\n", totalNode(root));

    printf("\nAfter deleting 20\n");
    root = deleteNode(root, 20);
    inorder(root);


    return 0;
}