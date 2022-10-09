// AIM: Implementation of LCS problem.

#include <stdio.h>

#include <string.h>

int i, j, m, n, c[20][20];
char x[20], y[20], b[20][20];
int main() {
  printf("Enter 1st sequence:");
  scanf("%s", x);
  printf("Enter 2nd sequence:");
  scanf("%s", y);
  Lcs();
  printf("\nThe Longest Common Subsequence is ");
  print(m, n);
  return 0;
}
int print(int i, int j) {
  if (i == 0 || j == 0) {
    return;
  }
  if (b[i][j] == 'd') {
    print(i - 1, j - 1);
    printf("%c", x[i - 1]);
  } else if (b[i][j] == 'u') {
    print(i - 1, j);
  } else {
    print(i, j - 1);
  }
}
int Lcs() {
  m = strlen(x);
  n = strlen(y);
  for (i = 0; i <= m; i++) {
    c[i][0] = 0;
  }
  for (i = 0; i <= n; i++) {
    c[0][i] = 0;
  }
  for (i = 1; i <= m; i++) {
    for (j = 1; j <= n; j++) {
      if (x[i - 1] == y[j - 1]) {
        c[i][j] = c[i - 1][j - 1] + 1;
        b[i][j] = 'd';
      } else if (c[i - 1][j] >= c[i][j - 1]) {
        c[i][j] = c[i - 1][j];
        b[i][j] = 'u';
      } else {
        c[i][j] = c[i][j - 1];
        b[i][j] = 'l';
      }
    }
  }
  printf("\n");
  for (i = 0; i <= n; i++) {
    if (i == 0) {
      printf(" Y ");
    }
    printf("%c ", y[i]);
  }
  printf("\n");
  printf("-----------------\n");
  for (i = 0; i <= m; i++) {
    for (j = 0; j <= n; j++) {
      if (j == 0) {
        if (i == 0) {
          printf("X ");
        } else {
          printf("%c ", x[i - 1]);
        }
      }
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }
}
