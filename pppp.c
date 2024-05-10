#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define MAX_DESCRIPTION_LENGTH 256

typedef struct TrieNode {
    struct TrieNode *sWord[ALPHABET_SIZE];
    char *description;
} TrieNode;

TrieNode *getNode(void) {
    TrieNode *newNode = (TrieNode *)malloc(sizeof(TrieNode));
    newNode->description = NULL;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        newNode->sWord[i] = NULL;
    }
    return newNode;
}

void insert(TrieNode *root, const char *key, char *description) {
    TrieNode *curr = root;
    int length = strlen(key);
    int index;

    for (int level = 0; level < length; level++) {
        index = CHAR_TO_INDEX(key[level]);
        if (!curr->sWord[index]) {
            curr->sWord[index] = getNode();
        }
        curr = curr->sWord[index];
    }

    if (curr->description) {
        free(curr->description);
        printf("Successfully updated a slang word.\n");
    } else {
        printf("Successfully released new slang word.\n");
    }
    curr->description = (char *)malloc(strlen(description) + 1);
    strcpy(curr->description, description);
}

void search(TrieNode *root, const char *key) {
    TrieNode *curr = root;
    int length = strlen(key);
    int index;

    for (int level = 0; level < length; level++) {
        index = CHAR_TO_INDEX(key[level]);
        if (!curr->sWord[index]) {
            printf("There is no word \"%s\" in the dictionary.\n", key);
            return;
        }
        curr = curr->sWord[index];
    }

    if (curr != NULL && curr->description) {
        printf("Slang word: %s\nDescription: %s\n", key, curr->description);
    } else {
        printf("There is no word \"%s\" in the dictionary.\n", key);
    }
}

void display(TrieNode *root, char str[], int level) {
    static int found = 0;  // Used to check if any word is found
    if (root->description) {
        str[level] = '\0';
        printf("%s: %s\n", str, root->description);
        found = 1;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->sWord[i]) {
            str[level] = i + 'a';
            display(root->sWord[i], str, level + 1);
        }
    }

    if (level == 0 && !found) {
        printf("There is no slang word yet in the dictionary.\n");
    }
    found = 0;  // Reset for next call
}

void displayPrefix(TrieNode *root, const char *prefix) {
    TrieNode *curr = root;
    int length = strlen(prefix);
    int index;
    char str[100];
    int level = 0;
    bool exists = false;

    for (int i = 0; i < length; i++) {
        index = CHAR_TO_INDEX(prefix[i]);
        if (!curr->sWord[index]) {
            printf("There is no prefix \"%s\" in the dictionary.\n", prefix);
            return;
        }
        curr = curr->sWord[index];
    }

    strcpy(str, prefix);
    display(curr, str, length);
}

void freeTrie(TrieNode *root) {
    if (!root) return;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->sWord[i])
            freeTrie(root->sWord[i]);
    }
    if (root->description)
        free(root->description);
    free(root);
}

int main() {
    TrieNode *root = getNode();
    char key[100], description[MAX_DESCRIPTION_LENGTH];
    char str[100];
    int choice;

    while (1) {
        printf("\n1. Release a new slang word\n");
        printf("2. Search a slang word\n");
        printf("3. View all slang words starting with a certain prefix\n");
        printf("4. View all slang words\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Input a new slang word [Must be more than 1 characters and contains no space]: ");
                scanf("%s", key);
                printf("Input a new slang word description [Must be more than 2 words]: ");
                scanf(" %[^\n]s", description);
                insert(root, key, description);
                break;
            case 2:
                printf("Input a slang word to be searched [Must be more than 1 characters and contains no space]: ");
                scanf("%s", key);
                search(root, key);
                break;
            case 3:
                printf("Input a prefix to be searched: ");
                scanf("%s", str);
                displayPrefix(root, str);
                break;
            case 4:
                printf("List of all slang words in the dictionary:\n");
                display(root, str, 0);
                break;
            case 5:
                freeTrie(root);
                printf("Thank you... Have a nice day :)\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
        printf("Press enter to continue...\n");
        while (getchar() != '\n'); // Consume newline left in input buffer
        getchar(); // Wait for user to press Enter
    }
    return 0;
}