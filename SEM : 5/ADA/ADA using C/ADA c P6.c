// AIM: Implementation of knapsack problem using dynamic programming.

#include <stdio.h>

int knapsack(int n, int wt[], int val[], int k_sack);
int max(int x, int y);
int main() {
  int k_sack, n, i;
  int wt[20], val[20];
  printf("\nEnter the no. of objects: ");
  scanf("%d", & n);
  printf("Enter the wts and profits of each object\n");
  for (i = 1; i <= n; i++) {
    scanf("%d %d", & wt[i], & val[i]);
  }
  printf("Enter the capacity of Knapsack:");
  scanf("%d", & k_sack);
  printf("\nAnswer is:%d", knapsack(n, wt, val, k_sack));
  return 0;
}
int max(int x, int y) {
  return ((x > y) ? x : y);
}
int knapsack(int n, int wt[], int val[], int k_sack) {
  int i, j, count = 0;
  int m[100][100];
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= k_sack; j++) {
      if (i == 0 || j == 0) {
        m[i][j] = 0;
      } else if (j - wt[i] < 0) {
        m[i][j] = m[i - 1][j];
      } else {
        m[i][j] = max(m[i - 1][j], m[i - 1][j - wt[i]] + val[i]);
      }
    }
  }
  printf("\nValue Table : \n");
  printf("Weight limit : ");
  for (j = 0; j <= k_sack; j++) {
    printf("%2d ", j);
  }
  printf("\n-----------------------------------------------------------------\n");
  for (i = 1; i <= n; i++) {
    if (i == 0) {
      printf(" ");
    } else {
      printf("w%d=%2d, v%d=%2d ", i, wt[i], i, val[i]);
    }
    for (j = 0; j <= k_sack; j++) {
      printf("%2d ", m[i][j]);
    }
    printf("\n");
  }
  i = n, j = k_sack;
  printf("\n\nAnswer : Total Value : %d\n", m[n][k_sack]);
  printf("\nObject_No weight value");
  printf("\n--------------------------\n");
  while (m[i][j] != m[1][0]) {
    if (m[i][j] == m[i - 1][j]) {
      i = i - 1;
      j = j;
    } else {
      count++;
      printf(" %d       %2d       %2d\n", i, wt[i], val[i]);
      i = i;
      j = j - wt[i];
    }
  }
  printf("--------------------------\n");
  printf(" %d       %2d       %2d", count, k_sack, m[n][k_sack]);
  return m[n][k_sack];
}
