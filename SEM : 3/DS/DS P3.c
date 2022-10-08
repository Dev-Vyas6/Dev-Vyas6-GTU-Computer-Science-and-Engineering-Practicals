// Aim : -Introduction to Dynamic memory Allocation.DMA function like malloc(), calloc(), free() etc.
// Write a program to add two numbers using malloc() and calloc().
#include <conio.h>
#include <stdio.h>
    void main() {
  int *a, *b, *c;
  a = (int *)malloc(sizeof(int));
  b = (int *)calloc(1, sizeof(int));
  c = (int *)malloc(sizeof(int));
  printf("\nEnter First and Second Number:");
  scanf("%d%d", &*a, &*b);
  *c = *a + *b;
  printf("The Result is:");
  printf("\n %d\t\t\%d\t\t\%d", *a, *b, *c);
  free(a);
  free(b);
  free(c);
  getch();
}
