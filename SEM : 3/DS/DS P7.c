// • Aim : -Write a menu driven program to implement following operations on the singly linked list.

#include <alloc.h>
#include <conio.h>
#include <process.h>
#include <stdio.h>
void create();
void insert();
void delet();
void display();
struct node {
  int info;
  struct node *link;
};
struct node *first = NULL, *last = NULL, *next, *prev, *New;
void create() {
  New = (struct node *)malloc(sizeof(struct node));
  printf("\n enter the data:");
  scanf("%d", &New->info);
  New->link = NULL;
  first = New;
  last = New;
}
void insert() {
  int pos, c = 1;
  New = (struct node *)malloc(sizeof(struct node));
  printf("\n enter the data:");
  scanf("%d", &New->info);
  printf("\n enter the position:");
  scanf("%d", &pos);
  if ((pos == 1) && (first != NULL)) {
    New->link = first;
    first = New;
  } else {
    next = first;
    while (c < pos) {
      prev = next;
      next = prev->link;
      c++;
    }
    if (prev == NULL) {
      printf("\n invalid position");
    } else {
      New->link = prev->link;
      prev->link = New;
    }
  }
}
void delet() {
  int pos, c = 1;
  printf("\n enter the position:");
  scanf("%d", &pos);
  if (first == NULL) {
    printf("\n list is empty");
  } else if (pos == 1 && first->link == NULL) {
    printf("\n deleted element is %d", &first->info);
    free(first);
    first = NULL;
  } else if (pos == 1 && first->link != NULL) {
    New = first;
    first = first->link;
    New->link = NULL;
    printf("\n deleted element is %d", &New->link);
    free(New);
  } else {
    next = first;
    while (c < pos) {
      New = next;
      next = next->link;
      c++;
    }
    New->link = next->link;
    next->link = NULL;
    if (next == NULL) {
      printf("\n invalid position");
    } else
    {
      printf("\n deleted elememt is %d", next->info);
      free(next);
    }
  }
}
void display() {
  New = first;
  while (New != NULL)
  {
    printf("\n %d", New->info);
    New = New->link;
  }
}
void main() {
  int ch;
  clrscr();
  printf("\n singly linked list");
  while (1)
  {
    printf("\n 1. create 2. insert 3. delete 4. exit \n");
    printf("enter your choice:");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      create();
      display();
      break;
    case 2:
      insert();
      display();
      break;
    case 3:
      delet();
      display();
      break;
    case 4:
      exit(0);
    default:
      printf("invalid choice...");
    }
  }
}
