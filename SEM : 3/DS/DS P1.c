// Aim : -Write A Program To Swap Two Numbers Using Call By Value.Program :
// Write a program to swap two values using call by value.
#include <conio.h>
#include <stdio.h>
    void
    swap(int, int);
void main() {
  int a, b;
  clrscr();
  printf(“enter two numbers :\n”);
  scanf(“% d % d”, &a, &b);
  printf(“\nNumber before swaping :”);
  printf(“a = % d b = % d”, a, b);
  swap(a, b);
  getch();
}
void swap(int a, int b) {
  a = a + b;
  b = a - b;
  a = a - b;
  printf(“\nNumber after swaping :”);
  printf(“a = % d b = % d”, a, b);
}
