#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int key;
    int height;
    struct TreeNode *right;
    struct TreeNode *left;
} TreeNode;

TreeNode *create(int key){
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->key = key;
    newNode->height = 1;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

int getHeight(TreeNode *node){
    if(node == NULL) return 0;
    return node->height;
}

int getBalance(TreeNode *node){
    if(node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

TreeNode *rightRotate(TreeNode *y){
    TreeNode *x = y->left;
    TreeNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return x;
}

TreeNode *leftRotate(TreeNode *x){
    TreeNode *y = x->right;
    TreeNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

TreeNode *minValue(TreeNode *node){
    TreeNode *curr = node;
    while(curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

TreeNode *insert(TreeNode *node, int key){
    if(node == NULL){
        TreeNode *newNode = create(key);
        return newNode;
    }

    if(key < node->key){
        node->left = insert(node->left, key);
    }
    else if(key > node->key){
        node->right = insert(node->right, key);
    }
    else{
        return node;
    }

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    int balance = getBalance(node);

    // LL >= 0
    if(balance > 1 && key < node->left->key){
        return rightRotate(node);
    }

    // RR < 0
    if(balance < -1 && key > node->right->key){
        return leftRotate(node);
    }

    // LR <= 0
    if(balance > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL > 0
    if(balance < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

TreeNode *delete(TreeNode *node, int key){
    if(node == NULL){
        return node;
    }

    if(key < node->key){
        node->left = insert(node->left, key);
    }
    else if(key > node->key){
        node->right = insert(node->right, key);
    }
    else{
        if(node->left == NULL || node->right == NULL){
            TreeNode *temp = node->left ? node->left : node->right;
            if(temp == NULL){
                temp = node;
                node = NULL;
            }
            else{
                *node = *temp;
            }
            free(temp);
        }
        else{
            TreeNode *temp = minValue(node->right);
            node->key = temp->key;
            node->right = delete(node->right, temp->key);
        }
    }

    if(node == NULL){
        return node;
    }

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    int balance = getBalance(node);

    // LL >= 0
    if(balance > 1 && getBalance(node->left) >= 0){
        return rightRotate(node);
    }

    // RR < 0
    if(balance < -1 && getBalance(node->right) < 0){
        return leftRotate(node);
    }

    // LR <= 0
    if(balance > 1 && getBalance(node->left) <= 0){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL > 0
    if(balance < -1 && getBalance(node->right) > 0){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

TreeNode *search(TreeNode *node, int key){
    if(node == NULL || node->key == key){
        return node;
    }

    if(key < node->key){
        return search(node->left, key);
    }

    return search(node->right, key);
}

int count(TreeNode *node){
    if(node == NULL){
        return 0;
    }

    return 1 + count(node->left) + count(node->right);
}

TreeNode *lowerBound(TreeNode *node, int key){
    TreeNode *result = NULL;

    while(node != NULL){
        if(node->key > key){
            result = node;
            node = node->left;
        }
        else{
            node = node->right;
        }
    }

    return result;
}