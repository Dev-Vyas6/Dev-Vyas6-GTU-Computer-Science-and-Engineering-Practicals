// Aim : -Implement a program to convert infix notation to postfix notation using stack.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 50 char stack[size]; int top = -1;
void push(char a) {
  if (top >= size - 1)
  {
    printf("\n Stack Overflow");
  }
  else
  {
    top++;
    stack[top] = a;
  }
}
char pop() {
  if (top < 0)
  {
    printf("Stack underflow");
  }
  else
  {
    top--;
  }
  int item;
  item = stack[top];
  return (item);
}
int precedence(char item) {
  if (item == '+' || item == '-')
  {
    return (1);
  }
  else if (item == '*' || item == '/')
  {
    return (2);
  }
  else if ((item >= 65 && item <= 90) || (item >= 97 && item <= 122) ||
           (item >= 48 && item <= 57))
  {
    return (3);
  }
  else if (item == '(') {
    return (0);
  }
}
int main() {
  char infix[size];
  char item, i = 0, x;
  printf("Enter infix expression:");
  scanf("%s", infix);
  printf("The Postfix expression is:");
  push('#');
  item = infix[i];
  while (item != '\0')
  {
    if (item == '(')
    {
      push(item);
    }
    else if (item == ')')
    {
      while ((x = pop()) != '(')
      {
        printf("%c", x);
      }
    }
    else
    {
      while (precedence(stack[top]) >= precedence(item))
      {
        printf("%c", pop());
      }
      push(item);
    }
    i++;
    item = infix[i];
  }
  while (top != -1 && stack[top] != '#')
  {
    printf("%c", pop());
  }
}
