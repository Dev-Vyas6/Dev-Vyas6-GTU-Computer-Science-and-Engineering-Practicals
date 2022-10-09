// AIM: Implementation of Graph and Searching (DFS and BFS).

// 11.1 Implementation of Depth First Search.

#include<stdio.h>

void DFS(int);
int G[10][10], visited[10], n;
int main() {
  int i, j;
  printf("Enter number of vertices:");
  scanf("%d", & n);
  printf("\nEnter adjecency matrix of the graph:\n");
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      scanf("%d", & G[i][j]);
  for (i = 0; i < n; i++)
    visited[i] = 0;
  DFS(0);
}
void DFS(int i) {
  int j;
  printf("\n%d", i);
  visited[i] = 1;
  for (j = 0; j < n; j++)
    if (!visited[j] && G[i][j] == 1)
      DFS(j);
}

// 11.2 Implementation of  Breadth First Search.

#include<stdio.h>

int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;
void bfs(int v) {
  for (i = 1; i <= n; i++)
    if (a[v][i] && !visited[i])
      q[++r] = i;
  if (f <= r) {
    visited[q[f]] = 1;
    bfs(q[f++]);
  }
}
void main() {
  int v;
  printf("\nEnter the number of vertices:");
  scanf("%d", & n);
  for (i = 1; i <= n; i++) {
    q[i] = 0;
    visited[i] = 0;
  }
  printf("\nEnter adjecency matrix of graph:\n");
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      scanf("%d", & a[i][j]);
    }
  }
  printf("\nEnter the starting vertex:");
  scanf("%d", & v);
  bfs(v);
  printf("\nThe node which are reachable are:\n");
  for (i = 1; i <= n; i++) {
    if (visited[i])
      printf("%d\t", i);
    else {
      printf("\nBfs is not possible. Not all nodes are reachable");
      break;
    }
  }
}
