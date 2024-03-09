// user akan input node kedalam linkedlist, dan menampilkan hasil linkedlist
// yang telah diinput

#include <stdio.h>
#include <stdlib.h>


struct Node {
  int value;
  struct Node *next;
} *head;

void create(int n){
struct Node *fnNode, *tmp;
int num, i;

head = (struct Node *)malloc(sizeof(struct Node));

// check if memory was allocated successfully
if (head == NULL) {
  printf("Memory was not allocated");
} else {
  // reading data for starting node from user input
  printf("Input data for node 1: ");
  scanf("%d", &num);
  head->value = num;
  head->next = NULL; // setting next pointer to NULL
  tmp = head;
  // creating n node and adding to linkedlist
  for (i = 2; i <= n; i++) {
    fnNode = (struct Node *)malloc(sizeof(struct Node));

    // check memory
    if (fnNode == NULL) {
      printf("Memory was not allocated");
      break;
    } else {
      printf("Input data for node %d: ", i);
      scanf("%d", &num);
      fnNode ->value = num ;// setting data for fnNode
      fnNode ->next = NULL; //setting data the next pointer to NULL
      tmp->next = fnNode;
      tmp=tmp->next;
    }
  }
}
}

//fungsi insert head
void insertHead(int n){
  struct Node *fnNode;
  fnNode= (struct Node*)malloc(sizeof(struct Node));

  if(fnNode==NULL){
    printf("Memory was not allocated");
  }else{
    fnNode->value=n;
    fnNode->next = head;
    head=fnNode;
  }
}
//fungsi insert tail//code menyesuaikan
//fungsi delete head//code menyesuaikan
//fungsi delete tail//code menyesuaikan

//fungsi cetak
void printList(){
  struct Node *tmp;

  if(head==NULL){
    printf("List is empty");
  }else{
    tmp=head;

    while(tmp!=NULL){
      printf("Data = %d\n", tmp->value);
      tmp=tmp->next;
    }
  }
}

void insertTail(int n){
  struct Node *fnNode, *tmp;
  fnNode = (struct Node *)malloc(sizeof(struct Node));

  if(fnNode == NULL){
    printf("Memory was not allocated");
  }
  else{
    fnNode->value = n;
    fnNode->next = NULL;
    tmp = head;

    while(tmp->next != NULL){
      tmp = tmp->next;
    }
    tmp->next = fnNode;
  }
}

void deleteTail(){
  struct Node *delNode, *tmp;
  if(head == NULL){
    printf("List is empty");
  }
  else{
    delNode = head;
    tmp = head;

    while(delNode->next != NULL){
      tmp = delNode;
      delNode = delNode->next;
    }
    if(delNode == head){
      head = NULL;
    }
    else{
      tmp->next = NULL;
    }
    free(delNode);
  }
}

void deleteHead(){
  struct Node *delNode;
  if(head == NULL){
    printf("List is empty");
  }
  else{
    delNode = head;
    head = head->next;
    free(delNode);
  }
}

int main(void){
  int n;
  printf("Input jumlah node: ");
  scanf("%d", &n);

  create(n);

  printf("\n Data entered in the list are: \n");
  printList();

  printf("\n Insert data at the beginning of the list: ");
  scanf(" %d", &n);
  insertHead(n);

  printf("\n Data entered in the list are: \n");
  printList();

  printf("\n Insert data at the end of the list: ");
  scanf(" %d", &n);
  insertTail(n);
  //funsgi insert tail(n);//code menyesuaikan

  printf("\n Data entered in the list are: \n");
  printList();

  printf("\n Deletet data at the beginning of the list: ");
  scanf(" %d", &n);
  deleteHead();
  //funsgi delete head (n);//code menyesuaikan

  printf("\n Data entered in the list are: \n");
  printList();

  printf("\n Delete data at the end of the list: ");
  scanf(" %d", &n);
  deleteTail();
  //funsgi delete tail (n); , code menyesuaikan

  printf("\n Data entered in the list are: \n");
  printList();
  return 0;
}