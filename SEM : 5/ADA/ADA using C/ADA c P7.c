// AIM: Implementation of chain matrix multiplication using Dynamic Programming. 

#include <stdio.h>
#include <time.h>

#define INF 999999999
long int m[20][20];
int s[20][20], p[20], i, j, n;
void mat_multiply();
int MatrixChainOrder(int[], int, int);
void print_optimal(int, int);
int main() {
  int k;
  printf(" Enter number of elements:");
  scanf("%d", & n);
  for (i = 1; i <= n; i++) {
    for (j = i + 1; j <= n; j++) {
      m[i][i] = 0;
      m[i][j] = INF;
      s[i][j] = 0;
    }
  }
  printf("\n Enter the dimensions: ");
  for (k = 0; k <= n; k++) {
    scanf("%d", & p[k]);
  }
  mat_multiply();
  printf("\n Multiplication Computation Table : \n");
  printf("m\t");
  for (i = 1; i <= n; i++) {
    printf(" %5d\t", i);
  }
  printf("\n");
  for (i = 1; i <= n; i++) {
    printf("%d\t", i);
    for (k = 1; k < i; k++) {
      printf("\t\t");
    }
    for (j = i; j <= n; j++) {
      printf(" %5ld ", m[i][j]);
    }
    printf("\n");
  }
  printf("\n\n S Table : \n");
  printf("s\t");
  for (i = 2; i <= n; i++) {
    printf(" %2d\t", i);
  }
  printf("\n");
  for (i = 1; i < n; i++) {
    printf("%d\t", i);
    for (k = 1; k < i; k++) {
      printf("\t");
    }
    for (j = i + 1; j <= n; j++) {
      printf(" %2d ", s[i][j]);
    }
    printf("\n");
  }
  printf("\n Number of multiplications is : %d ", MatrixChainOrder(p, 1, n));
  printf("\n\n Multiplication Sequence : ");
  print_optimal(1, n);
}
void mat_multiply() {
  long int q;
  int k;
  for (i = n; i > 0; i--) {
    for (j = i; j <= n; j++) {
      if (i == j) {
        m[i][j] = 0;
      } else {
        for (k = i; k < j; k++) {
          q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
          if (q < m[i][j]) {
            m[i][j] = q;
            s[i][j] = k;
          }
        }
      }
    }
  }
}
int MatrixChainOrder(int p[], int i, int j) {
  int k;
  int min = INF;
  int count;
  if (i == j) {
    return 0;
  }
  for (k = i; k < j; k++) {
    count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] *
      p[j];
    if (count < min) {
      min = count;
    }
  }
  return min;
}
void print_optimal(int i, int j) {
  if (i == j) {
    printf(" A%d ", i);
  } else {
    printf("(");
    print_optimal(i, s[i][j]);
    print_optimal(s[i][j] + 1, j);
    printf(")");
  }
}
