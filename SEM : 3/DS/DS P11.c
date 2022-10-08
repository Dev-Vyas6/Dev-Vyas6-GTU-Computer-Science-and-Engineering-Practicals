// • Aim : -Implement recursive and non -
  //      recursive tree traversing methods inorder,
   // preorder and post - order traversal.

#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *left;
  struct node *right;
};
struct node *root = NULL;
int count = 0;
struct node *insert(struct node *, int);
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
int main() {
  int choice, value;
  while (1) {
    printf("\n1. insert 2. inorder 3. preorder 4. postorder 5. exit");
    printf("\n enter your choice:");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("\n enter the value to be insert:");
      scanf("%d", &value);
      root = insert(root, value);
      break;
    case 2:
      inorder(root);
      break;
    case 3:
      preorder(root);
      break;
    case 4:
      postorder(root);
      break;
    case 5:
      exit(1);
    default:
      printf("\n please select correct operations");
    }
  }
}
struct node *insert(struct node *root, int value) {
  struct node *newnode;
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = value;
  if (root == NULL) {
    newnode->left = newnode->right = NULL;
    root = newnode;
    count++;
  } else {
    if (count % 2 != 0)
      root->left = insert(root->left, value);
    else
      root->right = insert(root->right, value);
  }
  return root;
}
void inorder(struct node *root)
{
  if (root != NULL)
  {
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
  }
}
void preorder(struct node *root) {
  if (root != NULL)
  {
    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}
void postorder(struct node *root) {
  if (root != NULL)
  {
    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
  }
}
