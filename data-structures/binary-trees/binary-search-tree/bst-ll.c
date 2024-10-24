#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

int ch, item, flag = 0;
struct node *root = NULL, *ptr = NULL, *parent = NULL, *new;

void insert() {
  printf("Enter the item to insert: ");
  scanf("%d", &item);

  if (root == NULL) {

    struct node *new = (struct node *)malloc(sizeof(struct node *));
    new->data = item;
    new->left = NULL;
    new->right = NULL;
    root = new;
  } else {
    ptr = root;
    flag = 0;
    while (ptr != NULL && flag == 0) {
      if (ptr->data == item) {
        printf("\n item exists");
        flag = 1;
        return;

      } else if (item < ptr->data) {
        parent = ptr;
        ptr = ptr->left;
      } else {
        parent = ptr;
        ptr = ptr->right;
      }
    }

    if (ptr == NULL) {
      new = (struct node *)malloc(sizeof(struct node *));
      new->data = item;
      new->left = NULL;
      new->right = NULL;

      if (item < parent->data)
        parent->left = new;
      else
        parent->right = new;
    }
  }
}

void inorder(struct node *ptr) {
  if (ptr != NULL) {
    inorder(ptr->left);
    printf("%d ", ptr->data);
    inorder(ptr->right);
  }
}

struct node *insucc(struct node *y) {
  while (y->left != NULL) {
    y = y->left;
  }
  return y;
}

void delete(int item) {

  if (root == NULL)
    printf("\nempty");

  else {
    ptr = root;
    flag = 0;
    while (ptr != NULL && flag == 0) {
      if (ptr->data == item) {

        flag = 1;
        break;
      } else if (item < ptr->data) {
        parent = ptr;
        ptr = ptr->left;
      } else {
        parent = ptr;
        ptr = ptr->right;
      }
    }

    if (flag == 0)
      printf("\n item not exists");
    else {
      if (ptr->left == NULL && ptr->right == NULL) {
        if (parent->left == ptr)
          parent->left = NULL;
        else
          parent->right = NULL;

        free(ptr);
      }

      else if (ptr->left != NULL && ptr->right == NULL) {
        if (parent->left == ptr)
          parent->left = ptr->left;
        else
          parent->right = ptr->left;
        free(ptr);
      }

      else if (ptr->left == NULL && ptr->right != NULL) {
        if (parent->left == ptr)
          parent->left = ptr->right;
        else
          parent->right = ptr->right;
        free(ptr);
      } else {
        struct node *temp = insucc(ptr->right); // Find the in-order successor
        printf("inorder successor ..%d\n", temp->data);
        int x = temp->data;
        delete (x);
        ptr->data = x;
      }
    }
  }
}
int main() {

  while (1) {
    printf("\nBinary Search Tree Operations:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    switch (ch) {
    case 1:
      insert();
      inorder(root);
      break;

    case 2:
      printf("\nEnter the item to delete: ");
      scanf("%d", &item);
      delete (item);

      inorder(root);
      break;
    }
  }
  return 0;
}
