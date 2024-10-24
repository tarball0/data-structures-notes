// credit: Abdul Ali sir :)

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *root = NULL, *new, *loc = NULL, *ploc = NULL;
int ch, key, item;

void build(struct node *ptr) {
  printf("\nenter item..");
  scanf("%d", &ptr->data);

  printf("\nwant to create left child for %d..if yes enter 0....", ptr->data);
  scanf("%d", &ch);
  if (ch == 0) {
    new = (struct node *)malloc(sizeof(struct node *));
    ptr->left = new;
    new->left = NULL;
    new->right = NULL;
    build(new);
  }

  printf("\nwant to create right child for %d..if yes enter 0....", ptr->data);
  scanf("%d", &ch);
  if (ch == 0) {
    new = (struct node *)malloc(sizeof(struct node *));
    ptr->right = new;
    new->left = NULL;
    new->right = NULL;
    build(new);
  }
}

void inorder(struct node *ptr) {
  if (ptr == NULL)
    return;
  else {
    inorder(ptr->left);
    printf("%d ", ptr->data);
    inorder(ptr->right);
  }
}

void search(struct node *par, struct node *ptr) {
  if (ptr != NULL) {
    if (ptr->data == key) {
      ploc = par;
      loc = ptr;
    } else {
      search(ptr, ptr->left);
      search(ptr, ptr->right);
    }
  }
}

void insert(struct node *ptr) {
  printf("\nenter item to insert..");
  scanf("%d", &item);
  printf("\nwant to insert %d as left child of %d..if yes enter 0....", item,
         ptr->data);
  scanf("%d", &ch);
  if (ch == 0) {
    if (ptr->left == NULL) {
      new = (struct node *)malloc(sizeof(struct node *));
      ptr->left = new;
      new->data = item;
      new->left = NULL;
      new->right = NULL;
    }

    else
      printf("\nleft child exists");
  } else {
    printf("\nwant to insert %d as right child of %d..if yes enter 0....", item,
           key);
    scanf("%d", &ch);
    if (ch == 0) {
      if (ptr->right == NULL) {
        new = (struct node *)malloc(sizeof(struct node *));
        ptr->right = new;
        new->data = item;
        new->left = NULL;
        new->right = NULL;
      }

      else
        printf("\nright child exists");
    }
  }
}

void delete() {
  printf("\nenter key to delete.");
  scanf("%d", &key);
  search(NULL, root);
  if (loc == NULL)
    printf("\nkey not found ");
  else {
    if (loc->left == NULL && loc->right == NULL) {
      if (ploc->left == loc)
        ploc->left = NULL;
      else
        ploc->right = NULL;

      free(loc);
    } else
      printf("not a leaf");
  }
}

int main() {
  root = (struct node *)malloc(sizeof(struct node *));
  root->left = NULL;
  root->right = NULL;
  build(root);
  inorder(root);
  printf("\nenter key to search..");
  scanf("%d", &key);
  search(NULL, root);
  if (loc == NULL)
    printf("\nkey not found ");
  else
    printf("\nkey found....");

  insert(loc);
  inorder(root);

  delete ();
  inorder(root);
  return 0;
}
