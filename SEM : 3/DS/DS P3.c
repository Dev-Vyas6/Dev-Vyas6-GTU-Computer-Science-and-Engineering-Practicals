// • Aim : -Implement a program from stack that performs following operations Using array.(a)PUSH(B) POP(C) PEEP(D) DISPLAY(E) CHANGE.

#include <stdio.h>
#include <stdlib.h>
        void push(),
    pop(), peep(), display(), change();
int top = -1, stack[5];
int main() {
  int choice;
  while (1) {
    printf("\n---------stack menu---------\n");
    printf("1.push\n");
    printf("2.pop\n");
    printf("3.peep\n");
    printf("4.display\n");
    printf("5.change\n");
    printf("6.exit\n");
    printf("Enter your choice:");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      peep();
      break;
    case 4:
      display();
      break;
    case 5:
      change();
      break;
    defult:
      printf("\nEnter valid choice");
      break;
    }
  }
}
void push() {
  if (top <= 4) {
    int value;
    printf("\nEnter the element which you want to push:");
    scanf("%d", &value);
    top++;
    stack[top] = value;
  } else {
    printf("\nStack is overflow");
  }
}
void pop() {
  if (top == -1) {
    printf("\nStack is underflow");
  } else {
    top--;
    ;
  }
}
void peep() {
  int I;
  printf("\nEnter Ith element from top of stack:");
  scanf("%d", &I);
  if (I <= 5) {
    printf("%d", stack[top - I + 1]);
  } else {
    printf("\nEnter valid Ith element");
  }
}
void display() {
  int i;
  if (top == -1) {
    printf("\nStack is empty");
  } else {
    for (i = 0; i <= top; i++) {
      printf("\nPosition\tElement\n%d\t\t\t%d", i, stack[i]);
    }
  }
}
void change() {
  int a, b, temp, i;
  printf("\nEnter ith and jth element:");
  scanf("%d %d", &a, &b);
  printf("\nBefor swaping stack is");
  for (i = 0; i <= top; i++) {
    printf("\t%d\t", stack[i]);
  }
  temp = stack[a];
  stack[a] = stack[b];
  stack[b] = temp;
  printf("\nAfter swaping stack is");
  for (i = 0; i <= top; i++) {
    printf("\t%d\t", stack[i]);
  }
}
