#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode{
    int key;
    char virtue[20];
    struct TreeNode* left;
    struct TreeNode* right;
    int height;
} TreeNode;

TreeNode *createNode(int treeKey, char virtueType[20]){
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if(newNode != NULL){
        newNode->key = treeKey;
        strcpy(newNode->virtue, virtueType);
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

TreeNode *insertNode(TreeNode* node, int treeKey, char virtueType[20], int* powerCounter, int* wisdomCounter, int* courageCounter){
    if(node == NULL){
        TreeNode* newNode = createNode(treeKey, virtueType);
        if(strcasecmp(virtueType, "Power") == 0){
            (*powerCounter)++;
        }
        else if(strcasecmp(virtueType, "Courage") == 0){
            (*courageCounter)++;
        }
        else if(strcasecmp(virtueType, "Wisdom") == 0){
            (*wisdomCounter)++;
        }
        return newNode;
    }

    if(treeKey < node->key){
        node->left = insertNode(node->left, treeKey, virtueType, powerCounter, wisdomCounter, courageCounter);
    }
    else if(treeKey > node->key){
        node->right = insertNode(node->right, treeKey, virtueType, powerCounter, wisdomCounter, courageCounter);
    }
    else{
        return node;
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

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

TreeNode *deleteNode(TreeNode* root, int treeKey, int* powerCounter, int* wisdomCounter, int* courageCounter){
    if(root == NULL){
        return root;
    }

    if(treeKey < root->key){
        root->left = deleteNode(root->left, treeKey, powerCounter, wisdomCounter, courageCounter);
    }
    else if(treeKey > root->key){
        root->right = deleteNode(root->right, treeKey, powerCounter, wisdomCounter, courageCounter);
    }
    else{
        if(strcasecmp(root->virtue, "Power") == 0){
            (*powerCounter)--;
        }
        else if(strcasecmp(root->virtue, "Courage") == 0){
            (*courageCounter)--;
        }
        else if(strcasecmp(root->virtue, "Wisdom") == 0){
            (*wisdomCounter)--;
        }

        if((root->left == NULL) || (root->right == NULL)){
            TreeNode* temp = root->left ? root->left : root->right;

            if(temp == NULL) {
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
            strcpy(root->virtue, temp->virtue);
            root->right = deleteNode(root->right, temp->key, powerCounter, wisdomCounter, courageCounter);
        }
    }

    if(root == NULL){
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

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

int main(){

    TreeNode *root = NULL;
    int powerCounter = 0;
    int courageCounter = 0;
    int wisdomCounter = 0;
    int t;

    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        int actionType;
        int treeKey;
        char virtueType[20];
        scanf("%d", &actionType);

        switch (actionType) {
            case 1:
                scanf("%d %s", &treeKey, virtueType);
                root = insertNode(root, treeKey, virtueType, &powerCounter, &wisdomCounter, &courageCounter);
                printf("%d %d %d\n", powerCounter, wisdomCounter, courageCounter);
                break;
            case 2:
                scanf("%d", &treeKey);
                root = deleteNode(root, treeKey, &powerCounter, &wisdomCounter, &courageCounter);
                printf("%d\n", countNodes(root));
                break;
            case 3:
                if (powerCounter > 0 && wisdomCounter > 0 && courageCounter > 0)
                    printf("May your courage to seek wisdom grant you power!\n");
                break;
        }
        
    }

    return 0;
}