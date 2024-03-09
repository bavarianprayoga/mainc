// case: buat program dimana user menginputkan node dan menampilkan node
// menggunakan double linked list
#include <stdio.h>
#include <stdlib.h>

// inisiasi struct
struct node {
  int value;
  struct node *next;
  struct node *prev;
} * head, *tail;

// create double linkedlist
void doubleLL(int n) {
  int i, value;
  struct node *newNode;

  if (n >= 1) {
    head = (struct node *)malloc(sizeof(struct node));

    if (head != NULL) {
      printf("masukkan value ke 1: ");
      scanf("%d", &value);
      head->value = value;
      head->prev = NULL;
      head->next = NULL;
      tail = head; // assign head ke tail

      // Buat node dan mengelinkan menggunakan double linkedlist
      for (i = 2; i <= n; i++) {
        newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode != NULL) {
          printf("Masukkan value ke %d: ", i);
          scanf(" %d", &value);
          newNode->value = value;
          newNode->prev = tail;
          newNode->next = NULL;

          tail->next = newNode;
          tail = newNode;
        } else {
          printf("Memory allocation failed.\n");
        }
      }
    }
  }
}
// fungsi tambah node di awal
void insertHead(int value) {
  ;
  struct node *newNode;
  if (head == NULL) {
    printf("List Kosong\n");

  } else {
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = head;
    newNode->prev = NULL;
    head->prev = newNode;
    head = newNode;
  }
}
// fungsi cetak
void printList() {
  struct node *tmp;
  int n = 1;
  if (head == NULL) {
    printf("List kosong\n");
  } else {
    tmp = head;
    printf("Data dalam list: \n");

    // traverse dan trampilkan hasil
    while (tmp != NULL) {
      printf("Data ke %d: %d\n", n, tmp->value);
      n++;
      tmp = tmp->next;
    }
  }
}
// fungsi hapus head
void deleteHead() {
  struct node *delNode;
  if (head == NULL) {
    printf("Tidak bisa hapus.List kosong\n");
  } else {
    delNode = head;
    head = head->next;
    if (head != NULL) {
      head->prev = NULL;
    }
    free(delNode);
  }
}

void insertTail(int value) {
  struct node *newNode;
  if (head == NULL) {
    printf("List kosong\n");
  } else {
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
  }
}

void deleteTail() {
  struct node *delNode;
  if (head == NULL) {
    printf("List kosong\n");
  } else {
    delNode = tail;
    if (head == tail) {
      head = NULL;
      tail = NULL;
    } else {
      tail = tail->prev;
      tail->next = NULL;
    }
    free(delNode);
  }
}

// Buatlah fungsi hapus tail
// fungsi insert tail

int main(void) {
  int n;
  head = NULL;
  tail = NULL;

  printf("Masukkan jumlah node: ");
  scanf(" %d", &n);

  doubleLL(n);
  printList();
  printf("\n");

  printf("Tambahkan node di awal: ");
  scanf("%d", &n);
  insertHead(n);
  printList();

  printf("Tambahkan node di akhir:");
  scanf("%d", &n);
  insertTail(n);
  printList();


  printf("\n");
  deleteHead();
  printList();

  return 0;
}