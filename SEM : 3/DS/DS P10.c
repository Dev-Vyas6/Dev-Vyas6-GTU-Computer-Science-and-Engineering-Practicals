// • Aim : -Write a program which create binary search tree.

#include <stdio.h>
        typedef struct node {
  int info;
  struct node *left;
  struct node *right;
} node;
node *r = NULL;
node *insert(node *r, int x) {
  if (r == NULL) {
    r = (struct node *)malloc(sizeof(struct node));
    r->info = x;
    r->left = NULL;
    r->right = NULL;
  } else if (r->info > x)
    r->left = insert(r->left, x);
  else if (r->info < x)
    r->right = insert(r->right, x);
  else if (x == r->info) {
    printf("error");
    exit(0);
  }
  return r;
}
void search(node *r, int x) {
  if (r == NULL)
    printf("no element is there");
  else if (r->info == x)
    printf("element:%d", x);
  else if (r->info > x)
    search(r->left, x);
  else
    search(r->right, x);
}
int main() {
  int i, n, x, y;
  printf("enter the number of data you want to add:");
  scanf("%d", &n);
  printf("enter data:\n");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &x);
    r = insert(r, x);
  }
  printf("enter the element to search:");
  scanf("%d", &y);
  search(r, y);
}
