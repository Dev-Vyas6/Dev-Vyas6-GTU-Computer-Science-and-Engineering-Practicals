// • Aim : -Write a program to implement Circular Queue using arrays that performs following operations.(a)INSERT(b) DELETE(c) DISPLAY

#include <conio.h>
#include <stdio.h>
#define SIZE 4
void Insert(int);
void Delete();
void display();
int cQueue[SIZE], front = -1, rear = -1;
void main() {
  int choice, value;
  while (1)
  {
    printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("\nEnter the value to be insert: ");
      scanf("%d", &value);
      Insert(value);
      break;
    case 2:
      Delete();
      break;
    case 3:
      display();
      break;
    case 4:
      printf("\nExiting");
    }
  }
}
void Insert(int value) {
  if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
    printf("\nCircular Queue is Full! Insertion not possible!!!\n");
  else
  {
    if (rear == SIZE - 1 && front != 0)
      rear = -1;
    cQueue[++rear] = value;
    printf("\nInsertion Success!!!\n");
    if (front == -1)
      front = 0;
  }
}
void Delete() {
  if (front == -1 && rear == -1)
    printf("\nCircular Queue is Empty! Deletion is not possible!!!\n");
  else
  {
    printf("\nDeleted element : %d\n", cQueue[front++]);
    if (front == SIZE)
      front = 0;
    if (front - 1 == rear)
      front = rear = -1;
  }
}
void display() {
  if (front == -1)
    printf("\nCircular Queue is Empty!!!\n");
  else
  {
    int i = front;
    printf("\nCircular Queue Elements are : \n");
    if (front <= rear)
    {
      while (i <= rear)
        printf("%d\t", cQueue[i++]);
    }
    else
    {
      while (i <= SIZE - 1)
        printf("%d\t", cQueue[i++]);
      i = 0;
      while (i <= rear)
        printf("%d\t", cQueue[i++]);
    }
  }
}
