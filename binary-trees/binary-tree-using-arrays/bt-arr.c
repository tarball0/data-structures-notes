// credit: Abdul Ali sir :)

#include <stdio.h>

int a[15], i, item, key, ch, loc = 0;

void display() {
  int i;
  for (i = 1; i <= 15; i++)

    if (a[i] != -1)
      printf("%d ", a[i]);
    else
      printf("_ ");
}

void build(int index) {
  printf("\nenter item..");
  scanf("%d", &a[index]);

  printf("\nwant to create left child for %d..if yes enter 0....", a[index]);
  scanf("%d", &ch);
  if (ch == 0)
    build(2 * index);

  printf("\nwant to create right child for %d..if yes enter 0....", a[index]);
  scanf("%d", &ch);
  if (ch == 0)
    build(2 * index + 1);
}

void search(int index) {
  if (index <= 15) {
    if (a[index] == key)
      loc = index;

    else {
      search(2 * index);
      search(2 * index + 1);
    }
  }
}

void insert() {
  printf("\nenter item to insert..");
  scanf("%d", &item);
  printf("\nwant to insert %d as left child of %d..if yes enter 0....", item,
         key);
  scanf("%d", &ch);
  if (ch == 0) {
    if (a[2 * loc] == -1)
      a[2 * loc] = item;
    else
      printf("\nleft child exists");
  } else {
    printf("\nwant to insert %d as right child of %d..if yes enter 0....", item,
           key);
    scanf("%d", &ch);
    if (ch == 0) {
      if (a[2 * loc + 1] == -1)
        a[2 * loc + 1] = item;
      else
        printf("\nright child exists");
    }
  }
}

void delete() {
  printf("\nenter key to delete");
  scanf("%d", &key);

  search(1);
  if (loc == 0)
    printf("\nkey not found at index %d....", loc);
  else
    printf("\nkey found....");

  if (a[2 * loc] == -1 && a[2 * loc + 1] == -1)
    a[loc] = -1;
  else
    printf("\nnot a leaf,deletion denied");
}
int main() {

  int i;

  for (i = 1; i <= 15; i++) {
    a[i] = -1;
  }

  display();

  build(1);

  printf("tree is....");
  display();

  printf("\nenter key to search..");
  scanf("%d", &key);

  search(1);
  if (loc == 0)
    printf("\nkey not found at index %d....", loc);
  else
    printf("\nkey found....");

  insert();
  display();

  delete ();
  display();
  return 0;
}
