# Singly Linked List Implementation in C
# Singly Linked List in C

This README provides a detailed explanation of the `singly_linked_list.c` file, which implements a singly linked list in C. The file includes definitions and implementations for various operations such as insertion, deletion, searching, and displaying elements in the list.

## Overview

A singly linked list is a data structure that consists of a sequence of elements, each containing data and a reference (or link) to the next element in the sequence. This implementation provides basic operations to manage the singly linked list.

## Structure Definition

```c
typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;
```

- `node`: A structure that defines a single element in the linked list, containing:
  - `data`: An integer to store the value of the node.
  - `next`: A pointer to the next node in the list.
- `head`: A pointer to the first node in the list, initialized to `NULL`.

## Function Prototypes

```c
node *createNode();
void searchElement();
void insertElement();
void insertFront();
void insertEnd();
void displayList();
void deleteElement();
void deleteEnd();
void deleteFront();
```

These are the prototypes for the functions used in the implementation. Each function is described in detail below.

## Main Function

```c
int main() {
    int choice = 0;

    printf("\n#### MENU ####\n");
    printf("\n1.Insert at Front");
    printf("\n2.Insert at End");
    printf("\n3.Insert after Element");
    printf("\n4.Delete from Front");
    printf("\n5.Delete from End");
    printf("\n6.Delete Element");
    printf("\n7.Search Element");
    printf("\n8.Display Elements");
    printf("\n9.Exit");

    while (choice != 9) {
        printf("\n\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertFront();
                displayList();
                break;
            case 2:
                insertEnd();
                displayList();
                break;
            case 3:
                insertElement();
                displayList();
                break;
            case 4:
                deleteFront();
                displayList();
                break;
            case 5:
                deleteEnd();
                displayList();
                break;
            case 6:
                deleteElement();
                displayList();
                break;
            case 7:
                searchElement();
                break;
            case 8:
                displayList();
                break;
            default:
                break;
        }
    }
}
```

Displays a menu to the user with options to perform different operations on the linked list. Continuously prompts the user to enter a choice until the user decides to exit by entering 9. Calls the corresponding function based on the user's choice and displays the list after each operation.

## Create Node

```c
node *createNode() {
    node *new = malloc(sizeof(node));

    if (new == NULL)
        printf("Memory is Full");

    printf("\nEnter Element to be entered: ");
    scanf("%d", &new->data);
    new->next = NULL;
    return new;
}
```

- Allocates memory for a new node.
- Prompts the user to enter data for the new node.
- Sets the next pointer to `NULL` as it’s a new node.
- Returns the pointer to the new node.

## Display List

```c
void displayList() {
    if (head == NULL)
        printf("\nList is Empty\n");
    else {
        node *temp = head;
        printf("\nElements: ");
        while (temp->next != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d \n", temp->data);
    }
}
```

- Checks if the list is empty and prints a message if it is.
- If the list is not empty, traverses the list from the head and prints each element's data.

## Insert at Front

```c
void insertFront() {
    node *ptr = createNode();
    ptr->next = head;
    head = ptr;
}
```

- Creates a new node.
- Sets the new node’s next pointer to the current head.
- Updates the head to point to the new node.

## Insert at End

```c
void insertEnd() {
    node *ptr = createNode(), *temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = ptr;
}
```

- Creates a new node.
- Traverses to the end of the list.
- Sets the next pointer of the last node to the new node.

## Insert After Element

```c
void insertElement() {
    node *ptr = createNode(), *temp = head;
    int elem, flag = 0;

    if (head == NULL)
        return;

    printf("\nEnter existing element: ");
    scanf("%d", &elem);

    while (temp->next != NULL) {
        if (temp->data == elem) {
            flag++;
            break;
        }
        temp = temp->next;
    }

    if (flag != 0 || temp->data == elem) {
        ptr->next = temp->next;
        temp->next = ptr;
    } else
        printf("\nSpecified Element is Absent\n");
}
```

- Creates a new node.
- Prompts the user to enter an existing element in the list.
- Searches for the existing element.
- If found, inserts the new node after the existing element; otherwise, prints a message that the element is absent.

## Delete from Front

```c
void deleteFront() {
    if (head != NULL) {
        node *temp = head;
        head = temp->next;
        free(temp);
    }
}
```

- Checks if the list is not empty.
- Moves the head to the next node and frees the old head.

## Delete from End

```c
void deleteEnd() {
    if (head == NULL) {
        // List is empty
    } else if (head->next == NULL) {
        node *temp = head;
        head = NULL;
        free(temp);
    } else {
        node *temp, *ptr;
        temp = head;
        ptr = temp;
        while (temp->next != NULL) {
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = NULL;
        free(temp);
    }
}
```

- Handles the edge case where the list is empty or has only one node.
- Traverses to the end of the list.
- Removes the last node and updates the second last node’s next pointer to `NULL`.

## Delete Element

```c
void deleteElement() {
    node *temp = head;
    node *ptr;
    int elem, flag = 0;

    if (head == NULL)
        return;
    else if (head->next == NULL) {
        printf("\nEnter element to be deleted: ");
        scanf("%d", &elem);

        if (head->data == elem) {
            temp = head;
            head = NULL;
            printf("\nDeleted Element: %d", temp->data);
            free(temp);
            return;
        } else
            printf("\nElement not found");
        return;
    }

    printf("\nEnter element to be deleted: ");
    scanf("%d", &elem);

    while (temp->next != NULL) {
        if (temp->data == elem) {
            flag++;
            break;
        }
        ptr = temp;
        temp = temp->next;
    }

    if (flag != 0 || temp->data == elem) {
        ptr->next = temp->next;
        printf("\nDeleted Element: %d", temp->data);
        free(temp);
    } else
        printf("\nElement not found");
}
```

- Handles the edge case where the list is empty or has only one node.
- Prompts the user to enter the element to be deleted.
- Searches for the element and deletes it if found.

## Search Element

```c
void searchElement() {
    node *temp = head;
    int elem, loc = 1, flag = 0;

    printf("\nEnter element to be searched: ");
    scanf("%d", &elem);

    while (temp->next != NULL) {
        if (temp->data == elem) {
            flag++;
            break;
        }
        temp = temp->next;
        loc++;
    }

    if (flag != 0 || temp->data == elem) {
        printf("\nElement found at location %d", loc);
    } else
        printf("\nElement not found");
}
```

- Prompts the user to enter the element to be searched.
- Searches for the element and prints its location if found.

## Conclusion

This implementation of a singly linked list in C provides a basic structure and operations to manage the list. Each function is designed to handle specific tasks such as insertion, deletion, and searching, making it a comprehensive example of linked list operations.
