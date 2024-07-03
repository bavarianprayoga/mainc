#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode{
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
    int height;
} TreeNode;

TreeNode *createNode(int treeKey){
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if(newNode != NULL){
        newNode->key = treeKey;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1;
    }
    return newNode;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

int getHeight(TreeNode* node){
    if(node == NULL) return 0;
    return node->height;
}

int getBalanceFactor(TreeNode* node){
    if(node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

TreeNode *rightRotate(TreeNode* y){
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

TreeNode *leftRotate(TreeNode* x){
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

TreeNode *minValueNode(TreeNode* node){
    TreeNode* current = node;
    while(current->left != NULL){
        current = current->left;
    }
    return current;
}

TreeNode *insertNode(TreeNode* node, int treeKey){
    if(node == NULL){
        TreeNode* newNode = createNode(treeKey);
        return newNode;
    }

    if(treeKey < node->key){
        node->left = insertNode(node->left, treeKey);
    }
    else if(treeKey > node->key){
        node->right = insertNode(node->right, treeKey);
    }
    else{
        return node;
    }

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    int balanceFactor = getBalanceFactor(node);

    if(balanceFactor > 1 && treeKey < node->left->key){
        return rightRotate(node);
    }

    if(balanceFactor < -1 && treeKey > node->right->key){
        return leftRotate(node);
    }

    if(balanceFactor > 1 && treeKey > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if(balanceFactor < -1 && treeKey < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

TreeNode *deleteNode(TreeNode* root, int treeKey){
    if(root == NULL){
        return root;
    }

    if(treeKey < root->key){
        root->left = deleteNode(root->left, treeKey);
    }
    else if(treeKey > root->key){
        root->right = deleteNode(root->right, treeKey);
    }
    else{
        if((root->left == NULL) || (root->right == NULL)){
            TreeNode* temp = root->left ? root->left : root->right;

            if(temp == NULL){
                temp = root;
                root = NULL;
            }
            else{
                *root = *temp;
            }
            free(temp);
        }
        else{
            TreeNode* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if(root == NULL){
        return root;
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int balanceFactor = getBalanceFactor(root);

    if(balanceFactor > 1 && getBalanceFactor(root->left) >= 0){
        return rightRotate(root);
    }

    if(balanceFactor > 1 && getBalanceFactor(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(balanceFactor < -1 && getBalanceFactor(root->right) <= 0){
        return leftRotate(root);
    }

    if(balanceFactor < -1 && getBalanceFactor(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

TreeNode *searchNode(TreeNode* root, int treeKey){
    if (root == NULL || root->key == treeKey){
        return root;
    }

    if(treeKey < root->key){
        return searchNode(root->left, treeKey);
    }

    return searchNode(root->right, treeKey);
}

int countNodes(TreeNode* root){
    if (root == NULL){
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

TreeNode *lowerBound(TreeNode* root, int treeKey){ // smallest key greater than treeKey
    TreeNode* result = NULL;
    while(root != NULL){
        if(root->key > treeKey){
            result = root;
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return result;
}

int main(){

    TreeNode *root = NULL;
    int t;

    scanf("%d", &t);

    for(int i = 0; i < t * 2; i++){
        char actionType;
        int treeKey;
        scanf("%c", &actionType);

        if(actionType == 'i' || actionType == 'I'){
            scanf("%d", &treeKey);
            root = insertNode(root, treeKey);
        }
        else if(actionType == 'd' || actionType == 'D'){
            scanf("%d", &treeKey);
            root = deleteNode(root, treeKey);
        }
        else if(actionType == 'l' || actionType == 'L'){
            scanf("%d", &treeKey);
            TreeNode* result = lowerBound(root, treeKey);
            if(result != NULL){
                printf("%d\n", result->key);
            }
            else{
                printf("-1\n");
            }
        }
        
    }

    return 0;
}