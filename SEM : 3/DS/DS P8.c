// • Aim : -Write a program to implement following operations on the doubly linked
           // list.(a)Insert a node at the front of the linked list
             //   .(b)Insert a node at the end of the linked list
              //  .(c)Delete a last node of the linked list
               // .(d)Delete a node before specified position.

#include <stdio.h>
#include <stdlib.h>
        typedef struct node {
  int data;
  struct node *prev;
  struct node *next;
} node;
node *head;
void add_last();
void add_start();
void display();
void dlt_last();
void dlt_specific();
void main() {
  int n;
  while (1) {
    printf("\n1. add_last \n2. add_start \n3. display \n4. delete_last \n5. "
           "delete_specfic \n6. exit");
    printf("\nenter your choice:");
    scanf("%d", &n);
    switch (n) {
    case 1:
      add_last();
      break;
    case 2:
      add_start();
      break;
    case 3:
      display();
      break;
    case 4:
      dlt_last();
      break;
    case 5:
      dlt_specific();
      break;
    case 6:
      exit(1);
    default:
      printf("invalid number");
    }
    getch();
  }
}
void add_last() {
  node *p, *temp;
  p = (node *)malloc(sizeof(node));
  printf("\n enter the data:");
  scanf("%d", &p->data);
  p->next = p->prev = NULL;
  temp = head;
  if (head == NULL)
    head = p;
  else {
    while (temp->next != NULL)
      temp = temp->next;
    temp->next = p;
    p->prev = temp;
  }
}
void add_start() {
  node *p, *temp;
  p = (node *)malloc(sizeof(node));
  printf("\n enter the data:");
  scanf("%d", &p->data);
  p->next = p->prev = NULL;
  if (head == NULL)
    head = p;
  else {
    head->prev = p;
    p->next = head;
    head = p;
  }
}
void display() {
  node *p;
  p = head;
  if (head == NULL)
    printf("\n no list");
  while (p != NULL) {
    printf("%d", p->data);
    p = p->next;
  }
}
void dlt_last() {
  node *p;
  p = head;
  if (head == NULL)
    printf("no node list found");
  else
  {
    while (p->next != NULL)
      p = p->next;
    p->prev->next = NULL;
    free(p);
  }
}
display();
{
  void dlt_specific()
  {
    int a;
    node *p;
    p = head;
    printf("\n enter data to delete:");
    scanf("%d", &a);
    if (head == NULL)
      printf("no node found");
    else
    {
      while (p->data != a)
        p = p->next;
      printf("%d", p->data);
      p->next->prev = p->prev;
      p->prev->next = p->next;
      free(p);
    }
    display();
  }
}
