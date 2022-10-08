// Aim : -Write A Program To Swap Two Numbers Using Call By refernce.
// Write a program to swap two values using call by value.
#include <conio.h>
#include <stdio.h>
        void
        swap(int *a, int *b);
void main() {
  int a, b;
  clrscr();
  printf(“enter two numbers :\n”);
  scanf(“% d % d”, &a, &b);
  printf(“\nNumber before swaping :”);
  printf(“a = % d b = % d”, a, b);
  swap(&a, &b);
  printf(“\nNumber after swaping :”);
  printf(“a = % d b = % d”, a, b);
  getch();
}
void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
