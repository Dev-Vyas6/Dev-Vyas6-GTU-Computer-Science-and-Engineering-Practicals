// • Aim : -Write a program to implement QUEUE using arrays that performs following operations(a) INSERT(b) DELETE(c) DISPLAY

#include <stdio.h>
#include <stdlib.h>
#define size 10
        void insert();
void delete ();
void Display();
int front = -1, rear = -1, queue[size];
int main() {
  int choice;
  while (1)
  {
    printf("\n*******Queue menu*******\n");
    printf("1.insert\n");
    printf("2.delete\n");
    printf("3.Display\n");
    printf("Enter choice from above menu: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      insert();
      break;
    case 2:
      delete ();
      break;
    case 3:
      Display();
      break;
    default:
      printf("Enter valid choice:");
      break;
    }
  }
}
void insert() {
  if (queue[size - 1])
  {
    printf("\nQueue is overflow");
  }
  else
  {
    front = 0;
    int v;
    printf("\nEnter value: ");
    scanf("%d", &v);
    rear++;
    queue[rear] = v;
  }
}
void delete () {
  if (front > rear)
  {
    printf("\nQueue is underflow");
  }
  else
  {
    front++;
  }
}
void Display() {
  int i;
  if (rear == -1)
  {
    printf("\nQueue is empty");
  }
  else
    for (i = front; i <= rear; i++)
    {
      printf("%d\t", queue[i]);
    }
}
