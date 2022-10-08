// • Aim : -Implement following operations on circular linked list.
  //  (a)Insert a node at end of linked list,
  //  (b)Insert a node before specified position,
  //  (c)Delete a first node of linked list,
  //  (d)Delete a node after specified position.

#include <stdio.h>
#include <stdlib.h>
int insert_start(),
insert_end(), 
delete_start(), 
delete_succ(), 
display();
struct node {
  int data;
  struct node *next;
} *first = NULL, *t, *q;
int insert_start() {
  t = (struct Node *)malloc(sizeof(struct Node *));
  int num;
  printf("Enter info:");
  scanf("%d", &num);
  t->data = num;
  {
    q = first;
    while (q->next != first) {
      q = q->next;
    }
    t->next = first;
    first = t;
    q->next = first;
  }
  printf("Element inserted");
  return 0;
}
int insert_end() {
  t = (struct Node *)malloc(sizeof(struct Node *));
  int num;
  printf("Enter info:");
  scanf("%d", &num);
  t->data = num;
  t->next = first;
  {
    q = first;
    while (q->next != first) {
      q = q->next;
    }
    q->next = t;
    t->next = first;
  }
  printf("Element inserted");
  return 0;
}
int delete_start() {
  if (first == NULL) {
    printf("List is empty");
    return 0;
  } else if (first->next == first) {
    first = NULL;
  } else {
    q = first;
    t = first;
    while (q->next != first) {
      q = q->next;
    }
    first = t->next;
    q->next = first;
    free(t);
  }
  printf("Element deleted");
  return 0;
}
int delete_succ() {
  int pos, i;
  if (first == NULL) {
    printf("List is empty");
    return 0;
  }
  printf("Enter position:");
  scanf("%d", &pos);
  q = first;
  for (i = 0; i < pos - 1; i++) {
if(q->next==first 
{
      printf("There are less elements!!");
      return 0; 
}  
q=q->next;
  }
  t = q->next;
  if (t == first) {
    printf("There are less elements");
    return 0;
  }
  q->next = t->next;
  free(t);
  printf("Element deleted");
  return 0;
}
int display() {
  if (first == NULL) {
    printf("List is empty");
    return 0;
  }
  q = first;
  printf("Linked list is\n");
  printf("%d->", first->data);
  q = q->next;
  while (q->next != first) {
    printf("%d->", q->data);
    q = q->next;
  }
  return 0;
}
int main() {
  int option;
  while (1) {
    printf("\n Menu");
printf("\n 
"); 
printf("\n1.Insert at first \n2.Insert at end \n3.Delete at beginning
\n4.Delete after specified position\n5.Display\n6.Exit");
printf("\n Please Enter Any Option:-");   
scanf("%d",&option);   
switch(option)
  {
    case 1:
      insert_start();

      break;

    case 2:
      insert_end();

      break;

    case 3:
      delete_start();

      break;

    case 4:
      delete_succ();

      break;

    case 5:
      display();

      break;

    case 8:
      exit(0);

    default:
      printf("\nInvalid option"); 
}
  }

  return 0;
}
