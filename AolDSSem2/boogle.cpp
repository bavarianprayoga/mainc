#include <stdio.h> // Standard library for input/output functions
#include <string.h> // Library for string manipulation functions
#include <stdlib.h> // Library for dynamic memory allocation functions
#include <ctype.h> // Library for character handling functions

typedef struct Trie{ // Define Trie node structure
    char chr; // Stored char in this node
    int isItWord; // 1 = valid word, 0 = invalid
    char desc[100]; // Description if it's a valid word
    struct Trie *child[26]; // Array of pointer to child nodes (one foe each letter in the alphabet)
} Trie;

Trie *root = NULL; // Declare root and set it to NULL

Trie *newNode(char chr); // Function for creating a new Trie node
void newSlang(); // Function for adding a new slang word to the Trie
void searchSlang(); // Function for searching slangs inputted beforehand
void prefixSearch(); // Function to print all the words in the Trie that starts with a given prefix
void viewAllWords(); // Function to print all words in the Trie
void printPrefixes(Trie *curr, char *prefix, int *count); // Helper function for prefixSearch
void pressEnter(); // Funcrion to prompt user to press enter to continue

int main(){ // Main function

    root = newNode('\0'); // Initialize root node of the Trie with null

    int menuSelection; //stores the users selection for the menu

    do{
        // Display the menu
        printf("===========================================\n");
        printf("1. Release a new slang word\n");
        printf("2. Search a slang word\n");
        printf("3. View all slang words starting with a certain prefix word\n");
        printf("4. View all slang words\n");
        printf("5. Exit\n");
        printf("===========================================\n");

        do{
            printf("Your choice: ");
            scanf("%d", &menuSelection); // Get user's menu selection
        } while(menuSelection < 1 || menuSelection > 5); // Validate user's selection

        switch(menuSelection){
        case 1:
            newSlang(); // Call newSlang function
            pressEnter();
            break;
        case 2:
            searchSlang();
            pressEnter();
            break;
        case 3:
            prefixSearch();
            pressEnter();
            break;
        case 4:
            viewAllWords();
            pressEnter();
            break;
        case 5:
            printf("Thank you!\n"); 
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice! Please enter a number between 1 and 5.\n\n");
            break;
        }

    } while(menuSelection != 5); // Continue displaying menu until user chooses to exit

}

Trie *newNode(char chr){
    Trie *newNode = (Trie*)malloc(sizeof(Trie));
    newNode->chr = chr;
    newNode->isItWord = 0;
    for(int i = 0; i < 26; i++){
        newNode->child[i] = NULL;
    }
    return newNode;
}

void newSlang(){
    char slang[100], desc[100];

    // Input and validate slang word
    do{
        printf("Enter a new slang word: ");
        scanf(" %[^\n]", slang);
    } while(strlen(slang) < 2 || strchr(slang, ' ') != NULL);

    // Input and validate description
    do{
        printf("Enter the description of the new word: ");
        scanf(" %[^\n]", desc);
    } while(strchr(desc, ' ') == NULL);

    // Convert slang word to lower case
    for(int i = 0; slang[i]; i++){
        slang[i] = tolower(slang[i]);
    }

    //check existence of the slang in the Trie
    Trie *curr = root;
    for(int i = 0; i < strlen(slang); i++){
        int idx = slang[i] - 'a'; // subtract by a to set the index from 0 to 26 (ex. b - a is 98 - 97 in ascii, and it will fill index 1)
        if(!curr->child[idx]){ //check if current char's child index is null based on the subtraction we did earlier. If it is, then create ndlsifoiwhgf
            curr->child[idx] = newNode(slang[i]);
        }
        curr = curr->child[idx]; // Update curr to point to the newly created child node
    }

    strcpy(curr->desc, desc); //update or set the description for the new slang.
    curr->isItWord = 1; //set the boolean to true (1) because we got a new slang.
    printf("\n");
}

void searchSlang(){
    char slang[100];
    
    // Input and validate slang word
    do{
        printf("Enter a slang word to search: ");
        scanf(" %[^\n]", slang);
    } while(strlen(slang) < 2 || strchr(slang, ' ') != NULL);

    // Convert slang word to lower case
    for(int i = 0; slang[i]; i++){
        slang[i] = tolower(slang[i]);
    }

    // Search the word in the Trie
    Trie *curr = root;
    for(int i = 0; i < strlen(slang); i++){
        int idx = slang[i] - 'a'; // subtract with a to set the index from 0 to 26 (ex. b - a is 98 - 97 in ascii, and it will fill index 1)
        if(!curr->child[idx]){ //if current's child does not exists, then the search keyword is invalid.
            printf("Slang does not exists.\n");
            printf("\n");
            return;
        }
        curr = curr->child[idx]; //if the current child exists, check the child's child. do that as many as the length of the keyword.
    }

    // If the slang exists, display it along with the description
    if(curr != NULL && curr->isItWord){
        printf("Slang found!\n");
        printf("Slang word : %s\nDescription: %s\n", slang, curr->desc);
    }
    else{
        printf("Slang does not exists.\n");
    }
    printf("\n");
}

void prefixSearch(){
    char prefix[100];

    printf("Enter a prefix word to search: ");
    scanf("%s", prefix);

    // Convert slang word to lower case
    for(int i = 0; prefix[i]; i++){
        prefix[i] = tolower(prefix[i]);
    }

    Trie *curr = root;
    for(int i = 0; i < strlen(prefix); i++){
        int idx = prefix[i] - 'a'; // subtract with a to set the index from 0 to 26 (ex. b - a is 98 - 97 in ascii, and it will fill index 1)
        if (!curr->child[idx]){ //if current's child does not exists, then the search keyword is invalid.
            printf("No words found with this prefix.\n\n");
            return;
        }
        curr = curr->child[idx]; //if the current child exists, check the child's child. do that as many as the length of the keyword.
    }

    int count = 0;
    printf("Here are the slangs that start with \"%s\":\n", prefix);
    printPrefixes(curr, prefix, &count);
    printf("\n");
} 

void viewAllWords(){
    int isEmpty = 1;
    for(int i = 0; i < 26; i++){
        if(root->child[i] != NULL){
            isEmpty = 0;
            break;
        }
    }

    if(isEmpty == 1){
        printf("No words in the dictionary.\n\n");
    }
    else{
        char prefix[100] = "";
        int count = 0;
        printf("List of all slang words in the dictionary:\n");
        printPrefixes(root, prefix, &count);
    }
    printf("\n");
}

void printPrefixes(Trie *curr, char *prefix, int *count){
    if(curr->isItWord == 1){ // If the current node marks the end of a valid word, print it.
        printf("%d. %s\n", ++(*count), prefix);
    }
    for(int i = 0; i < 26; i++){ //Iterate over each child of the current node
        if(curr->child[i] != NULL){ // Check if current node has a child corresponding to the i-th letter of the alphabet
            char newPrefix[100]; // New variable to search words with a new prefix
            strcpy(newPrefix, prefix); // Copy the content of prefix to the new one
            int len = strlen(newPrefix);
            newPrefix[len] = i + 'a'; // Append the i-th letter of the alphabet to newPrefix
            newPrefix[len + 1] = '\0'; // Add a null character at the end to mark the end of the string
            printPrefixes(curr->child[i], newPrefix, count); // Recursively call the printWords function for the child node
        }
    }
}

void pressEnter(){
    printf("Press enter to continue...");
    getchar();
    getchar();
    printf("\n");
}