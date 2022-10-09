// AIM: Implementation and Time analysis of factorial program using iterative and recursive method. 

// ➢ Iterative method

#include<stdio.h>

#include <stdlib.h>

long int fact(int n) {
  long fact = 1;
  while (n > 0) {
    fact = fact * n;
    n--;
  }
  return fact;
}
int main() {
  int num;
  long ans;
  printf("Enter a number : ");
  scanf("%d", & num);
  if (num < 0) {
    printf("No factorial for negative number\n");
  } else {
    ans = fact(num);
    printf("\nFactorial of %d is %ld\n\n", num, ans);
  }
  return 0;
}

// ➢ Recursive method 

#include <stdio.h>

#include <stdlib.h>

long int fact(int n) {
  if (n == 0) {
    return (1);
  }
  return (n * fact(n - 1));
}
int main() {
  int num;
  long ans;
  printf("Enter a number : ");
  scanf("%d", & num);
  if (num < 0) {
    printf("No factorial for negative number\n");
  } else {
    ans = fact(num);
    printf("\nFactorial of %d is %ld\n\n", num, ans);
  }
  return 0;
}
